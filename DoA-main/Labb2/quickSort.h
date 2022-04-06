#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

//Declaring Quick Sort Algorithm with unsorted data, leftmost valueposition and rightmost valueposition as parameters and returns sorted data
std::vector<int> QuickSort(std::vector<int> data, int low, int high);

//Declaring PartionFunction of the Quick Sort Algorithm which is iterated throughout the algorithm, rightmost value chosen as pivot
int partitioning(std::vector<int> &data, int low, int high);

//Declaring Quick Sort Algorithm with unsorted data, leftmost valueposition and rightmost valueposition as parameters and returns sorted data
std::vector<int> QuickSortMedianOfThree(std::vector<int> data, int low, int high);

//Declaring PartionFunction of the Quick Sort Algorithm which is iterated throughout the algorithm, median of three used to choose pivot
int partitioningMedianOfThree(std::vector<int> &data, int low, int high);

#endif