#include "comms_manager.h"

static bool initialized = false;
static int sock_fd;
static uint8_t receive_buffer[5 * 1024];

bool create_socket(void)
{
    struct sockaddr_in server;
    int retry_count = 0;
    int connect_status = -1;

    if (initialized)
    {
        return true;
    }

#ifndef AZURE_SPHERE_REMOTEX_IP
    printf("No AZURE_SPHERE_REMOTEX_IP variable defined in root cmakelists.txt\n");
    printf("Add the following to cmakelists.txt\n");
    printf("add_compile_definitions(AZURE_SPHERE_REMOTEX_IP = \"xxx.xxx.xxx.xxx\"\n");

    initialized = true;

    return false;
#endif

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd == -1)
    {
        printf("Could not create a socket for an Azure Sphere RemoteX connection\n");
    }

#ifdef AZURE_SPHERE_REMOTEX_IP
    server.sin_addr.s_addr = inet_addr(AZURE_SPHERE_REMOTEX_IP);
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
#endif

    while (retry_count < 10)
    {
        printf("Attempting connection to Azure Sphere RemoteX...\n");
        if ((connect_status = connect(sock_fd, (struct sockaddr *)&server, sizeof(server))) < 0)
        {
            printf("Connection to Azure Sphere RemoteX failed\n");
            printf("Retrying in 5 seconds\n");
            nanosleep(&(struct timespec){5, 0}, NULL);
            retry_count++;
        }
        else
        {
            break;
        }
    }

    if (connect_status < 0)
    {
        printf("Connection to Azure Sphere RemoteX failed\n");
        return false;
    }

    struct timeval tv;
    tv.tv_sec = 360;
    tv.tv_usec = 0;
    setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof tv);

    initialized = true;

    puts("Connected to Azure Sphere RemoteX\n");

    return true;
}

ssize_t socket_send_msg(void *msg, uint8_t command, size_t request_length, size_t response_length, bool respond)
{
    size_t bytes_received = 0;

    create_socket();

    CTX_HEADER *header = (CTX_HEADER *)msg;

    header->block_length = (uint16_t)request_length;
    header->cmd = command;

    header->response_length = response_length;

#ifdef AZURE_SPHERE_REMOTEX_PERFORMANCE_MODE
    header->respond = respond;
#else
    header->respond = true;
#endif

    if (send(sock_fd, msg, request_length, 0) != request_length)
    {
        // puts("Send to Azure Sphere RemoteX failed\n");
        return -1;
    }

    if (!header->respond)
    {
        return response_length;
    }

    while (bytes_received < response_length)
    {
        ssize_t byte_count = recv(sock_fd, receive_buffer + bytes_received, response_length - bytes_received, 0);
        if (byte_count > 0)
        {
            bytes_received += byte_count;
        }
        else if (byte_count < 0)
        {
            break;
        }
    }

    if (bytes_received <= response_length)
    {
        memcpy(msg, receive_buffer, bytes_received);
    }

    return bytes_received;
}