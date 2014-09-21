#include "util.ArrayList.h"

void add(ArrayList_t* self, int32_t index, String_t e) {
    if (index > self->size(self) || index < 0) {
        return;
    }
    self->_value[index] = e;
    self->_size++;
}

void util_arraylist_del(ArrayList_t* self) {
    free(self->_value);
    self->_size = 0;
}

String_t get(ArrayList_t* self, int32_t index) {
    if (index >= self->size(self) || index < 0) {
        return String("");
    }
    return self->_value[index];
}

int32_t size(ArrayList_t* self) {
    return self->_size;
}

ArrayList_t ArrayList(int32_t initialCapacity) {
    int32_t ic = (initialCapacity > 0) ? initialCapacity : DEFAULT_CAPACITY;
    return (ArrayList_t) {(String_t*) malloc(sizeof(String_t) * ic), 0, add, util_arraylist_del, get, size};
}
