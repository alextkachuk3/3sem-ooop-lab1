/*! Graph_list class file
* \file graphs/Graph_list.hpp
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


/*Graph_list class*/
template<typename T>
class Graph_list
{
public:
	Graph_list() = default;
	Graph_list(const vector<vector<pair<int, T>>>& list);
	~Graph_list();
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
	/*Print graph matrix and data of all nodes*/
	void print();
	/*!Find path from first to second node
	* \param[in] from_index from node with this index we will try find path
	* \param[in] to_index node to which we try to find path
	*/
	int find_distanse(const int& from_index, const int& to_index);
	/*If graph is connectiveted return true, else false*/
	bool is_connected();
private:
	void go_throw_graph(vector<set<Node<T>*>> result, set<Node<T>*> passed_vertex, Node<T>* current, Node<T>* end);
	vector<set<Edge<T>*>> list;
	/*Containe all graph node*/
	vector<Node<T>*> vertices;
};

template<typename T>
inline Graph_list<T>::~Graph_list()
{
	for (auto& a : list)
	{
		for (auto& b : a)
		{
			delete b;
		}
	}
	for (auto& a : vertices)
	{
		delete a;
	}
}

template<typename T>
inline Graph_list<T>::Graph_list(const vector<vector<pair<int, T>>>& list)
{
	for (auto& a : list)
	{
		Node<T>* new_node = new Node<T>;
		vertices.push_back(new_node);
		list.push_back({});
	}
	for (int i = 0; i < list.size; i++)
	{
		for (int j = 0; j < list[i].size; j++)
		{
			this->connect(i, list[i][j].first, list[i][j].second);
		}
	}
}

template<typename T>
inline void Graph_list<T>::insert(const T& data)
{
	Node<T>* new_node = new Node<T>(vertices.size(), data);
	vertices.push_back(new_node);
	list.push_back({});
}

template<typename T>
inline void Graph_list<T>::erase(const int& index)
{
	for (int i = 0; i < list.size(); i++)
	{
		for (auto &b: list[i])
		{
			if (b->destination == vertices[index])
			{
				auto temp = b;
				list[i].erase(b);
				delete temp;
				break;
			}
		}
	}
	auto temp = vertices[index];
	vertices.erase(vertices.begin() + index);
	delete temp;
	list.erase(list.begin() + index);
}

template<typename T>
inline void Graph_list<T>::connect(const int& from_index, const int& to_index, const T& data)
{
	for (auto& a : list[from_index])
	{
		if (a->destination == vertices[to_index])
		{
			cout << "This vertices already connected!" << endl;
			return;
		}
	}
	Edge<T>* new_edge = new Edge<T>(vertices[to_index], data);
	list[from_index].insert(new_edge);
}

template<typename T>
inline void Graph_list<T>::disconect(const int& from_index, const int& to_index)
{
	for (auto& a : list[from_index])
	{
		if (a->destiantion == vertices[to_index])
		{
			auto temp = a;
			list[from_index].erase(a);
			delete temp;
			return;
		}
	}
	cout << "This vertices are not connected!" << endl;
}

template<typename T>
inline void Graph_list<T>::print()
{
	for (size_t i = 0; i < vertices.size(); i++)
	{
		cout << "#" << i <<" '" << vertices[i]->data <<"'" << " connected to: ";
		for (const auto& a : list[i])
		{
			cout << a->destination->index << " '" << vertices[a->destination->index]->data <<"'" << " (" << a->data << "), ";
		}
		cout << endl;
	}
}


template<typename T>
inline int Graph_list<T>::find_distanse(const int& from_index, const int& to_index)
{
	return 0;
}

template<typename T>
inline bool Graph_list<T>::is_connected()
{
	if (list.size())
	{
		set<Node<T>*> passed_nodes;
		for (auto& a : list)
		{
			passed_nodes.insert(a->destination);
		}
		if (passed_nodes.size() = vertices.size())
			return true;
	}
	return false;
}