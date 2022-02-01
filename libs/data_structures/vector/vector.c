//
// Created by Григорий on 01.02.2022.
//

#include "vector.h"
#include <malloc.h>
#include <stdlib.h>

static size_t min(size_t a, size_t b) {
    return a < b ? a : b;
}

vector createVector(size_t n) {
    vector v;

    v.data = (int *)malloc(n * sizeof(int));
    v.capacity = n;

    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}

void reserve(vector *v, size_t newCapacity) {
    v->data = (int *)realloc(v->data, newCapacity * sizeof(int));
    v->size = min(v->size, newCapacity);
    v->capacity = newCapacity;

    if (v->data == NULL && v->capacity != 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}