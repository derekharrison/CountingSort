/*
 * CountingSort.cpp
 *
 *  Created on: Jul 14, 2020
 *      Author: d-w-h
 */

#include "../inc/CountingSort.hpp"

CountingSort::CountingSort(int size) {
    this->size = size;
    A = new int[size+1];
    B = new int[size+1];
}

CountingSort::~CountingSort() {
    delete [] this->A;
    delete [] this->B;
}

void CountingSort::setA(int* Array) {
    for(int i = 1; i < this->size + 1; ++i) {
        this->A[i] = Array[i-1];
    }
}

int CountingSort::max_val_array(int* Array) {
    int max_val = -2147483647;
    for(int i = 0; i < this->size; ++i) {
        if(Array[i] >= max_val) {
            max_val = Array[i];
        }
    }

    return max_val;
}

void CountingSort::counting_sort(int* Array) {
    int max_val = CountingSort::max_val_array(Array);
    int* C = new int[max_val+1];
    for(int i = 0; i < max_val + 1; ++i) {
        C[i] = 0;
    }
    for(int j = 1; j < this->size + 1; ++j) {
        C[this->A[j]] = C[this->A[j]] + 1;
    }
    for(int i = 1; i < max_val + 1; ++i) {
        C[i] = C[i] + C[i-1];
    }
    for(int j = this->size; j > 0; --j) {
        this->B[C[this->A[j]]] = this->A[j];
        C[this->A[j]] = C[this->A[j]] - 1;
    }
}

void CountingSort::set_results(int* Array) {
    for(int i = 1; i < this->size + 1; ++i) {
        Array[i-1] = this->B[i];
    }
}

void counting_sort(int* Array, int size) {
    CountingSort c_sort(size);
    c_sort.setA(Array);
    c_sort.counting_sort(Array);
    c_sort.set_results(Array);
}
