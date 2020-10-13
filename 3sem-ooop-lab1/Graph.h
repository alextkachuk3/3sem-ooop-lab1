#pragma once
#include "top.h"
#include <map>
#include <vector>

using namespace std;

template<typename T>
class graph
{
public:
	void clear();
	void add_top(const T& data);
	int size() const;
	void connect(const int& first_index, const int& second_index, const int& connection_weight);
	void adj_matrix(const vector<vector<int>>& adjacency_matrix);
	void adj_list(const vector<vector<int>>& adjacency_list);
	void del_top(const int& index);
	void change_top_data(const int& index, const T& data);
	void print_graph();
private:
	map<int, top<T>> graph_map;
	/*!
	* In this vector we save index of deleted tops, which we will use for new tops
	*/
	vector<int> free_slots;
};
