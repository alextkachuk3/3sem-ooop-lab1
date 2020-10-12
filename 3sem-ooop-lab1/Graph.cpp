#include "graph.h"

using namespace std;

template<typename T>
void graph<T>::clean()
{
	graph_map.clear();
}

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
	}
}

template<typename T>
int graph<T>::size() const
{
	return graph_map.size();
}

template<typename T>
void graph<T>::connect(const int& first_index, const int& second_index, const int& connection_weight)
{
	graph_map[first_index].links[&graph_map[second_index]] = connection_weight;
	graph_map[second_index].links[&graph_map[first_index]] = connection_weight;
}

template<typename T>
void graph<T>::adj_matrix(const vector<vector<int>>& adjacency_matrix)
{

}

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

template<typename T>
void graph<T>::del_top(const int& index)
{

}
