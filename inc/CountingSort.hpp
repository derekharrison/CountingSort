/*
 * CountingSort.hpp
 *
 *  Created on: Jul 14, 2020
 *      Author: d-w-h
 */

#ifndef COUNTINGSORT_HPP_
#define COUNTINGSORT_HPP_

class CountingSort {
private:
    int size;
    int* A;
    int* B;

    int max_val_array(int* Array);
public:
    CountingSort(int size);
    ~CountingSort();
    void setA(int* Array);
    void counting_sort(int* Array);
    void set_results(int* Array);
};

void counting_sort(int* Array, int size);

#endif /* COUNTINGSORT_HPP_ */
