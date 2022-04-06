#include "Stack.h"

void Stack::AddToStack(int x)
{
	v.push_back(x);
}

void Stack::PopStack()
{
	v.pop_back();
}

int Stack::Back() {
	return v.back();
}

int Stack::GetSize()
{
	return v.size();
}

void Stack::PrintStack()
{
	for (auto i : v) {
		std::cout << i << ", ";
	}

	std::cout << std::endl << std::endl;
}