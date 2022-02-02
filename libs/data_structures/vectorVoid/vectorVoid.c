//
// Created by Григорий on 02.02.2022.
//

#include "vectorVoid.h"
#include <stdlib.h>
#include <malloc.h>

static size_t min(size_t a, size_t b) {
    return a < b ? a : b;
}

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v;

    v.data = malloc(n * baseTypeSize);
    v.size = 0;
    v.capacity = n;
    v.baseTypeSize = baseTypeSize;

    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    v->data = realloc(v->data, newCapacity * v->baseTypeSize);
    v->size = min(v->size, newCapacity);
    v->capacity = newCapacity;

    if (v->data == NULL && v->capacity != 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}