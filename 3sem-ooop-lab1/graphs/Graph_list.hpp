#pragma once
#include <vector>
#include <set>
#include <iostream>
#include "Node.hpp"
#include "Edge.hpp"
#include "../ostream_vector_operator.hpp"

using namespace std;

template<typename T>
class Graph_list
{
public:
	~Graph_list();
	void insert(const T& data);
	void erase(const int& index);
	void connect(const int& from_index, const int& to_index, const T& data);
	void disconect(const int& from_index, const int& to_index);
	void print();
	vector<Node<T>*> get_vertices();
private:
	vector<set<Edge<T>*>> list;
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
inline vector<Node<T>*> Graph_list<T>::get_vertices()
{
	return vertices;
}
