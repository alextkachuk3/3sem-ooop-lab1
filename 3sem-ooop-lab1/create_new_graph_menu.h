#pragma once
#include "Graph.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class create_new_graph_menu
{
public:
	template<typename T>
	void empty_graph(graph<T> &Graph);
	template<typename T>
	void adjacency_matrix(graph<T>& Graph);
	template<typename T>
	void adjacency_list(graph<T>& Graph);
};

template<typename T>
void create_new_graph_menu::empty_graph(graph<T>& Graph)
{
	Graph.clear();
	system("cls");
	cout << "New matrix created!" << endl;
}

template<typename T>
void create_new_graph_menu::adjacency_matrix(graph<T>& Graph)
{
	int count_tops;
	cout << "Enter count of tops" << endl;
	cin >> count_tops;
	cout << "Enter matrix" << endl;
	vector<vector<int>> matrix(count_tops, vector<int>(count_tops));
	for (auto& a : matrix)
	{
		for (auto& b : a)
		{
			cin >> b;
		}
	}
	Graph.adj_matrix(matrix);
	system("cls");
	cout << "New matrix created!" << endl;
}

template<typename T>
void create_new_graph_menu::adjacency_list(graph<T>& Graph)
{
	int count_tops;
	cout << "Enter count of tops" << endl;
	cin >> count_tops;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	cout << "Enter list" << endl;
	vector<vector<int>> list(count_tops);
	for (int i = 0; i < count_tops; i++)
	{
		cout << "#" << i << ":";
		stringstream sn;
		string s;
		getline(cin, s);
		sn << s;
		while (sn && s.size())
		{
			int n;
			sn >> n;
			sn.ignore(1);
			list[i].push_back(n);
		}
	}
	Graph.adj_list(list);
	system("cls");
	cout << "New matrix created!" << endl;
}
