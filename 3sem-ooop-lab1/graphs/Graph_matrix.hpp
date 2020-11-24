/*! Dice class file
* \file graphs/Graph_matrix.hpp
* \author Alex Tkachuk
* \version 1.0 11/10/20
*/
#pragma once
#include <vector>
#include <set>
#include <iostream>
#include <iomanip>
#include "Node.hpp"
#include "Edge.hpp"
#include "../vector_operators.hpp"

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
	/*! Change data in graph node
	* \param[in] index - index of node in which we wont to change data
	* /param[in] data - new data for node
	*/
	void set_data(const int& index, const T& data);
	/*! Add new node
	* \param[in] data - data which will contain this node
	*/
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
	vector<pair<Edge<T>*, Node<T>*>> find_paths(const int& from_index, const int& to_index);
	/*If graph is connectiveted return true, else false*/
	bool is_connected();

private:
	/*Matrix of graph*/
	vector<vector<Edge<T>*>> matrix;
	/*Nodes of graph*/
	vector<Node<T>*> vertices;
	/*!Recursive function which find shortest path
	* \param[in] result here function insert all posible paths
	* \param[in] current from this node we find path
	* \param[in] end to this node we find path
	*/
	void go_throw_graph(vector<vector<pair<Edge<T>*, Node<T>*>>>& result, Node<T>* current, Node<T>* end, vector<pair<Edge<T>*, Node<T>*>> passed_vertex = {});
	void go_throw_all(Node<T>* current, set<Node<T>*>& passed_vertex);
};

template<typename T>
inline Graph_matrix<T>::Graph_matrix(const vector<vector<T>>& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		Node<T>* new_node = new Node<T>(i);
		vertices.push_back(new_node);
		for (auto& a : this->matrix)
		{
			a.push_back(nullptr);
		}
		vector<Edge<T>*> new_line_for_matrix(vertices.size(), nullptr);
		this->matrix.push_back(new_line_for_matrix);
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i].size() != matrix.size())
			throw exception("Matrix must be square!");
		for (int j = 0; j < matrix[i].size(); j++)
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
inline void Graph_matrix<T>::set_data(const int& index, const T& data)
{
	vertices[index]->data = data;
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
	cout << "Matrix:" << endl;
	cout << " ";
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(13) << i;
	}
	cout << endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << i;
		for (int j = 0; j < matrix.size(); j++)
		{
			if (matrix[i][j])
			{
				cout << " " << setw(12) << matrix[i][j]->data;
			}
			else
			{
				cout << setw(13) << "0";
			}
		}
		cout << endl;
	}
	cout << "Vertices:" << endl;
	for (int i = 0; i < vertices.size(); i++)
	{
		cout << i << ":" << vertices[i]->data << " ";
	}
	cout << endl;
}

template<typename T>
inline void Graph_matrix<T>::go_throw_graph(vector<vector<pair<Edge<T>*, Node<T>*>>>& result, Node<T>* current, Node<T>* end, vector<pair<Edge<T>*, Node<T>*>> passed_vertex)
{
	for (auto& a : matrix[current->index])
	{
		if (a && a->destination->index != current->index)
		{
			if (a->destination == end)
			{
				passed_vertex.push_back({ a, a->destination });
				result.push_back(passed_vertex);
				passed_vertex.pop_back();
			}
			else
			{
				if (!(find(passed_vertex.begin(), passed_vertex.end(), make_pair( a, a->destination )) != passed_vertex.end()))
				{
					passed_vertex.push_back({ a, a->destination });
					go_throw_graph(result, a->destination, end, passed_vertex);
					passed_vertex.pop_back();
				}
			}

		}
	}
}


template<typename T>
vector<pair<Edge<T>*, Node<T>*>> Graph_matrix<T>::find_paths(const int& from_index, const int& to_index)
{
	vector<vector<pair<Edge<T>*, Node<T>*>>> paths;
	go_throw_graph(paths, vertices[from_index], vertices[to_index]);
	if (paths.size())
	{
		T* shortest_lenght = new T();
		vector<pair<Edge<T>*, Node<T>*>> shortest_path = paths[0];
		for (const auto& a : paths[0])
		{
			*shortest_lenght += a.first->data;
		}
		for (int i = 1; i < paths.size(); i++)
		{
			T* current_length = new T();
			for (auto& a : paths[i])
			{
				*current_length += a.first->data;
			}
			if (*current_length < *shortest_lenght)
			{
				*shortest_lenght = *current_length;
				shortest_path = paths[i];
			}
			delete current_length;
		}
		delete shortest_lenght;
		return shortest_path;
	}
	else
	{
		return {};
	}
}

template<typename T>
inline void Graph_matrix<T>::go_throw_all(Node<T>* current, set<Node<T>*>& passed_vertex)
{
	for (auto& a : matrix[current->index])
	{
		if (a)
		{
			passed_vertex.insert(a->destination);
			if (!(passed_vertex.find(a->destination) != passed_vertex.end()))
			{
				go_throw_all(a->destination, passed_vertex);
			}
		}
	}
}

template<typename T>
inline bool Graph_matrix<T>::is_connected()
{
	if (matrix.size())
	{
		set<Node<T>*> passed_nodes;
		go_throw_all(vertices[0], passed_nodes);
		if (passed_nodes.size() == vertices.size())
			return true;
	}
	return false;
}