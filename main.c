#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"


void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 42);
    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data[0] == 42);
}


void test_pushBack_fullVector() {
    vector v = createVector(1);
    pushBack(&v, 24);
    pushBack(&v, 42);
    assert(v.capacity == 2);
    assert(v.size == 2);
    assert(v.data[0] == 24);
    assert(v.data[1] == 42);
}


void test_pushBack_fullVector2() {
    vector v = createVector(2);
    pushBack(&v, 22);
    pushBack(&v, 24);
    pushBack(&v, 42);
    assert(v.size == 3);
    assert(v.capacity == 4);
    assert(v.data[0] == 22);
    assert(v.data[1] == 24);
    assert(v.data[2] == 42);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);

}

void test_atVector_notEmptyVector() {
    vector v = createVector(2);
    pushBack(&v, 24);
    pushBack(&v, 42);
    int *a = atVector(&v, 1);
    assert(*a == 42);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(3);
    pushBack(&v, 24);
    pushBack(&v, 42);
    pushBack(&v, 88);
    int *a = atVector(&v, 2);
    assert(*a == 88);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 24);
    int *a = back(&v);
    assert(*a == 24);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 24);
    int *a = front(&v);
    assert(*a == 24);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_pushBack_fullVector2();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();
    return 0;
}