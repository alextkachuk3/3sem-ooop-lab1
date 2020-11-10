/*! Dice class file
* \file graphs/Graph_matrix.hpp
* \author Alex Tkachuk
* \version 1.0 11/10/20
*/
#pragma once
#include <vector>
#include <set>
#include <iostream>
#include "Node.hpp"
#include "Edge.hpp"
#include "../ostream_vector_operator.hpp"

using namespace std;

/*Graph_matrix class*/
template<typename T>
class Graph_matrix
{
public:
	/*Default constructor*/
	Graph_matrix() = default;
	/*!Constructor
	* \param[in] matrix - matrix which we will use for creating new graph
	*/
	Graph_matrix(const vector<vector<T>>& matrix);
	/*Destructor*/
	~Graph_matrix();
	void insert(const T& data);
	/*! Erase edge
	* \param[in] index - index of node which we wont to erase
	*/
	void erase(const int& index);
	/*!Allow to create edge between nodes
	* \param[in] from_index index of node from which we wont to create edge
	* \param[in] to_index end point of this edge
	* \param[in] data - data which will be in new edge
	*/
	void connect(const int& from_index, const int& to_index, const T& data);
	/*!Allow to delete edge
	* \param[in] from_index index of node from which we wont to delete edge
	* \param[in] to_index end point of edge which we wont to delete
	*/
	void disconect(const int& from_index, const int& to_index);
	/*Print graph list*/
	void print();
	/*!Find path from first to second node
	* \param[in] from_index from node with this index we will try find path
	* \param[in] to_index node to which we try to find path
	*/
	int find_distanse(const int& from_index, const int& to_index);
	/*If graph is connectiveted return true, else false*/
	bool is_connected();

private:
	/*Matrix of graph*/
	vector<vector<Edge<T>*>> matrix;
	/*Nodes of graph*/
	vector<Node<T>*> vertices;
};

template<typename T>
inline Graph_matrix<T>::Graph_matrix(const vector<vector<T>>& matrix)
{
	this->matrix.empty();
	this->matrix.resize(matrix.size());
	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i].size() != matrix.size())
			throw exception("Matrix must be square!");
		for (int j = 0; j < matrix[i].size; j++)
		{
			connect(i, j, matrix[i][j]);
		}
	}
}

template<typename T>
inline Graph_matrix<T>::~Graph_matrix()
{
	for (auto& a : matrix)
	{
		for (auto& b : a)
		{
			if (b)
			{
				delete b;
			}
		}
	}
	for (auto& a : vertices)
		delete a;
}

template<typename T>
inline void Graph_matrix<T>::erase(const int& index)
{
	if (index >= vertices.size())
	{
		cout << "Wrong index!" << endl;
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		if (i != index)
		{
			if (matrix[i][index])
			{
				delete matrix[i][index];
			}
			matrix[i].erase(matrix[i].begin() + index);
		}
	}
	matrix.erase(matrix.begin() + index);
	delete vertices[index];
	vertices.erase(vertices.begin() + index);
	for (auto& a : vertices)
	{
		if (a->index > index)
		{
			a->index--;
		}
	}
}

template<typename T>
inline void Graph_matrix<T>::insert(const T& data)
{
	Node<T>* new_node = new Node<T>(vertices.size(), data);
	vertices.push_back(new_node);
	for (auto& a : matrix)
	{
		a.push_back(nullptr);
	}
	vector<Edge<T>*> new_line_for_matrix(vertices.size(), nullptr);
	matrix.push_back(new_line_for_matrix);
}

template<typename T>
inline void Graph_matrix<T>::connect(const int& from_index, const int& to_index, const T& data)
{
	if (matrix[from_index][to_index])
	{
		cout << "These vertices are already connected!" << endl;
		return;
	}
	Edge<T>* new_edge = new Edge<T>(vertices[to_index], data);
	matrix[from_index][to_index] = new_edge;
}

template<typename T>
inline void Graph_matrix<T>::disconect(const int& from_index, const int& to_index)
{
	if (!matrix[from_index][to_index])
	{
		cout << "This vertices are not connect" << endl;
		return;
	}
	auto temp = matrix[from_index][to_index];
	matrix[from_index][to_index] = nullptr;
	delete temp;
}

template<typename T>
inline void Graph_matrix<T>::print()
{
	cout << " ";
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << i;
		for (int j = 0; j < matrix.size(); j++)
		{
			if (matrix[i][j])
			{
				cout << " " << matrix[i][j]->data << " ";
			}
			else
			{
				cout << " 0 ";
			}
		}
		cout << endl;
	}
}

template<typename T>
inline int Graph_matrix<T>::find_distanse(const int& from_index, const int& to_index)
{
	return 0;
}

template<typename T>
inline bool Graph_matrix<T>::is_connected()
{
	return false;
}