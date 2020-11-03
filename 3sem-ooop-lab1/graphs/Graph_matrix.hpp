#pragma once
#include <vector>
#include <set>
#include <iostream>
#include "Node.hpp"
#include "Edge.hpp"

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << "{ "
		for (auto& a : v)
		{
			out << a << " ";
		}
	out << "}";
	return out;
}

template<typename T>
class Graph_matrix
{
public:
	~Graph_matrix();
	void insert(const T& data);
	void erase(const int& index);
	void connect(const int& from_index, const int& to_index, const T& data);
	void disconect(const int& from_index, const int& to_index);
	void print();
private:
	vector<vector<Edge<T>*>> matrix;
	vector<Node<T>*> vertices;
};

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