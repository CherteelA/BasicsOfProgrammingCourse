#include <malloc.h>
#include <stdio.h>
#include "vectorVoid.h"

//создание вектора
vectorVoid createVectorV(size_t n, size_t baseTypeSize){
    vectorVoid vecV;
    if(n == 0){
        vecV.data = NULL;
        vecV.size = 0;
        vecV.capacity = 0;
        vecV.baseTypeSize = baseTypeSize;
        return vecV;
    }

    int *ptr = malloc(baseTypeSize * n);

    if(ptr == NULL){
        fprintf(stderr, "bad alloc");
        exit(1);
    }



    vecV.data = (void **) ptr;
    vecV.size = 0;
    vecV.capacity = n;
    vecV.baseTypeSize = baseTypeSize;


    return vecV;
}

// изменяет количество памяти
void reserveV(vectorVoid *v, size_t newCapacity){
    int* arr[v->size];
    for(int i = 0; i < v->size; i++){
        arr[i] = v->data[i];
    }
    free(v->data);
    v->data = malloc(v->baseTypeSize * newCapacity);
    int size = 0;
    if(newCapacity != 0) {
        for (int i = 0; i < v->size; i++) {
            v->data[i] = arr[i];
            size++;
            if(size == newCapacity)
                break;
        }
    }
    v->size = size;
}