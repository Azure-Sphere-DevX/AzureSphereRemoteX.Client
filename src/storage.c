#include "../applibs/storage.h"

#include "../contract.h"
#include "../comms_manager.h"
#include <errno.h>

int BEGIN_API(ctx_block, Storage_OpenMutableFile, void)
{
    SEND_MSG_WITH_DEFAULTS(Storage_OpenMutableFile, true);
}
END_API(Storage_OpenMutableFile)

int BEGIN_API(ctx_block, Storage_DeleteMutableFile, void)
{
    SEND_MSG_WITH_DEFAULTS(Storage_DeleteMutableFile, true);
}
END_API(Storage_DeleteMutableFile)

int BEGIN_API(ctx_block, Storage_Write, int fd, uint8_t *writeData, size_t lenWriteData)
{
    if (lenWriteData > DATA_BLOCK_DATA_SIZE(Storage_Write))
    {
        return -1;
    }

    ctx_block.fd = fd;
    ctx_block.length = lenWriteData;
    memcpy(ctx_block.data_block.data, writeData, lenWriteData);

    SEND_MSG(Storage_Write_c,
             VARIABLE_BLOCK_SIZE(Storage_Write, lenWriteData),
             CORE_BLOCK_SIZE(Storage_Write),
             false);

    ctx_block.returns = ctx_block.header.respond ? ctx_block.returns : lenWriteData;
}
END_API(Storage_Write)

int BEGIN_API(ctx_block, Storage_Read, int fd, uint8_t *readData, size_t lenReadData)
{
    if (lenReadData > DATA_BLOCK_DATA_SIZE(Storage_Read))
    {
        return -1;
    }

    ctx_block.fd = fd;
    ctx_block.length = lenReadData;

    SEND_MSG(Storage_Read_c,
             CORE_BLOCK_SIZE(Storage_Read),
             VARIABLE_BLOCK_SIZE(Storage_Read, lenReadData),
             true);

    memcpy(readData, ctx_block.data_block.data, ctx_block.length);
}
END_API(Storage_Read)

int64_t BEGIN_API(ctx_block, Storage_Lseek, int fd, uint64_t offset, int whence)
{
    ctx_block.fd = fd;
    ctx_block.offset = offset;
    ctx_block.whence = whence;

    SEND_MSG_WITH_DEFAULTS(Storage_Lseek, false);
}
END_API(Storage_Lseek)