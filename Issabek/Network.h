#pragma once
#include "Pipes.h"
#include "KC.h"
#include <unordered_set>
#include <unordered_map>
#include <vector>
//#include "utils.h"
#include <set>
#include <stack>
#include <iostream>

using namespace std;

class Network
{

	unordered_map<int, Pipes> pGroup;
	unordered_map<int, KC> csGroup;
	vector<vector<int>> GetEdgesAndVertexes(unordered_map<int, int>& indexVertexes, int& n);
	bool is_changed;


public:
	Network();
	Network(ifstream& fin);
	friend ostream& operator << (ostream& out, const Network& GTS);
	void SaveToFile(ofstream& fout);
	bool HasPipe() const;
	bool HasCs(int count = 1) const;
	void EditPipe();
	void EditCs();
	void DeletePipe();
	void DeleteCs();
	void ConnectPipe();
	void DisconnectPipe();
	bool CanBeUsed(const Pipes& p) const;
	void ShowNetwork();
	void FindMaxFlow();
	void FindShortestPath();
	void AddCS();
	void AddPipe();
	void TopologicalSort();
};

