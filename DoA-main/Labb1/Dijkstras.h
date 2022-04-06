#pragma once
#include "reader.h"
#include <vector>
#include <limits>

class Dijkstras 
{
public:
	Dijkstras(std::vector<std::vector<float>> adjacency_matrix);
	void createList(int startNode, adjacency_list_t oldList);
	void calculatePath(int startNode, int endNode);
private:
	std::vector<std::vector<float>> adjMatix;
	bool isVisited(int node);
	float GetShortestDistance(int node);
	void UpdateNode(int prevNode, int newNode, float distance);
	int GetPrevNode(int node);

	struct edge {
		int node;
		float shortestDistance;
		int previousNode;
		bool isVisited;
	};
	std::vector<edge> nodeInfo;
};

