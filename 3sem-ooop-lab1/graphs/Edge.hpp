#pragma once
#include "Node.hpp"

template<typename T>
class Edge
{
	T data;
	Node* first_node;
	Node* second_node;
};