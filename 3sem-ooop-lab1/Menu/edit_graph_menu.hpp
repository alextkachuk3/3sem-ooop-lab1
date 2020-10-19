#pragma once

#include <iostream>

using namespace std;

template<typename T>
class graph;

class edit_graph_menu
{
public:
	template<typename T>
	void add_top(graph<T>& Graph);
	template<typename T>
	void change_top_data(graph<T>& Graph);
	template<typename T>
	void double_connect_top(graph<T>& Graph);
	template<typename T>
	void single_connect_top(graph<T>& Graph);
	template<typename T>
	void delete_top(graph<T>& Graph);
};

template<typename T>
void edit_graph_menu::add_top(graph<T>& Graph)
{
	T data;
	cout << "Enter data:";
	cin >> data;
	Graph.add_top(data);
}

template<typename T>
void edit_graph_menu::change_top_data(graph<T>& Graph)
{
	int index;
	T new_data;
	cout << "Enter index of top:";
	cin >> index;
	cout << "Enter data:";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> new_data;
	Graph.change_top_data(index, new_data);
}

template<typename T>
void edit_graph_menu::double_connect_top(graph<T>& Graph)
{
	int first, second, weight;
	cout << "Enter number of first top:";
	cin >> first;
	cout << "Enter number of second top";
	cin >> second;
	cout << "Enter weight of connection:";
	cin >> weight;
	Graph.double_connect(first, second, weight);
}

template<typename T>
void edit_graph_menu::single_connect_top(graph<T>& Graph)
{
	int first, second, weight;
	cout << "Enter number of first top(from):";
	cin >> first;
	cout << "Enter number of second top(to)";
	cin >> second;
	cout << "Enter weight of connection:";
	cin >> weight;
	Graph.single_connect(first, second, weight);
}

template<typename T>
void edit_graph_menu::delete_top(graph<T>& Graph)
{
	int num_t;
	cout << "Enter number of top:";
	cin >> num_t;
	Graph.del_top(num_t);
}
