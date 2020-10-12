#pragma once
#include "top.h"
#include <map>
#include <vector>

using namespace std;

template<typename T>
class graph
{
public:
	void clean();
	void add_top(const T& data);
	int size() const;
	void connect(const int& first_index, const int& second_index, const int& connection_weight);
	void adj_matrix(const vector<vector<int>>& adjacency_matrix);
	void adj_list(const vector<vector<int>>& adjacency_list);
	//void del_top(const int& index);
private:
	map<int, top<T>> graph_map;
	vector<int> free_slots;
};
