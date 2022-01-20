#include "BFS.h"
#include <vector>
#include <iostream>


void BFS::bfs(std::vector<std::vector<int>> adjacency_matrix, int startNode) {
	stack.AddToStack(startNode);
	queueAdjacent(adjacency_matrix, startNode);


	std::cout << "Stack Size after BFS: " << stack.GetSize() << std::endl;
	stack.PrintStack();
}

void BFS::queueAdjacent(std::vector<std::vector<int>> adjacency_matrix, int startNode) {
	int nextNode;

	for (int i = 0; i < adjacency_matrix.size(); i++)
	{
		if (adjacency_matrix[startNode][i] != adjacency_matrix[i][startNode]) {
			std::cout << "*** THE GRAPH IS INVALID AT EDGE: " << startNode << " to " << i << ". ***" << std::endl;
		}
		if (adjacency_matrix[startNode][i] == 1 && isNew(i)) // && is not in queue)
		{
			queue.AddToQueue(i);
		}
	}
	if (queue.GetSize() != 0) {
		stack.AddToStack(queue.Front());
		nextNode = queue.Front();
		queue.PopQueue();
		queueAdjacent(adjacency_matrix, nextNode);
	}
}

bool BFS::isNew(int node) {
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