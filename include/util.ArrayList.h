#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_CAPACITY 10

typedef struct ArrayList_t {
    void **_value;
    int32_t _size;

    void (*add)(struct ArrayList_t*, int32_t, void*);
    void (*del)(struct ArrayList_t*);
    void* (*get)(struct ArrayList_t*, int32_t);
    int32_t (*size)(struct ArrayList_t*);
} ArrayList_t;

void add(ArrayList_t* self, int32_t index, void* e);
void util_arraylist_del(ArrayList_t* self);
void* get(ArrayList_t* self, int32_t index);
int32_t size(ArrayList_t* self);
//ArrayList_t* ArrayList(int32_t initialCapacity);
ArrayList_t ArrayList(int32_t initialCapacity);

#endif
