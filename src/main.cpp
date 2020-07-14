/*
 * main.cpp
 *
 *  Created on: Jul 14, 2020
 *      Author: d-w-h
 */

#include <cstdlib>
#include <iostream>
#include <time.h>

#include "../inc/CountingSort.hpp"

int main(int argc, char * argv[])
{
    int size = 200;
    int* Array = new int[size];

    srand(time(NULL));
    for(int i = 0; i < size; ++i) {
        Array[i] = rand() % size;
    }

    counting_sort(Array, size);

    for(int i = 0; i < size; ++i) {
        std::cout << Array[i] << std::endl;
    }

    return 0;
}
