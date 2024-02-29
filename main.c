// 25.02.2024 20:55
#include "library/vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "library/vectorVoid.h"


void test_atVector_notEmptyVector() {
    vector vec = createVector(10);
    vec.data[0] = 1;
    vec.data[1] = 2;
    vec.data[2] = 3;
    vec.data[3] = 4;
    vec.data[4] = 5;
    vec.size = 5;
    assert(vec.data[2] == *atVector(&vec, 2));
    free(vec.data);

}
void test_atVector_requestToLastElement(){
    vector vec = createVector(10);
    vec.data[0] = 1;
    vec.data[1] = 2;
    vec.data[2] = 3;
    vec.data[3] = 4;
    vec.data[4] = 5;
    vec.size = 5;
    assert(vec.data[4] == *atVector(&vec, 4));
    free(vec.data);
}
void test_back_oneElementInVector(){
    vector vec = createVector(10);
    vec.data[0] = 1;
    vec.size = 1;
    assert(1 == *back(&vec));
    free(vec.data);
}
void test_front_oneElementInVector(){
    vector vec = createVector(10);
    vec.data[0] = 1;
    vec.size = 1;
    assert(1 == *front(&vec));
    free(vec.data);
}
void test_pushBack_emptyVector(){
    vector vec = createVector(1);
    vec.size = 0;
    pushBack(&vec, 5);

    assert(vec.data[0] == 5 & vec.size == 1);
    free(vec.data);

}
void test_pushBack_fullVector(){
    vector vec = createVector(3);
    vec.data[0] = 1;
    vec.data[1] = 2;
    vec.data[2] = 3;
    vec.size = 3;

    pushBack(&vec, 5);
    assert(vec.data[3] == 5 & vec.size == 4);
    free(vec.data);
}
void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
    free(v.data);
}

void test_vec(){
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_front_oneElementInVector();
    test_back_oneElementInVector();
    test_atVector_requestToLastElement();
    test_atVector_notEmptyVector();
}

int main() {
    test_vec();
    return 0;
}