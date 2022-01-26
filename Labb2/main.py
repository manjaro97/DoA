import matplotlib.pyplot as plt
import numpy as np
import csv
from ctypes import c_longlong as ll, sizeof

#Elements\tTime[ms]\tSamples\t\tFault analysis[ns]
time = []
dataAmount = []
stddev = []

with open('EvalueatedTime.txt', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=',')
    var = "test"
    Algorithm = ""
    Data = ""
    Type = ""
    Amount = ""
    Samples = ""
    first = True
    for ROWS in plotting:
        if first:
            var = ROWS[1]
            first = False
        elif var != ROWS[1]:
            var = ROWS[1]
            plt.errorbar(dataAmount, time, stddev, linestyle='None', marker='^', capsize=3)
            plt.title(Algorithm + "\n" + Data)
            plt.ylabel("Time "+Type)
            plt.xlabel("Amount: " + Amount)
            plt.show()
            time.clear()
            dataAmount.clear()
            stddev.clear()
        #print(int(ROWS[3]))
        Algorithm = ROWS[0]
        Data = ROWS[1]
        Type = ROWS[2]
        Amount = ROWS[4]
        Samples = ROWS[6]

        time.append(int(ROWS[3]))
        dataAmount.append(int(ROWS[5]))
        stddev.append(int(ROWS[9]))
 
plt.errorbar(dataAmount, time, stddev, linestyle='None', marker='^', capsize=3)
plt.title(Algorithm + "\n" + Data)
plt.ylabel("Time "+Type)
plt.xlabel("Amount: " + Amount)
plt.show()