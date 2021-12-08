#pragma once

#include "comms_manager.h"
#include "contract.h"
#include <errno.h>
#include <stdint.h>
#include <stddef.h>

int RemoteX_PlatformInformation(char *buffer, size_t buffer_length);

#ifdef DARWIN
int close(int fd);
off_t lseek(int fd, off_t offset, int whence);
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count);
#else
int __wrap_close(int fd);
off_t __wrap_lseek(int fd, off_t offset, int whence);
ssize_t __wrap_read(int fd, void *buf, size_t count);
ssize_t __wrap_write(int fd, const void *buf, size_t count);
#endif