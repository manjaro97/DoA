#include "DFS.h"
#include <vector>
#include <iostream>


void DFS::dfs(std::vector<std::vector<int>> adjacency_matrix, int startNode) {
	stack.AddToStack(startNode);
	stackAdjacent(adjacency_matrix, startNode);


	std::cout << "Stack Size after DFS: " << stack.GetSize() << std::endl;
	stack.PrintStack();
}

void DFS::stackAdjacent(std::vector<std::vector<int>> adjacency_matrix, int startNode) {
	int nextNode;

	for (int i = 0; i < adjacency_matrix.size(); i++)
	{
		if (adjacency_matrix[startNode][i] != adjacency_matrix[i][startNode]) {
			std::cout << "*** THE GRAPH IS INVALID AT EDGE: " << startNode << " to " << i << ". ***" << std::endl;
		}
		if (adjacency_matrix[startNode][i] == 1 && isNew(i)) // && is not in queue)
		{
			queue.AddToStack(i);
		}
	}
	if (queue.GetSize() != 0) {
		stack.AddToStack(queue.Back());
		nextNode = queue.Back();
		queue.PopStack();
		stackAdjacent(adjacency_matrix, nextNode);
	}
}

bool DFS::isNew(int node) {
	for (auto i : stack.v) {
		if (i == node) {
			return false;
		}
	}
	for (auto i2 : queue.v) {
		if (i2 == node) {
			return false;
		}
	}
	return true;
}