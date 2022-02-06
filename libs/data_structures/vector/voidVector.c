#include "voidVector.h"

void badAlloc(const int *a) {
    if (a == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}

vectorVoid createVectorV(const size_t n, size_t baseTypeSize) {
    int *a = (int *) malloc(sizeof(int) * n);
    badAlloc(a);
    return (vectorVoid) {a, 0, sizeof(baseTypeSize)};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity) {
        v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
        badAlloc(v->data);
        v->capacity = newCapacity;
        if (newCapacity < v->size)
            v->size = newCapacity;
    } else
        deleteVectorV(v);
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->capacity = 0;
    v->size = 0;
}

