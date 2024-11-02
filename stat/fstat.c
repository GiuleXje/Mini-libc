// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	if (!st) {
		errno = EINVAL;
		return -1;
	}

	long res = syscall(__NR_fstat, fd, st);
	if (res < 0) {
		errno = -res;
		return -1;
	}
	return 0;
}
