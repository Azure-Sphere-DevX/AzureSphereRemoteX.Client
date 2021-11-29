#include "applibs/remotex.h"

int BEGIN_API(ctx_block, RemoteX_PlatformInformation, char *buffer, size_t buffer_length)
{
    ctx_block.length = buffer_length;

    SEND_MSG(RemoteX_PlatformInformation,
             CORE_BLOCK_SIZE(RemoteX_PlatformInformation),
             VARIABLE_BLOCK_SIZE(RemoteX_PlatformInformation, buffer_length),
             true);

    memset(buffer, 0x00, buffer_length);
    memcpy(buffer, ctx_block.data_block.data, ctx_block.returns);
}
END_API(GPIO_OpenAsOutput)

int BEGIN_API(ctx_block, RemoteX_Write, int fd, uint8_t *writeData, size_t lenWriteData)
{
    if (lenWriteData > DATA_BLOCK_DATA_SIZE(RemoteX_Write))
    {
        return -1;
    }

    ctx_block.fd = fd;
    ctx_block.length = lenWriteData;
    memcpy(ctx_block.data_block.data, writeData, lenWriteData);

    SEND_MSG(RemoteX_Write,
             VARIABLE_BLOCK_SIZE(RemoteX_Write, lenWriteData),
             CORE_BLOCK_SIZE(RemoteX_Write),
             false);

    ctx_block.returns = ctx_block.header.respond ? ctx_block.returns : lenWriteData;
}
END_API(Storage_Write)

int BEGIN_API(ctx_block, RemoteX_Read, int fd, uint8_t *readData, size_t lenReadData)
{
    if (lenReadData > DATA_BLOCK_DATA_SIZE(RemoteX_Read))
    {
        return -1;
    }

    ctx_block.fd = fd;
    ctx_block.length = lenReadData;

    SEND_MSG(RemoteX_Read,
             CORE_BLOCK_SIZE(RemoteX_Read),
             VARIABLE_BLOCK_SIZE(RemoteX_Read, lenReadData),
             true);

    memcpy(readData, ctx_block.data_block.data, ctx_block.length);
}
END_API(RemoteX_Read)

int64_t BEGIN_API(ctx_block, RemoteX_Lseek, int fd, uint64_t offset, int whence)
{
    ctx_block.fd = fd;
    ctx_block.offset = offset;
    ctx_block.whence = whence;

    SEND_MSG_WITH_DEFAULTS(RemoteX_Lseek, false);
}
END_API(Storage_Lseek)