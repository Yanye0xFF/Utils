#ifndef SPARSE_ARRAY_H_INCLUDED
#define SPARSE_ARRAY_H_INCLUDED

#include "stdint.h"
#include "stdlib.h"
#include "string.h"

#define BOOL unsigned char
#define TRUE    1
#define FALSE    0
#undef NULL
#define NULL (void *)0


struct _sparse_array;
typedef struct _sparse_array    SparseArray;

struct _sparse_array{
    size_t *keys;
    size_t *values;
    uint32_t position;
    uint32_t capacity;
    BOOL (*put)(SparseArray *self, size_t key, size_t value);
    BOOL (*get)(SparseArray *self, size_t key, size_t *value);
    void (*clear)(SparseArray *self);
    void (*delete)(SparseArray **self);
};

SparseArray *newSparseArray(uint32_t initialCapacity);


#endif // SPARSE_ARRAY_H_INCLUDED
