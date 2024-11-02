// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	long result = syscall(3, fd); //3 este pentru close
    if (result < 0) {
        errno = -result;
        return -1;
    }
    return 0;
}
