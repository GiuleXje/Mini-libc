// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
    if (!path || !buf) {
		errno = EINVAL;
		return -1;
	}

	long res = syscall(__NR_stat, path, buf);
	if (res < 0) {
		errno = -res;
		return -1;
	}
	return 0;
}
