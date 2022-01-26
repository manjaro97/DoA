#include "handleMeasurements.h"

struct TimeMeasurement  
{  
    std::string algorithm;  
    std::string dataType;  
    int N;  
    std::string timeFormat;
    long long time;
} ;

void handleMeasurements(int sampleSize){
    std::vector<std::string> data;
    std::fstream readFile;
    readFile.open("TimeMeasurements.txt",std::ios::in); //open a file to perform read operation using file object
    if(readFile.is_open()){   //checking whether the file is open
        std::string tp;
        while(std::getline(readFile, tp)){ //read data from file object and put it into string.
            //std::cout << tp << "\n"; //print the data of the string
            data.push_back(tp);
        }
        readFile.close(); //close the file object.
    }

    std::sort (data.begin(), data.end());
    for(auto test : data){
        std::cout << test << std::endl;
    }

    std::string copy;
    TimeMeasurement dataStruct;
    std::string firstDelim = ", ";
    std::string secondDelim = ", N = ";
    std::string thirdDelim = ", ";
    std::string fourthDelim = " = ";
    std::vector<TimeMeasurement> ds;
    
    for(auto s : data){
        copy = s;

        dataStruct.algorithm = copy.substr(0, copy.find(firstDelim)); 
        copy.erase(0, copy.find(firstDelim) + firstDelim.length());

        dataStruct.dataType = copy.substr(0, copy.find(secondDelim)); 
        copy.erase(0, copy.find(secondDelim) + secondDelim.length());

        dataStruct.N = std::stoi( copy.substr(0, copy.find(thirdDelim))); 
        copy.erase(0, copy.find(thirdDelim) + thirdDelim.length());

        dataStruct.timeFormat = copy.substr(0, copy.find(fourthDelim)); 
        copy.erase(0, copy.find(fourthDelim) + fourthDelim.length());

        dataStruct.time = std::stoll(copy); 
    
        ds.push_back(dataStruct);
    }


    // Create and open a text file
    std::ofstream TxtFile("EvalueatedTime.txt");

    for (int i = 0; i < (ds.size()/sampleSize); i++)
    {
        long long sum = 0;
        for (int i2 = 0; i2 < sampleSize; i2++){
            sum += ds[i*sampleSize + i2].time;
        }
        long long mean = sum/sampleSize;

        long long var = 0;
        for(int n = 0; n < sampleSize; n++ )
        {
          var += (ds[i*sampleSize + n].time - mean) * (ds[i*sampleSize + n].time - mean);
        }
        var /= sampleSize;
        long long sd = sqrt(var);

        TxtFile << ds[i*sampleSize].algorithm << ", " << ds[i*sampleSize].dataType << ", " << ds[i*sampleSize].timeFormat << ", " << mean << ", " << "N" << ", " << ds[i*sampleSize].N << ", samples, " << sampleSize << ", stdDev, " << sd << std::endl; 
    }

    TxtFile.close();

}

