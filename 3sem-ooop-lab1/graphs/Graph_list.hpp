#pragma once
#include <vector>
#include <set>
#include <iostream>
#include "Node.hpp"
#include "Edge.hpp"

using namespace std;

template<typename T>
class Graph_list
{
public:
	void insert(const T& data);
	void erase(const int& index);
	void connect(const int& from_index, const int& to_index, const T& data);
	void disconect(const int& from_index, const int& to_index);
	friend ostream& operator<<(ostream& out, const Graph_list<T>& graph_list);
private:
	vector<set<Edge<T>*>> list;
	vector<Node<T>*> vertices;
};
template<typename T>
ostream& operator<<(ostream& out, const Graph_list<T>& graph_list)
{
	
	return out;
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
		if (a->destiantion == vertices[to_index])
		{
			cout << "This vertices already connected!" << endl;
			return;
		}
	}
	Edge<T>* new_edge = new Edge<T>(vertices[to_index], data);

}

template<typename T>
inline void Graph_list<T>::disconect(const int& from_index, const int& to_index)
{

}
