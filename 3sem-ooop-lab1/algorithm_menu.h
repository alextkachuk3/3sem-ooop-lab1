#pragma once
#include <iostream>

template<typename T>
class graph;

class algorithm_menu
{
public:
	template<typename T>
	void find_distance(graph<T>& Graph);
	template<typename T>
	void is_connectivited(graph<T>& Graph);
};

