#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <vector>
#include <random>

//Created the generator functions as class functions just for fun and to learn, no real reason
//Setting functions to static in order to be able to call the functions like this: DataGenerator::GetRandomData(minNum, maxNum, amount);
class DataGenerator{
  public:
    static std::vector<int> GetRandomData(int min, int max, int amount);
    static std::vector<int> GetDescendingData(int min, int amount);
    static std::vector<int> GetAscendingData(int min, int amount);
    static std::vector<int> GetConstantData(int num, int amount);
};

#endif