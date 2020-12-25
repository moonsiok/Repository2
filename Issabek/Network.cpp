#include "Network.h"
#include "Utility.h"
#include <queue>
int Network::GetKCIndex(int id) const
{
	return IdIndexKC.find(id)->second;
}

void Network::AddKC(const unordered_map<int, KC>& map, int id)
{
edges.insert(map.find(id)->first);
IdIndexKC.insert({ id, edges.size() - 1 });
cout << "added CS ID: " << IdIndexKC.find(id)->first << " Index: " << IdIndexKC.find(id)->second << endl;
is_changed = true;

}

void Network::AddPipes(const unordered_map<int, Pipes>& map, int id)
{
	vertex.insert(map.find(id)->first);
	IdIndexPipes.insert({ id, vertex.size() - 1 });
	cout << "added Pipe ID: " << IdIndexPipes.find(id)->first << " Index: " << IdIndexPipes.find(id)->second << endl;
	is_changed = true;
}

void Network::ConnectEdges(unordered_map<int, KC>& mapCS, unordered_map<int, Pipes>& mapPipe)
{
	cout << "Enter an ID of start CS: " << endl;
	int CSId1 = GetCorrectNumber(0, KC::GetMaxID());
	cout << "Enter an ID of Pipe" << endl;
	int pipeId = GetCorrectNumber(0, Pipes::GetMaxID());
	cout << "Enter an ID of end CS: " << endl;
	int CSId2 = GetCorrectNumber(0, KC::GetMaxID());
	mapPipe.find(pipeId)->second.SetStart(CSId1);
	mapPipe.find(pipeId)->second.SetEnd(CSId2);
	cout << "CS " << CSId1 << " was connected to CS " << CSId2 << " by Pipe with an ID " << pipeId << endl;
	is_changed = true;
}


void Network::CreateAdjacencyMatrix(unordered_map<int, KC>& mapKC, unordered_map<int, Pipes>& mapPipes)
{
	int n = edges.size();
	if (is_changed) {
		//UpdateIndexKC();
		AdjacencyMatrix.clear();
		AdjacencyMatrix.resize(n);
		for (int i = 0; i < n; i++) {
			AdjacencyMatrix[i].resize(n);
			is_changed = false;
		}
	}
	for (auto itr = mapPipes.begin(); itr != mapPipes.end(); itr++) {
		if (itr->second.GetStart() != -1) {
			AdjacencyMatrix[GetKCIndex(itr->second.GetStart())][GetKCIndex(itr->second.GetEnd())] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << AdjacencyMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Network::DeleteEdge(int id, unordered_map<int, Pipes>& mapPipes)
{
	is_changed = true;
	edges.erase(id);
	IdIndexKC.erase(id);

	for (auto iter = mapPipes.begin(); iter != mapPipes.end(); iter++) {
		if (iter->second.GetStart() == id || iter->second.GetEnd() == id) {
			DeleteVertex(iter->first);
			mapPipes.erase(iter->first);
			break;
		}
	}
}

void Network::DeleteVertex(int id)
{
	is_changed = true;
	vertex.erase(id);
	IdIndexPipes.erase(id);

}

void Network::UpdateIndexCS()
{
	int i = 0;
	for (auto iter = IdIndexKC.begin(); iter != IdIndexKC.end(); iter++) {
		iter->second = i;
		++i;
	}
	i = 0;
	for (auto iter = IdIndexPipes.begin(); iter != IdIndexPipes.end(); iter++) {
		iter->second = i;
	}
}

int Network::GetIDkc(int index) const
{
	for (auto iter = IdIndexKC.begin(); iter != IdIndexKC.end(); iter++) {
		if (iter->second == index)
			return iter->first;
	}
	return 0;
}

void Network::TopologicalSort(int index, vector<int>& colors, bool& cycl, vector<int>& TopSortedVector)
{
	if (colors[index] == 2)
		return;
	if (cycl)
		return;
	if (colors[index] == 1) {
		cycl = true;
		return;
	}
	colors[index] = 1;
	for (int i = 0; i < edges.size(); i++) {
		if (AdjacencyMatrix[index][i] == 1) {
			int AdjacencyEdge = i;
			TopologicalSort(AdjacencyEdge, colors, cycl, TopSortedVector);
			if (cycl)
				return;
		}

	}
	colors[index] = 2;
	TopSortedVector.push_back(GetIDkc(index));
}

void Network::TopSort()
{
	vector<int> colors;
	colors.resize(edges.size());
	vector<int> TopSortedVector;
	bool cycl = false;
	for (int i = 0; i < edges.size(); i++) {
		TopologicalSort(i, colors, cycl, TopSortedVector);
	}
	if (cycl) {
		cout << "There is cycle" << endl;
	}
	else {
		reverse(TopSortedVector.begin(), TopSortedVector.end());
		cout << "Topological sort: " << endl;
		for (int i = 0; i < TopSortedVector.size(); i++) {
			cout << TopSortedVector[i] << " ";
		}
		cout << endl;
	}
}