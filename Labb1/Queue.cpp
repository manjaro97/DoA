#include "Queue.h"

void Queue::AddToQueue(int x)
{
	v.push_back(x);
}

void Queue::PopQueue()
{
	v.erase(v.begin());
}

int Queue::GetSize() {
	return v.size();
}

int Queue::Front() {
	return v.front();
}

void Queue::PrintQueue()
{
	for (auto i : v) {
		std::cout << i << ", ";
	}

	std::cout << std::endl << std::endl;
}
