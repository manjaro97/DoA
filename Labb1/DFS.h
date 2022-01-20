#pragma once
#include "Stack.h"

class DFS
{
public:
	void dfs(std::vector<std::vector<int>> adjacency_matrix, int startNode);

private:
	Stack stack;
	Stack queue;

	void stackAdjacent(std::vector<std::vector<int>> adjacency_matrix, int startNode);
	bool isNew(int node);
};

