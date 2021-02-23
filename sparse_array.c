#include "sparse_array.h"

static BOOL put(SparseArray *self, size_t key, size_t value);
static BOOL get(SparseArray *self, size_t key, size_t *value);
static void clear(SparseArray *self);
static void delete(SparseArray **self);

SparseArray *newSparseArray(uint32_t initialCapacity) {
    SparseArray *array = (SparseArray *)malloc(sizeof(SparseArray));
    if(array != NULL) {
        array->position = 0;
        array->capacity = initialCapacity;

        array->keys = (size_t *)malloc(sizeof(size_t) * initialCapacity);
        array->values = (size_t *)malloc(sizeof(size_t) * initialCapacity);
        array->put = put;
        array->get = get;
        array->clear = clear;
        array->delete = delete;
    }
    return array;
}

static BOOL put(SparseArray *self, size_t key, size_t value) {
    if(self->position > (self->capacity - 1)) {
        return FALSE;
    }
    *(self->keys + self->position) = key;
    *(self->values + self->position) = value;
    self->position++;
    return TRUE;
}

static BOOL get(SparseArray *self, size_t key, size_t *value) {
    for(uint32_t i = 0; i < self->position; i++) {
        if(*(self->keys + i) == key) {
            *value = *(self->values + i);
            return TRUE;
        }
    }
    return FALSE;
}

static void clear(SparseArray *self) {
	self->position = 0;
}

static void delete(SparseArray **self) {
    SparseArray *array = *self;
    if(array != NULL) {
        free(array->keys);
        free(array->values);
        free(array);
        *self = NULL;
    }
}
