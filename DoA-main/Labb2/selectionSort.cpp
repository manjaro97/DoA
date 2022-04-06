#include "selectionSort.h"

std::vector<int> SelectionSort(std::vector<int> sortData){
    int minNum;
    //Looping through every position of the array
    for (int pos = 0; pos < sortData.size(); pos++)
    {
        //Looping through every position of the Unsorted array
        for (int pivot = pos; pivot < sortData.size(); pivot++)
        {
            //Checking which unsorted value is the smallest
            if(pivot == pos){
                minNum = pos;
            }
            else if(sortData[pivot] < sortData[minNum]){
                minNum = pivot;
            }
        }
        //Swapping the current pos with the smallest value
        std::swap(sortData[pos], sortData[minNum]);
    }
    return sortData;
}