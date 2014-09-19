#ifndef PRINT_STREAM_H
#define PRINT_STREAM_H

#include "lang.String.h"

typedef struct PrintStream_t {
    void (*println)(struct String_t*);
} PrintStream_t;

void println(String_t* x);
PrintStream_t* PrintStream();

#endif
