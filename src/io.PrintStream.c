#include "io.PrintStream.h"

void println(String_t* x) {
    printf("%s\n", x->toString(x));
}

PrintStream_t* PrintStream() {
    PrintStream_t *ps = (PrintStream_t*) malloc(sizeof(PrintStream_t));
    if (ps == NULL) {
        return NULL;
    }

    ps->println = println;

    return ps;
}
