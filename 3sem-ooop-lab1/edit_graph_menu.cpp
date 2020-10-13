#include "edit_graph_menu.h"
#include <iostream>

using namespace std;

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
void edit_graph_menu::connect_top(graph<T>& Graph)
{
	int first, second, weight;
	cout << "Enter number of first top:";
	cin >> first;
	cout << "Enter number of second top";
	cin >> second;
	cout << "Enter weight of connection:";
	cin >> weight;
	Graph.connect(first, second, weight);
}

template<typename T>
void edit_graph_menu::delete_top(graph<T>& Graph)
{
	int num_t;
	cout << "Enter number of top:";
	cin >> num_t;
	Graph.del_top(num_t);
}
