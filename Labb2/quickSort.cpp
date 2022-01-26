#include "quickSort.h"

#include <iostream>

std::vector<int> QuickSort(std::vector<int> data, int low, int high){
    //Checking if there are values to sort
    if(low < high){
        //Partitions the array to get the pivotposition
        int pivot = partitioning(data, low, high);
        //Recurse the Quick Sort function with the new pivot
        //The function is called for left side and right side of the pivot
        data = QuickSort(data, low, pivot-1);
        data = QuickSort(data, pivot+1, high);
    }
    return data;
}

//Runs partioning on the given data in order to split the array in two. 
//left side will be smaller than pivot and right side will be larger
int partitioning(std::vector<int> &data, int low, int high){
    //picking right most value as pivot
    int pivot = high;
    int lhsPos = low-1;
    for (int pos = low; pos <= high-1; pos++)
    {
        //Checking if value is smaller than pivot
        if(data[pos] <= data[pivot]){
            lhsPos++;
            //Swaps value with the new right most position for the left hand side of the pivot
            std::swap(data[lhsPos], data[pos]);
        }
    }
    //Swaps rightmost position of left hand side +1 with the pivot
    std::swap(data[lhsPos+1], data[pivot]);

    //Returns rightmost position of left hand side +1 to get pivot position
    return lhsPos+1;
}

std::vector<int> QuickSortMedianOfThree(std::vector<int> data, int low, int high){
    //Checking if there are values to sort
    if(low < high){
        
        //Partitions the array to get the pivotposition
        int pivot = partitioning(data, low, high);
        
        //Recurse the Quick Sort function with the new pivot
        //The function is called for left side and right side of the pivot
        data = QuickSort(data, low, pivot-1);
        data = QuickSort(data, pivot+1, high);
    }
    return data;
}

//Runs partioning on the given data in order to split the array in two. 
//left side will be smaller than pivot and right side will be larger
int partitioningMedianOfThree(std::vector<int> &data, int low, int high){
    //Finding the middle value
    int mid = ((high - low)/2) + low;
    //Finding the median value
    int median = std::max(std::min(data[low],data[mid]), std::min(std::max(data[low],data[mid]),data[high]));
    int pivot;
    //Setting the pivot to the position of the median value
    if(data[low] == median){
        pivot = low;
    }
    else if(data[mid] == median){
        pivot = mid;
    }
    else{
        pivot = high;
    }
    int lhsPos = low-1;
    for (int pos = low; pos <= high-1; pos++)
    {
        //Checking if value is smaller than pivot
        if(data[pos] <= data[pivot]){
            lhsPos++;
            //Swaps value with the new right most position for the left hand side of the pivot
            std::swap(data[lhsPos], data[pos]);
        }
    }
    //Swaps rightmost position of left hand side +1 with the pivot
    std::swap(data[lhsPos+1], data[pivot]);

    //Returns rightmost position of left hand side +1 to get pivot position
    return lhsPos+1;
}