#pragma once

#include "comms_manager.h"
#include "contract.h"
#include <errno.h>
#include <stdint.h>
#include <stddef.h>

int RemoteX_PlatformInformation(char *buffer, size_t buffer_length);
int RemoteX_Read(int fd, uint8_t *readData, size_t lenReadData);
int RemoteX_Write(int fd, uint8_t *writeData, size_t lenWriteData);
int64_t RemoteX_Lseek(int fd, uint64_t offset, int whence);