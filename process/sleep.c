#include "../include/time.h"
#include "../include/errno.h"
#include "../include/internal/arch/x86_64/syscall_list.h"
#include "../include/internal/syscall.h"

int nanosleep(const struct timespec *requested_time, struct timespec *remaining) {
    if (!requested_time) {
        errno = EINVAL;
        return -1;
    }

    long res = syscall(__NR_nanosleep, requested_time, remaining);
    return res == -1 ? -1 : 0;
}

unsigned int sleep(unsigned int seconds) {
    if (!seconds)
        return 0;

    timespec req = {seconds, 0};
    timespec rem;

    while (nanosleep(&req, &rem) == -1 && errno == EINTR)
        req = rem;

    return rem.tv_sec;
}
