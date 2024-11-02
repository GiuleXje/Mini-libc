#ifndef TIME_H
#define TIME_H

#include "../include/internal/arch/x86_64/syscall_arch.h"

typedef unsigned int time_t;

typedef struct timespec timespec;

struct timespec {
    time_t tv_sec; //secunde
    long tv_nsec; //nanosecunde
};

int nanosleep(const struct timespec *requested_time, struct timespec *remaining);
unsigned int sleep(unsigned int seconds);

#endif //TIME_H
