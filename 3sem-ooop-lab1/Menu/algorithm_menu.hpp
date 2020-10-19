#pragma once
#include <iostream>

using namespace std;

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

template<typename T>
void algorithm_menu::find_distance(graph<T>& Graph)
{
	system("cls");
	int ind_from, ind_to;
	cout << "Enter index of top(from):";
	cin >> ind_from;
	cout << "Enter index of top(to):";
	cin >> ind_to;
	cout << Graph.distance(ind_from, ind_to);
}

template<typename T>
void algorithm_menu::is_connectivited(graph<T>& Graph)
{
	system("cls");
	if (Graph.check_connectivity())
		cout << "Graph is connectivited" << endl;
	else
		cout << "Graph is not connectivited" << endl;
}