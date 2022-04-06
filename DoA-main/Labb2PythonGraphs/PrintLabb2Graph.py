from matplotlib import pyplot as plt
import numpy              as np
import re

print("Hello World")

valueList = [] 

with open("TimeMeasurements.txt") as f:
    for line in f:
        # Do something with 'line'
        valueList.append(line) 

# sort the list
valueList.sort()

#for test in valueList:
    #print(test) 

listOfData = []

for data in valueList:
    data = data.replace(', T[ns] = ', ', ')
    data = data.replace(', N = ', ', ')
    data = data.replace('\n', '')
    listingData = data.split(', ')
    listOfData.append(listingData)


newListOfData = []
dataBuffer = []
medianData = []

algoCheck = listOfData[0][0]
dataTypeCheck = listOfData[0][1]
amountCheck = listOfData[0][2]

for data in listOfData:
    if algoCheck == data[0] and dataTypeCheck == data[1] and amountCheck == data[2]:
        print("")
    else:
        #print(data[0] + " " + data[1] + " " + data[2] + " " + data[3])
        #dataBuffer.sort(key=lambda l:l[3])
        #num = 0
        #iter = 0
        #for d in dataBuffer:
            #iter += 1
            #num += int(d[3])
        #dataBuffer[5][3] = num/iter
        #dataBuffer[5][2] = int(dataBuffer[5][2])
        #newListOfData.append(dataBuffer[5])
        #dataBuffer.clear()
        algoCheck = data[0]
        dataTypeCheck = data[1]
        amountCheck = data[2]
    #dataBuffer.append(data)
    data[2] = int(data[2])
    data[3] = int(data[3])
    newListOfData.append(data)

#print(newListOfData)
newListOfData.sort(key=lambda row: (row[0], row[1], row[2]))
#print(newListOfData)
#input("test")

algo = newListOfData[0][0]
dataType = newListOfData[0][1]

amount = [] 
time = []

#for data in listOfData:
    #print(data)

for data in newListOfData:
    #print(algo + " = " + data[0])
    #print(dataType + " = " + data[1])
    if algo == data[0] and dataType == data[1]:
        print("")
    else:
        plt.title(algo + ", type: " + dataType)
        plt.scatter(amount, time)
        plt.xlabel("amount")
        #print(amount)
        plt.ylabel("time")
        #plt.xlim(min(amount),max(amount))
        #plt.ylim(min(time),max(time))
        #plt.xticks(np.linspace(min(amount), max(amount), 7))  # arbitrary chosen
        #plt.yticks(np.linspace(min(time), max(time), 5))  # arbitrary chosen
        
        #plt.axis([min(amount), max(amount), min(time), max(time)])
        plt.show()

        amount.clear() 
        time.clear()
        algo = data[0]
        dataType = data[1]
    amount.append(data[2])
    time.append(data[3])

    #print(data)