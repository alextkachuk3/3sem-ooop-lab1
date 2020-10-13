#include "graph.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

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
	result += " }"
	out << result;
	return out;
}


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
inline void graph<T>::add_top(const T& data)
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
* This function connect two tops of the graph.
\param first_index Index of first top in the graph which we want connect.
\param second_index Index of second top in the graph which we want connect.
\param connection_weight Weight of new connection
*/
template<typename T>
void graph<T>::connect(const int& first_index, const int& second_index, const int& connection_weight)
{
	graph_map[first_index].links[&graph_map[second_index]] = connection_weight;
	graph_map[second_index].links[&graph_map[first_index]] = connection_weight;
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
		cout<<"#" << a.first <<": " << a.second.data << " connected to ";
		for (const auto& b : a.second.links)
		{
			cout << b.first->data << " (" << b.second << ") ";
		}
		cout << endl;
	}
}

template<typename T>
int graph<T>::distance(const int& index_from, const int& index_to)
{
	
	return 1;
}

template<typename T>
bool graph<T>::check_connectivity()
{
	return false;
}
