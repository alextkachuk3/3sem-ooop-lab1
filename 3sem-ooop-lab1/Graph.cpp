
#include "graph.h"

template<typename T>
inline void graph<T>::add_graph(T data)
{
	graph_map[graph_map.size()] = data;
}