#include "Dijkstras.h"
#include <iostream>
#include <algorithm>

Dijkstras::Dijkstras(std::vector<std::vector<float>> adjacency_matrix){
	adjMatix = adjacency_matrix;
}

void Dijkstras::createList(int startNode, adjacency_list_t oldList) {
	for (auto i : oldList.first)
	{
		if (i.first == startNode) {
			nodeInfo.push_back({ i.first, 0, -1, false});
		}
		else {
			nodeInfo.push_back({ i.first, 99999, -1, false});
		}
	}
	return;
}

bool Dijkstras::isVisited(int node) {
	for (auto content : nodeInfo) {
		if (content.node == node) {
			return content.isVisited;
		}
	}
	return true;
}

void Dijkstras::calculatePath(int startNode, int endNode) {
	for (int i = 0; i < nodeInfo.size(); i++)
	{
		int targetNode;
		float dist = 999999;
		for (auto nextNode : nodeInfo) {
			if (nextNode.shortestDistance < dist && nextNode.isVisited == false) {
				dist = nextNode.shortestDistance;
				targetNode = nextNode.node;
			}
		}
		auto queuedNode = nodeInfo[targetNode];
		//std::cout << "next Target node: " << queuedNode.node << std::endl;
		//std::cout << "node dist: " << queuedNode.shortestDistance << std::endl;

		for (int connectedNodes = 0; connectedNodes < nodeInfo.size(); connectedNodes++)
		{
			if (adjMatix[queuedNode.node][connectedNodes] > 0 && isVisited(queuedNode.node) == false) {
				float newDistance = adjMatix[queuedNode.node][connectedNodes] + queuedNode.shortestDistance;
				if (GetShortestDistance(connectedNodes) > newDistance) {
					UpdateNode(queuedNode.node, connectedNodes, newDistance);
					//std::cout << "Updating node: " << connectedNodes << " with distance: " << newDistance << std::endl;
				}
			}
		}

		nodeInfo[targetNode].isVisited = true;
	}


	for (auto test: nodeInfo) {
		if(test.node == endNode){
			std::cout << "From: " << startNode << ", to:" << test.node << " with dist: " << test.shortestDistance << std::endl;
		}
	}

	std::cout << std::endl;
	int nodeBuffer = endNode;
	std::cout << "------Dijkstras Path------" << std::endl;
	std::cout << "Start Node: " << startNode << ", End Node: " << endNode << std::endl;
	while (nodeBuffer > 0) {
		std::cout << "To: " << nodeBuffer;
		nodeBuffer = GetPrevNode(nodeBuffer);
		std::cout << ", From: " << nodeBuffer << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
	return;
}

float Dijkstras::GetShortestDistance(int node) {
	if (node == -1) {
		return 0;
	}
	for (auto content : nodeInfo) {
		if (content.node == node) {
			return content.shortestDistance;
		}
	}
	return 0;
}

void Dijkstras::UpdateNode(int prevNode, int newNode, float distance) {
	for (int i = 0; i < nodeInfo.size(); i++)
	{
		if (nodeInfo[i].node == newNode) {
			nodeInfo[i].shortestDistance = distance;
			nodeInfo[i].previousNode = prevNode;
		}
	}
	return;
}

int Dijkstras::GetPrevNode(int node) {
	for (auto content: nodeInfo) {
		if (content.node == node) {
			return content.previousNode;
		}
	}
	return -1;
}