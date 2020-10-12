#include "graph.h"

using namespace std;

template<typename T>
void graph<T>::clean()
{
	graph_map.clear();
}

template<typename T>
inline void graph<T>::add_top(T data)
{
	graph_map[graph_map.size()] = data;
}

template<typename T>
int graph<T>::size() const
{
	return graph_map.size();
}
