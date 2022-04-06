#include "insertionSort.h"

std::vector<int> InsertionSort(std::vector<int> data){
    int targetNum;
    //Looping through every position of the unsorted vector
    for (int pos = 0; pos < data.size(); pos++)
    {
        targetNum = pos;
        //Looping through every position of the sorted vector
        for (int pivot = pos-1; pivot >= 0; pivot--)
        {
            //Checking if the Pivot value is smaller than the sorted values
            if(data[targetNum] < data[pivot] ){
                //Swapping the pivot value with each bigger sorted number
                std::swap(data[targetNum], data[pivot]);
                targetNum = pivot;
            }
            else{
                break;
            }
        }
        
    }
    return data;
}