#include <iostream>
#include <vector>
#include "Queue.h"
#include "Stack.h"
#include "reader.h"
#include "BFS.h"
#include "DFS.h"
#include "Dijkstras.h"

//cd "c:\Users\j_c_k\Desktop\DoA\Labb1\" ; if ($?) { g++ main.cpp BFS.cpp DFS.cpp Dijkstras.cpp Queue.cpp reader.cpp Stack.cpp -o main } ; if ($?) { .\main }

int main()
{	
	//Parsing Original Text-File
	auto parsed_File = parse_file("export.txt");

	//Printing number of nodes in export.txt
	std::cout << "Number of nodes in export.txt: " << parsed_File.first.size() << std::endl << std::endl;

	//Creating Adjacency Matrix
	std::vector<std::vector<int>> adjacency_matrix(parsed_File.first.size(), std::vector<int>(parsed_File.first.size(), 0));
	for (int i = 0; i < parsed_File.second.size(); i++)
	{
		adjacency_matrix[parsed_File.second[i].n1][parsed_File.second[i].n2] = 1;
	}

	//Printing out Adjacency Matrix with nighbours as 1 and rest 0
	std::cout << "*** Printing Adjacency Matrix ***" << std::endl;
	for (int y = 0; y < adjacency_matrix.size(); y++)
	{
		for (int x = 0; x < adjacency_matrix.size(); x++)
		{
			std::cout << adjacency_matrix[x][y] << " ";
		}
		std::cout << std::endl;
	}

	//Break
	std::cout << std::endl << std::endl;

	//Running BFS
	std::cout << "*** Running BFS ***" << std::endl;
	BFS BreadthFirstSearch;
	BreadthFirstSearch.bfs(adjacency_matrix, 2);

	//Break
	std::cout << std::endl << std::endl;
	
	//Running DFS
	std::cout << "*** Running DFS ***" << std::endl;
	DFS DepthFirstSearch;
	DepthFirstSearch.dfs(adjacency_matrix, 2);

	//Break
	std::cout << std::endl << std::endl;
	
	//Copied and adjusted export.txt into exportAdjusted.txt
	//Added edge: 3 19 6.23[Stängd pizzeria]
	//Adjusted Length: 46 44 4.00[Trapphus L]
	//Adjusted Length: 44 46 4.00[Trapphus L]
	
	//Parsing Adjusted Text-File
	auto parsed_AdjustedFile = parse_file("exportAdjusted.txt");

	//Creating Adjusted Adjacency Matrix and setting weights
	std::vector<std::vector<float>> adjusted_adjacency_matrix(parsed_AdjustedFile.first.size(), std::vector<float>(parsed_AdjustedFile.first.size(), -1));
	for (int i = 0; i < parsed_AdjustedFile.second.size(); i++)
	{
		adjusted_adjacency_matrix[parsed_AdjustedFile.second[i].n1][parsed_AdjustedFile.second[i].n2] = parsed_AdjustedFile.second[i].weight;
	}
	//Setting Weight to self = 0
	for (int i = 0; i < parsed_File.first.size(); i++)
	{
		adjusted_adjacency_matrix[i][i] = 0;
	}

	//Printing out Adjusted Adjacency Matrix with neighbours as Weight and rest -1
	std::cout << "*** Printing Adjusted Adjacency Matrix with weights ***" << std::endl;
	for (int y = 0; y < adjusted_adjacency_matrix.size(); y++)
	{
		for (int x = 0; x < adjusted_adjacency_matrix.size(); x++)
		{
			std::cout << adjusted_adjacency_matrix[x][y] << " ";
		}
		std::cout << std::endl;
	}

	//Break
	std::cout << std::endl << std::endl; 

	std::cout << std::endl << "Nackstavagen to Forradet" << std::endl;
	int startNode = 24; //Nackstavägen
	int endNode = 37;  //Förrådet

	Dijkstras nackstaForradet(adjusted_adjacency_matrix);
	nackstaForradet.createList(startNode, parsed_AdjustedFile);
	nackstaForradet.calculatePath(startNode, endNode);

	std::cout << std::endl << "L319 to D025" << std::endl;
	startNode = 46; //L319
	endNode = 47;  //D025

	Dijkstras skolanLokaler(adjusted_adjacency_matrix);
	skolanLokaler.createList(startNode, parsed_AdjustedFile);
	skolanLokaler.calculatePath(startNode, endNode);


	
	std::cout << std::endl << "Universitetet to Bite Line Vastra" << std::endl;
	startNode = 7; //Universitetet
	endNode = 19;  //Bite Line Västra

	Dijkstras uniBiteline(adjusted_adjacency_matrix);
	uniBiteline.createList(startNode, parsed_AdjustedFile);
	uniBiteline.calculatePath(startNode, endNode);

	system("pause");
	return 0;
}