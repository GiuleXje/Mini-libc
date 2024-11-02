// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *start = destination;

	while (*source) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';

	return start;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *start = destination;
	while (len--) {
		*destination = *source;
		destination++;
		source++;
	}
	return start;
}

char *strcat(char *destination, const char *source)
{
	char *start = destination;
	while (*destination)
		destination++;

	while (*source) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return start;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *start = destination;
	while (*destination)
		destination++;

	while (len-- && *source) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return start;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2) {
		if (*str1 > *str2)
			return 1;
		if (*str1 < *str2)
			return -1;
		str1++;
		str2++;
	}
	if (*str1 && !(*str2))
		return 1;
	if (*str2 && !(*str1))
		return -1;
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while (len-- && *str1 && *str2) {
		if (*str1 > *str2)
			return 1;
		if (*str1 < *str2)
			return -1;
		str1++;
		str2++;
	}
	if ((int)len != -1) {
		if (*str1 && !(*str2))
			return 1;
		if (*str2 && !(*str1))
			return -1;
		return 0;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	const char *aux = str;
	while (*aux) {
		if ((int)*aux == c)
			return (char *)aux;
		aux++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *last_app = NULL;
	while (*str) {
		if ((int)*str == c)
			last_app = (char *)str;
		str++;
	}
	return last_app;
}

char *strstr(const char *haystack, const char *needle)
{
	if (!needle || !haystack)
		return (char *)haystack;
	int size = 0;
	char *copy = (char *)needle;
	while (*(copy++))
		size++;
	while (*haystack) {
		if (strncmp(haystack, needle, size) == 0)
			return (char *)haystack;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	if (!needle || !haystack)
		return (char *)haystack;

	char *prev_app = NULL;
	int size = 0;
	char *copy = (char *)needle;
	while (*(copy++))
		size++;

	while (*haystack) {
		if (strncmp(haystack, needle, size) == 0)
			prev_app = (char *)haystack;
		haystack++;
	}
	return prev_app;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	if (!num || !source)
		return NULL;

	void *start = destination;
	while (num--) {
		*(char *)destination = *(char *)source;
		source++;
		destination++;
	}

	return start;
}

void *memmove(void *destination, const void *source, size_t num)
{
	if (!destination || !source) {
        return NULL;
    }

    unsigned char *dst = (unsigned char *)destination;
    unsigned char *src = (unsigned char *)source;

    if (src < dst && src + num > dst) {
		src += num;
		dst += num;
		while (num--) {
			*(--dst) = *(--src);
		}
	} else {
		while (num--) {
			*(dst++) = *(src++);
		}
	}

    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const char *a = (const char *)ptr1;
	const char *b = (const char *)ptr2;

	while (num--) {
		if (*a > *b)
			return 1;
		if (*a < *b)
			return -1;
		a++;
		b++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	unsigned char *src = (unsigned char *)source;
	while (num--) {
		*src = (unsigned char)value;
		src++;
	}
	return source;
}
