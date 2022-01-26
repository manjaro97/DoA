#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>
#include "dataGenerator.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "quickSort.h"
#include "handleMeasurements.h"


//cd "c:\Users\j_c_k\Desktop\DoA\Labb2\" ; if ($?) { g++ main.cpp dataGenerator.cpp selectionSort.cpp insertionSort.cpp quickSort.cpp handleMeasurements.cpp -o main } ; if ($?) { .\main }

//Declaring function for printing data
void printData(std::string dataName, std::vector<int> data);

int main(){
    
    // Create and open a text file
    std::ofstream TxtFile("TimeMeasurements.txt");
    
    //Declaring timer and data buffer
    std::chrono::steady_clock::time_point timerStart;
    std::chrono::steady_clock::time_point timerStop;
    std::vector<int> dataBuffer;

    //Minimum value to generate
    int minNum = 1; 
    //Maximum value to generate
    int maxNum = 10000000;
    //Amount of data to generate
    int amount = 1000;
    //Value of Constant data to be generated
    int constantNum = 123;
    //Number of Time samples per sort
    int samples = 10;
    //Number of different sample sizes
    int sampleSizes = 20;

    //Looping for more Samples
    for (int iter = 0; iter < (samples * sampleSizes); iter++)
    {
        if(iter % samples == 0 && iter != 0){
            amount = amount + 500;
        }
        std::cout << std::endl << "***Generating Data***" << std::endl << std::endl;

        //Generating 4 types of data. Random Uniform, Ascending, Descending and Constant Data.
        std::vector<int> randomData = DataGenerator::GetRandomData(minNum, maxNum, amount);
        std::vector<int> ascendingData = DataGenerator::GetAscendingData(minNum, amount);
        std::vector<int> descendingData = DataGenerator::GetDescendingData(minNum, amount);
        std::vector<int> constantData = DataGenerator::GetConstantData(constantNum, amount);

        //Printing Generated Data to terminal
        printData("---Random Data---", randomData);
        printData("---Ascending Data---", ascendingData);
        printData("---Descending Data---", descendingData);
        printData("---Constant Data---", constantData);

        
        //    ***EVERY SORT BELOW FOLLOWS THE FOLLOWING FORMAT***

        //    Start Clock
        //    Sort Data
        //    Stop Clock
        //    Print Time Difference
        //    Print Data

        

        // SELECTION SORT ALGORITHM

        std::cout << std::endl << std::endl << "***Running SelectionSort Algorithm***" << std::endl << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = SelectionSort(randomData);
        timerStop = std::chrono::steady_clock::now();
        auto timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Random Data---", dataBuffer);
        TxtFile << "SelectionSort Algorithm" << ", " << "Random Uniform Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = SelectionSort(ascendingData);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Ascending Data---", dataBuffer);
        TxtFile << "SelectionSort Algorithm" << ", " << "Ascending Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = SelectionSort(descendingData);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Descending Data---", dataBuffer);
        TxtFile << "SelectionSort Algorithm" << ", " << "Descending Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = SelectionSort(constantData);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Constant Data---", dataBuffer);
        TxtFile << "SelectionSort Algorithm" << ", " << "Constant Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        // INSERTION SORT ALGORITHM

        std::cout << std::endl << std::endl <<  "***Running InsertionSort Algorithm***" << std::endl << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = InsertionSort(randomData);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Random Data---", dataBuffer);
        TxtFile << "InsertionSort Algorithm" << ", " << "Random Uniform Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = InsertionSort(ascendingData);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Ascending Data---", dataBuffer);
        TxtFile << "InsertionSort Algorithm" << ", " << "Ascending Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = InsertionSort(descendingData);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Descending Data---", dataBuffer);
        TxtFile << "InsertionSort Algorithm" << ", " << "Descending Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = InsertionSort(constantData);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Constant Data---", dataBuffer);
        TxtFile << "InsertionSort Algorithm" << ", " << "Constant Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        // QUICK SORT ALGORITHM (Rightmost element as Pivot)

        std::cout << std::endl << std::endl <<  "***Running QuickSort Algorithm (Rightmost element as Pivot)***" << std::endl << std::endl;

        int firstPos = 0;
        timerStart = std::chrono::steady_clock::now();
        dataBuffer = QuickSort(randomData, firstPos, randomData.size()-1);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Random Data---", dataBuffer);
        TxtFile << "QuickSort Algorithm (Rightmost element as Pivot)" << ", " << "Random Uniform Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = QuickSort(ascendingData, firstPos, ascendingData.size()-1);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Ascending Data---", dataBuffer);
        TxtFile << "QuickSort Algorithm (Rightmost element as Pivot)" << ", " << "Ascending Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = QuickSort(descendingData, firstPos, descendingData.size()-1);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Descending Data---", dataBuffer);
        TxtFile << "QuickSort Algorithm (Rightmost element as Pivot)" << ", " << "Descending Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = QuickSort(constantData, firstPos, constantData.size()-1);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Constant Data---", dataBuffer);
        TxtFile << "QuickSort Algorithm (Rightmost element as Pivot)" << ", " << "Constant Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        // QUICK SORT ALGORITHM (Median of three as Pivot)

        std::cout << std::endl << std::endl <<  "***Running QuickSort Algorithm (Median of three as Pivot)***" << std::endl << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = QuickSortMedianOfThree(randomData, firstPos, randomData.size()-1);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Random Data---", dataBuffer);
        TxtFile << "QuickSort Algorithm (Median of three as Pivot)" << ", " << "Random Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = QuickSortMedianOfThree(ascendingData, firstPos, ascendingData.size()-1);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Ascending Data---", dataBuffer);
        TxtFile << "QuickSort Algorithm (Median of three as Pivot)" << ", " << "Ascending Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = QuickSortMedianOfThree(descendingData, firstPos, descendingData.size()-1);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Descending Data---", dataBuffer);
        TxtFile << "QuickSort Algorithm (Median of three as Pivot)" << ", " << "Descending Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        dataBuffer = QuickSortMedianOfThree(constantData, firstPos, constantData.size()-1);
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;
        printData("---Sorted Constant Data---", dataBuffer);
        TxtFile << "QuickSort Algorithm (Median of three as Pivot)" << ", " << "Constant Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        // STD::SORT ALGORITHM

        std::cout << std::endl << std::endl << "***Running std::sort Algorithm***" << std::endl << std::endl;

        timerStart = std::chrono::steady_clock::now();
        std::sort (randomData.begin(), randomData.end());
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl; 
        printData("---Sorted Random Data---", randomData);
        TxtFile << "std::sort Algorithm" << ", " << "Random Uniform Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        std::sort (ascendingData.begin(), ascendingData.end());
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;  
        printData("---Sorted Ascending Data---", ascendingData);
        TxtFile << "std::sort Algorithm" << ", " << "Ascending Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        std::sort (descendingData.begin(), descendingData.end());
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;  
        printData("---Sorted Descending Data---", descendingData);
        TxtFile << "std::sort Algorithm" << ", " << "Descending Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        timerStart = std::chrono::steady_clock::now();
        std::sort (constantData.begin(), constantData.end()); 
        timerStop = std::chrono::steady_clock::now();
        timeDelta = std::chrono::duration_cast<std::chrono::nanoseconds> (timerStop - timerStart).count();
        std::cout << "Time difference = " << timeDelta << "[ns]" << std::endl;     
        printData("---Sorted Constant Data---", constantData);
        TxtFile << "std::sort Algorithm" << ", " << "Constant Data" << ", " << "N = " << amount << ", " << "T[ns] = " << timeDelta << std::endl;

        std::cout << iter;
    }
    TxtFile.close();
    
    handleMeasurements(samples);
    return 0;
}

//Function to print data
void printData(std::string dataName, std::vector<int> data){
    std::cout << dataName << std::endl;
    //for(int num : data){
    //    std::cout << num << " ";
    //}
    std::cout << std::endl << std::endl;
}