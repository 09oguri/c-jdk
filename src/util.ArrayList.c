#include "util.ArrayList.h"

void add(ArrayList_t* self, int32_t index, void* e) {
    if (index > size || index < 0) {
        return;
    }
    self->_value[index] = e;
}

void del(ArrayList_t* self) {
    free(self->_value);
    self->_size = 0;
    free(self);
}

void* get(ArrayList_t* self, int32_t index) {
    if (index >= self->size(self) || index < 0) {
        return NULL;
    }
    return self->_value[index];
}

int32_t size(ArrayList_t* self) {
    return self->_size;
}

ArrayList_t* ArrayList(int32_t initialCapacity) {
    ArrayList_t *list = (ArrayList_t*) malloc(sizeof(ArrayList_t));
    if (list == NULL) {
        return NULL;
    }

    list->_size = (initialCapacity > 0) ? initialCapacity : DEFAULT_CAPACITY;
    list->_value = (void**) malloc(list->_size);

    list->add = add;
    list->del = del;
    list->get = get;
    list->size = size;

    return list;
}
