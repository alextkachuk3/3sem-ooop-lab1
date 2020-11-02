#pragma once
#include "Node.hpp"

template<typename T>
class Edge
{
public:
	Edge(Node<T>* destination, const T& data);
	T data;
	Node<T>* destination;
};

template<typename T>
inline Edge<T>::Edge(Node<T>* destination, const T& data)
{
	this->destination = destination;
	this->data = data;
}