#pragma once
#include "../Top/top.hpp"
#include <map>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

template<typename T>
class graph
{
public:
	void clear();
	void add_top(const T& data);
	int size() const;
	void double_connect(const int& first_index, const int& second_index, const int& connection_weight);
	void single_connect(const int& first_index, const int& second_index, const int& connection_weight);
	void adj_matrix(const vector<vector<int>>& adjacency_matrix);
	void adj_list(const vector<vector<int>>& adjacency_list);
	void del_top(const int& index);
	void change_top_data(const int& index, const T& data);
	void print_graph();
	void distance();
	T& operator[](const int& index);
	map<top<T>*, int>& get_top_links(const int& index);
	int get_top_links_count(const int& index);
	const map<int, top<T>>& get_graph_map();
private:
	map<int, top<T>> graph_map;
	/*!
	* In this vector we save index of deleted tops, which we will use for new tops
	*/
	vector<int> free_slots;
};

/*!
* This operator allow us to print vector
*/
template<typename T>
ostream& operator << (ostream& out, const vector<T>& vec)
{
	string result;
	result += "{ ";
	for (const auto& a : vec)
	{
		result += (a)+", ";
	}
	result.resize(result.size() - 2);
	result += " }";
	out << result;
	return out;
}

/*!
* This operator allow us to get vector from one console line(Elements must be separated by space)
*/
template<typename T>
istream& operator >> (istream& in, vector<T>& vec)
{
	stringstream sn;
	string s;
	getline(in, s);
	sn << s;
	while (sn && s.size())
	{
		T n;
		sn >> n;
		sn.ignore(1);
		vec.push_back(n);
	}
	return in;
}

/*!
* This function removes all tops from the graph.
*/
template<typename T>
void graph<T>::clear()
{
	graph_map.clear();
}

/*!
* This function add new top to the graph
\param data Data for new top
*/
template<typename T>
void graph<T>::add_top(const T& data)
{
	if (!free_slots.size())
	{
		graph_map[graph_map.size()] = data;
	}
	else
	{
		graph_map[free_slots[free_slots.size() - 1]] = data;
		free_slots.pop_back();
	}
}


/*!
* This function return current count of top in the graph.
*/
template<typename T>
int graph<T>::size() const
{
	return graph_map.size();
}

/*!
* This function connect two tops of the graph(Connect first to second and second to first).
\param first_index Index of first top in the graph which we want connect.
\param second_index Index of second top in the graph which we want connect.
\param connection_weight Weight of new connection
*/
template<typename T>
void graph<T>::double_connect(const int& first_index, const int& second_index, const int& connection_weight)
{
	graph_map[first_index].links[&graph_map[second_index]] = connection_weight;
	graph_map[second_index].links[&graph_map[first_index]] = connection_weight;
}

/*! This function connect two tops of the graph(Connect only first to second).
\param first_index Index of first top in the graph from which we want connect.
\param second_index Index of second top in the graph to which we want connect.
\param connection_weight Weight of new connection
*/
template<typename T>
void graph<T>::single_connect(const int& first_index, const int& second_index, const int& connection_weight)
{
	graph_map[first_index].links[&graph_map[second_index]] = connection_weight;
}

/*!
* This fucntion build graph by using adjacency matrix
\params adjacency_matrix Adjacency matrix which we use for building a new graph
*/
template<typename T>
void graph<T>::adj_matrix(const vector<vector<int>>& adjacency_matrix)
{
	graph_map.clear();
	size_t count = adjacency_matrix.size();
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (adjacency_matrix[i][j])
			{
				graph_map[i].links[&graph_map[j]] = 1;
			}
		}
	}
}


/*!
* This fucntion build graph by using adjacency list
\params adjacency_list Adjacency list which we use for building a new graph
\throw exception if get wrong adjacency list
*/
template<typename T>
void graph<T>::adj_list(const vector<vector<int>>& adjacency_list)
{
	graph_map.clear();
	size_t count = adjacency_list.size();
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < adjacency_list[i].size(); j++)
		{
			if (adjacency_list[i][j] >= count)
				throw exception("Invalid list");
			graph_map[i].links[&graph_map[adjacency_list[i][j]]] = 1;
		}
	}
}

/*!
* This function delete top of graph
\param index The index of removable top
*/
template<typename T>
void graph<T>::del_top(const int& index)
{
	if (!graph_map.count(index))
	{
		throw exception("There is no such top!");
	}
	for (auto& a : graph_map[index].links)
	{
		a.first->links.erase(&graph_map[index]);
	}
	graph_map.erase(index);
	free_slots.push_back(index);
}

/*!
* This function change data of top
 \param index The index of the top whose data we want to change
 \param data New data for the top
*/
template<typename T>
void graph<T>::change_top_data(const int& index, const T& data)
{
	graph_map[index].data = data;
}

/*!
* Firstly prints the index of the top, after his data and then the data of the connected topand the weight of the connection.
*/
template<typename T>
void graph<T>::print_graph()
{
	for (const auto& a : graph_map)
	{
		cout << "#" << a.first << ": " << a.second.data << " connected to ";
		for (const auto& b : a.second.links)
		{
			cout << b.first->data << " (" << b.second << ") ";
		}
		cout << endl;
	}
}

/*!
* Print shortest path between tops and shortes path
*/
template<typename T>
void graph<T>::distance()
{
	int SIZE = graph_map.size();
	int** a = new int* [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		a[i] = new int[SIZE];
		for (int j = 0; j < SIZE; j++)
		{
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (auto& b : graph_map[i].links)
		{
			for (auto& c : graph_map)
			{
				if (b.first->data == c.second.data)
				{
					a[i][c.first] = b.second;
				}
			}
		}
	}
	int* d = new int[SIZE];
	int* v = new int[SIZE];
	int temp, minindex, min;
	int begin_index = 0;
	for (int i = 0; i < SIZE; i++)
	{
		d[i] = 10000;
		v[i] = 1;
	}
	d[begin_index] = 0;
	do {
		minindex = 10000;
		min = 10000;
		for (int i = 0; i < SIZE; i++)
		{
			if ((v[i] == 1) && (d[i] < min))
			{
				min = d[i];
				minindex = i;
			}
		}
		if (minindex != 10000)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (a[minindex][i] > 0)
				{
					temp = min + a[minindex][i];
					if (temp < d[i])
					{
						d[i] = temp;
					}
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 10000);
	cout << "Shortes path to tops:" << endl;
	for (int i = 0; i < SIZE; i++)
		cout << d[i];
	int* ver = new int[SIZE];
	int end = 4;
	ver[0] = end + 1;
	int k = 1;
	int weight = d[end];

	while (end != begin_index)
	{
		for (int i = 0; i < SIZE; i++) 
			if (a[i][end] != 0)
			{
				int temp = weight - a[i][end];
				if (temp == d[i])
				{
					weight = temp;
					end = i;
					ver[k] = i + 1;
					k++;
				}
			}
	}
	cout << endl << "Shortes path:" << endl;
	for (int i = k - 1; i >= 0; i--)
		cout << ver[i] << " ";
	cout << endl;
	delete ver;
	delete d;
	delete v;
	for (int i = 0; i < SIZE; i++)
		delete [] a[i];
	delete [] a;
}

/*!
* This operator return top data
*/
template<typename T>
T& graph<T>::operator[](const int& index)
{
	return graph_map[index].data;
}

/*
* Return count of connnection from the graph
*/
template<typename T>
int graph<T>::get_top_links_count(const int& index)
{
	return this->graph_map.at(index).links.size();
}

/*
* Return map struct of graph
*/
template<typename T>
const map<int, top<T>>& graph<T>::get_graph_map()
{
	return graph_map;
}
