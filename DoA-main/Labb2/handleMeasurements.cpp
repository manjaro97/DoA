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

    for (int differentSamples = 0; differentSamples < (ds.size()/sampleSize); differentSamples++)
    {
        long long sum = 0;
        for (int sameSamples = 0; sameSamples < sampleSize; sameSamples++){
            sum += ds[differentSamples*sampleSize + sameSamples].time;
        }
        long long mean = sum/sampleSize;

        long long var = 0;
        for(int sameSamples = 0; sameSamples < sampleSize; sameSamples++ )
        {
          var += (ds[differentSamples*sampleSize + sameSamples].time - mean) * (ds[differentSamples*sampleSize + sameSamples].time - mean);
        }
        var /= sampleSize;
        long long sd = sqrt(var);

        TxtFile << ds[differentSamples*sampleSize].algorithm << ", " << ds[differentSamples*sampleSize].dataType << ", " << ds[differentSamples*sampleSize].timeFormat << ", " << mean << ", " << "N" << ", " << ds[differentSamples*sampleSize].N << ", samples, " << sampleSize << ", stdDev, " << sd << std::endl; 
    }

    TxtFile.close();

}

