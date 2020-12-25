#include "Network.h"
#include "Utility.h"

int Network::GetKCIndex(int id) const
{
	return IdIndexKC.find(id)->second;
}

void Network::AddKC(const unordered_map<int, KC>& map, int id)
{
edges.insert(map.find(id)->first);
IdIndexKC.insert({ id, edges.size() - 1 });
cout << "CS added ID: " << IdIndexKC.find(id)->first << " Index: " << IdIndexKC.find(id)->second << endl;
is_changed = true;

}

void Network::AddPipes(const unordered_map<int, Pipes>& map, int id)
{
	vertex.insert(map.find(id)->first);
	IdIndexPipes.insert({ id, vertex.size() - 1 });
	cout << "Pipe added ID: " << IdIndexPipes.find(id)->first << " Index: " << IdIndexPipes.find(id)->second << endl;
	is_changed = true;
}

void Network::ConnectEdges(unordered_map<int, KC>& mapCS, unordered_map<int, Pipes>& mapPipe)
{
	cout << "Enter start CS: " << endl;
	int CSId1 = GetCorrectNumber(0, KC::GetMaxID());
	cout << "Enter pipe" << endl;
	int pipeId = GetCorrectNumber(0, Pipes::GetMaxID());
	cout << "Enter end CS: " << endl;
	int CSId2 = GetCorrectNumber(0, KC::GetMaxID());
	mapPipe.find(pipeId)->second.SetStart(CSId1);
	mapPipe.find(pipeId)->second.SetEnd(CSId2);
	cout << "CS " << CSId1 << " was connected to CS " << CSId2 << "by Pipe with an ID " << pipeId << endl;
	is_changed = true;
}


void Network::CreateAdjacencyMatrix(unordered_map<int, KC>& mapKC, unordered_map<int, Pipes>& mapPipes)
{
	int n = edges.size();
	if (is_changed) {
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
		}
	}
}

void Network::DeleteVertex(int id)
{
	is_changed = true;
	vertex.erase(vertex.find(id));
	IdIndexPipes.erase(id);

}
