// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	mode_t mode = 0;
    if (flags & O_CREAT) {
        va_list args;
        va_start(args, flags);
        mode = va_arg(args, mode_t);
        va_end(args);
    }

    long result = syscall(__NR_open, filename, flags, mode); // 2 este pentru open
    if (result < 0) {
        errno = -result;
        return -1;
    }

    return (int)result;
}
