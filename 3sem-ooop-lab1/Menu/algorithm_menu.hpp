#pragma once
#include <iostream>

using namespace std;

class algorithm_menu
{
public:
	template<typename T>
	void find_distance(graph<T>& Graph);
};

template<typename T>
void algorithm_menu::find_distance(graph<T>& Graph)
{
	system("cls");
	Graph.distance();
}