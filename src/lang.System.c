#include "lang.System.h"
#include "io.PrintStream.h"

System_t* System() {
    System_t *s = (System_t*) malloc(sizeof(System_t));
    if (s == NULL) {
        return NULL;
    }

    s->out = PrintStream();

    return s;
}