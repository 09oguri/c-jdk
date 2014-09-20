#ifndef SYSTEM_H
#define SYSTEM_H

#include "io.PrintStream.h"

typedef struct System_t {
    struct PrintStream_t out;

    int32_t (*exit)(int32_t);
} System_t;

int32_t lang_system_exit(int32_t status);

System_t System = {(PrintStream_t) {println}, lang_system_exit};

#endif
