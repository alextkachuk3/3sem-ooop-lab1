#pragma once
#include <vector>
#include <set>
#include <iostream>
#include "Node.hpp"
#include "Edge.hpp"

using namespace std;

template<typename T>
class Graph_matrix
{
public:
	void add_top(const T& data);
	void delete_top(const int& index);
	void connect_top(const int& first_index, const int& second_index);
	void disconect_top(const int& first_index, const int& second_index);
	friend ostream& operator<<(ostream& out, const Graph_list<T>& graph_list);
private:
	vector<vector<Edge<T>*>> matrix;
	set<Node<T>*> vertices;
};
