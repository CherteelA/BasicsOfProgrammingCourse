#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//создание вектора
vector createVector(size_t n){
    vector res;
    if(n == 0){
        res.data = NULL;
    } else{
        res.data = malloc(sizeof(int) * n);
        if(!res.data){
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
    res.size = 0;
    res.capacity = n;
    return res;
}

// изменяет количество памяти
void reserve(vector *v, size_t newCapacity){
    int a[v->size];
    for (int i = 0; i < v->size; i ++)
        a[i] = v->data[i];
    *v = (vector) {malloc(sizeof(int) * newCapacity), v->size, newCapacity};
    if(!v->data){
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    if(newCapacity == 0)
        v->data = NULL;
    else if (newCapacity >= v->size) {
        for (int i = 0; i < v->size; i++)
            v->data[i] = a[i];
    }
    else {
        for (int i = 0; i < newCapacity; i++)
            v->data[i] = a[i];
    }

}
//удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector *v){
    v->size = 0;
}


//освобождает память, выделенную под
//неиспользуемые элементы.
void shrinkToFit(vector *v){
    v->capacity = v->size;
}

//освобождает память, выделенную вектору
void deleteVector(vector *v){
    int a[v->size];
    for (int i = 0; i < v->size; i ++)
        a[i] = v->data[i];
    free(v->data);
    *v = (vector) {malloc(sizeof(int) * v->size), v->size, v->size};

}