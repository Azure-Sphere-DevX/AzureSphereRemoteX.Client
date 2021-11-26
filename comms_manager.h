#pragma once

#include "contract.h"
#include <arpa/inet.h> //inet_addr
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <time.h>

#include <assert.h>

#define BEGIN_API(context, name, arguments, ...) \
    name(arguments, ##__VA_ARGS__)               \
    {                                            \
        name##_t context;                        \
        memset(&context, 0x00, sizeof(name##_t));

#define TYPE_SIZE(name) sizeof(name##_t)
// #define DATA_BLOCK_TOTAL_SIZE(name) sizeof(((name##_t *)0)->data_block)
#define DATA_BLOCK_DATA_SIZE(name) sizeof(((name##_t *)0)->data_block.data)
#define CORE_BLOCK_SIZE(name) (int)(sizeof(name##_t) - sizeof(((name##_t *)0)->data_block))
#define VARIABLE_BLOCK_SIZE(name, length) (int)(sizeof(name##_t) - sizeof(((name##_t *)0)->data_block.data) + length)

#define END_API(name)         \
    errno = ctx_block.err_no; \
    return ctx_block.returns; \
    }

#define CTX_BLOCK(TYPE) \
    TYPE ctx_block;     \
    memset(&ctx_block, 0x00, sizeof(TYPE))

#define SEND_MSG(command, request_length, response_length, response_required)                                          \
    ssize_t bytes_returned = socket_send_msg(&ctx_block, command, request_length, response_length, response_required); \
    if (bytes_returned < 0)                                                                                            \
    {                                                                                                                  \
        return bytes_returned;                                                                                         \
    }                                                                                                                  \
    assert(bytes_returned == response_length);

#define SEND_MSG_WITH_DEFAULTS(name, response_required)                                                                    \
    ssize_t bytes_returned = socket_send_msg(&ctx_block, name##_c, sizeof(name##_t), sizeof(name##_t), response_required); \
    if (bytes_returned < 0)                                                                                                \
    {                                                                                                                      \
        return bytes_returned;                                                                                             \
    }                                                                                                                      \
    assert(bytes_returned == sizeof(name##_t));

bool create_socket(void);
ssize_t socket_send_msg(void *msg, uint8_t command, size_t request_length, size_t response_length, bool respond);