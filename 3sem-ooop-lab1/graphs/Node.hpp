/*! Node class file
* \file graphs/Node.hpp
* \author Alex Tkachuk
* \version 1.0 11/10/20
*/
#pragma once

/*!Node class
* Contain index and data of this node
*/
template <typename T>
class Node
{
public:
	/*!Constructor
	* \param[in] index - index for new node
	* \param[in] data - data for new node
	*/
	Node(const int& index, const T& data);
	/*Node index*/
	int index;
	/*Node data*/
	T data;
};

template<typename T>
inline Node<T>::Node(const int& index, const T& data)
{
	this->index = index;
	this->data = data;
}
