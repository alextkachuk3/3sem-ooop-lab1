#pragma once

template <typename T>
class Node
{
public:
	Node() = default;
	Node(const int& index, const T& data);
	int index;
	T data;
	friend bool operator<(const Node<T>& lft, const Node<T>& rgt);
};

template <typename T>
bool operator<(const Node<T>& lft, const Node<T>& rgt)
{
	return lft.index < rgt.index;
}

template<typename T>
inline Node<T>::Node(const int& index, const T& data)
{
	this->index = index;
	this->data = data;
}
