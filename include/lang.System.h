#ifndef SYSTEM_H
#define SYSTEM_H

#include "io.PrintStream.h"

typedef struct System_t {
    struct PrintStream_t *out;
} System_t;

System_t* System();

#endif
