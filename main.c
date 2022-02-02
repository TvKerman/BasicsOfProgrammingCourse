#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>

bool isEqualVector(const vector *v1, const vector *v2) {
    if (v1->size != v2->size) {
        return false;
    }

    for (size_t i = 0; i < v1->size; i++) {
        if (v1->data[i] != v2->data[i]) {
            return false;
        }
    }

    return true;
}

void test_pushBack_emptyVector() {
    vector vector1 = createVector(0);
    pushBack(&vector1, 5);
    vector resultVector = createVector(1);
    resultVector.data[0] = 5;
    resultVector.size = 1;
    assert(isEqualVector(&vector1, &resultVector));
    deleteVector(&vector1);
    deleteVector(&resultVector);
}

void test_pushBack_fullVector() {
    vector vector1 = createVector(4);
    pushBack(&vector1, 5);
    pushBack(&vector1, 3);
    pushBack(&vector1, 2);
    pushBack(&vector1, 7);
    pushBack(&vector1, 1);

    vector resultVector = createVector(8);
    resultVector.data[0] = 5;
    resultVector.data[1] = 3;
    resultVector.data[2] = 2;
    resultVector.data[3] = 7;
    resultVector.data[4] = 1;
    resultVector.size = 5;
    assert(isEqualVector(&vector1, &resultVector));
    deleteVector(&vector1);
    deleteVector(&resultVector);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 5);
    pushBack(&v, 7);

    assert(atVector(&v, 2) == &v.data[2]);
    assert(atVector(&v, 0) == &v.data[0]);
    assert(atVector(&v, 1) == &v.data[1]);

    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(atVector(&v, 0) == &v.data[0]);
    pushBack(&v, 5);
    assert(atVector(&v, 1) == &v.data[1]);
    pushBack(&v, 7);
    assert(atVector(&v, 2) == &v.data[2]);
    pushBack(&v, 9);
    assert(atVector(&v, 3) == &v.data[3]);

    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 5);

    assert(back(&v) == &v.data[0]);

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 7);

    assert(front(&v) == &v.data[0]);

    deleteVector(&v);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
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
