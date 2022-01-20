#pragma once
#include <vector>
#include <iostream>

class Queue
{
public:
	std::vector<int> v;
	void AddToQueue(int x);
	void PopQueue();
	int GetSize();
	int Front();
	void PrintQueue();
private:

};
