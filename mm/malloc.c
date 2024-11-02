// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include "../include/errno.h"
#include "../include/internal/syscall.h"

void *malloc(size_t size)
{
    if (!size)
        return NULL;

    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        errno = ENOMEM;
        return NULL;
    }

    if (mem_list_add(ptr, size) != 0) {
        munmap(ptr, size);
		errno = ENOMEM;
        return NULL;
    }

    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
	void *start = malloc(total_size);
	if (start) {
		memset(start, 0, total_size);
	}
	return start;
}

void free(void *ptr)
{
    if (!ptr)
        return;

    struct mem_list *block = mem_list_find(ptr);
	munmap(block->start, block->len);
    mem_list_del(block->start);
}

void *realloc(void *ptr, size_t size)
{
	if (!ptr)
        return malloc(size);

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    struct mem_list *block = mem_list_find(ptr);
    if (!block)
        return NULL;

    if (size <= block->len) {
        return ptr;
    }

    void *new_ptr = malloc(size);
    if (!new_ptr)
        return NULL;
    memcpy(new_ptr, ptr, block->len);
    free(ptr);

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
    return realloc(ptr, total_size);
}
