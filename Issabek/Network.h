#pragma once
#include "Pipes.h"
#include "KC.h"
#include <unordered_set>
#include <unordered_map>
#include <vector>


using namespace std;

class Network
{
	unordered_set<int> edges;
	unordered_set<int> vertex;

	unordered_map<int, int> IdIndexKC;
	unordered_map<int, int> IdIndexPipes;

	vector<vector<int>> AdjacencyMatrix;
	vector<vector<int>> IncidenceMatrix;
	bool is_changed;

public:
	int GetKCIndex(int) const;

	void AddKC(const unordered_map<int, KC>&, int);

	void AddPipes(const unordered_map<int, Pipes>&, int);

	void ConnectEdges(unordered_map<int, KC>&, unordered_map<int, Pipes>&);


	void CreateAdjacencyMatrix(unordered_map<int, KC>&, unordered_map<int, Pipes>&);


	void DeleteEdge(int, unordered_map<int, Pipes>&);

	void DeleteVertex(int);

	void TopologicalSort(int, vector<int>&, bool&, vector<int>&);

	void TopSort();

};

