#include "../include/stdio.h"
#include "../include/internal/io.h"

int puts(const char *s) {
    while (*s) {
        if (write(1, s, 1) != 1) {
            return -1;// EOF
        }
        s++;
    }
    if (write(1, "\n", 1) != 1) {
        return -1;// EOF
    }

    return 1;// done
}
