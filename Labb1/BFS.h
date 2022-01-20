#pragma once
#include "Queue.h"
#include "Stack.h"

class BFS
{
public:
	void bfs(std::vector<std::vector<int>> adjacency_matrix, int startNode);

private:
	Stack stack;
	Queue queue;

	void queueAdjacent(std::vector<std::vector<int>> adjacency_matrix, int startNode);
	bool isNew(int node);
};

