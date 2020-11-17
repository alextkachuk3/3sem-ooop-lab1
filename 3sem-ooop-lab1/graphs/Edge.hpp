/*! Edge class file
* \file graphs/Edge.hpp
* \author Alex Tkachuk
* \version 1.0 11/10/20
*/
#pragma once
#include "Node.hpp"

/*!
* Edge class
*/
template<typename T>
class Edge
{
public:
	/*! Constructor
	* \param [in] destination - end point node of new edge
	* \param [in] data - data of new edge
	*/
	Edge(Node<T>* destination, const T& data);
	/*! Data which contain this edge*/
	T data;
	/*! End point of this edge*/
	Node<T>* destination;
};

template<typename T>
inline Edge<T>::Edge(Node<T>* destination, const T& data)
{
	this->destination = destination;
	this->data = data;
}