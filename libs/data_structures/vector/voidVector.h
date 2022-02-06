#ifndef VECTORLAB_VOIDVECTOR_H
#define VECTORLAB_VOIDVECTOR_H


#include <limits.h>

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;


#endif //VECTORLAB_VOIDVECTOR_H
