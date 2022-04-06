#include "dataGenerator.h"

std::vector<int> DataGenerator::GetRandomData(int min, int max, int amount){
    std::vector<int> data;

    //Declaring Random variable with set uniform distribution
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(min,max);

    int newData;
    for (int i = 0; i < amount; i++)
    {   
        //Generating Random Value and pushing to vector
        newData = dist(rng);
        data.push_back(newData);
    }

    return data;
}

std::vector<int> DataGenerator::GetDescendingData(int min, int amount){
    std::vector<int> data;

    //Iterating and adding increasing numbers in the front of the vector to get a Descending Vector
    for (int i = 0; i < amount; i++)
    {
        data.insert(data.begin(), min+i);
    }

    return data;
}

std::vector<int> DataGenerator::GetAscendingData(int min, int amount){
    std::vector<int> data;

    //Iterating and adding increasing numbers in the back of the vector to get a Descending Vector
    for (int i = 0; i < amount; i++)
    {
        data.push_back(min+i);
    }

    return data;
}

std::vector<int> DataGenerator::GetConstantData(int num, int amount){
    std::vector<int> data;

    //Iterating and adding the same number in the back of the vector to get a Vector of constant values
    for (int i = 0; i < amount; i++)
    {
        data.push_back(num);
    }

    return data;
}