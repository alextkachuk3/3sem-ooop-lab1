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
	void insert(const T& data);
	void erase(const int& index);
	void connect(const int& first_index, const int& second_index);
	void disconect(const int& first_index, const int& second_index);
	friend ostream& operator<<(ostream& out, const Graph_matrix<T>& graph_list);
private:
	vector<vector<Edge<T>*>> matrix;
	set<Node<T>*> vertices;
};

template<typename T>
ostream& operator<<(ostream& out, const Graph_matrix<T>& graph_list)
{

	return out;
}

template<typename T>
inline void Graph_matrix<T>::erase(const int& index)
{
	
}

template<typename T>
inline void Graph_matrix<T>::insert(const T& data)
{
	Node<T>* new_node = new Node<T>(vertices.size(), data);
	vertices.insert(new_node);
	for (auto& a : matrix)
	{
		a.push_back(nullptr);
	}
	vector<Edge<T>*> new_line_for_matrix(vertices.size(), nullptr);
	matrix.push_back(new_line_for_matrix);
}

template<typename T>
inline void Graph_matrix<T>::connect(const int& first_index, const int& second_index)
{

}

template<typename T>
inline void Graph_matrix<T>::disconect(const int& first_index, const int& second_index)
{

}