// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>
#include "../include/internal/arch/x86_64/syscall_list.h"

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	long res = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

	if (res < 0) {
		errno = -res;
		return MAP_FAILED;
	}
	return (void *)res;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	long res = syscall(__NR_mremap, old_address, old_size, new_size, flags);

	if (res < 0) {
		errno = -res;
		return MAP_FAILED;
	}
	return (void *)res;
}

int munmap(void *addr, size_t length)
{
	long res = syscall(__NR_munmap, addr, length);

	if (res < 0) {
		errno = -res;
		return -1;
	}

	return 0;
}
