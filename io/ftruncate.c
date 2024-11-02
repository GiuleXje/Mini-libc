// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	long res = syscall(__NR_ftruncate, fd, length);
	if (res < 0) {
		errno = -res;
		return -1;
	}
	return (int)res;
}
