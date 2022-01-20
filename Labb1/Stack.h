#pragma once
#include <vector>
#include <iostream>

class Stack
{
public:
	std::vector<int> v;
	void AddToStack(int x);
	void PopStack();
	int Back();
	int GetSize();
	void PrintStack();
private:

};