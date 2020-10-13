#pragma once

template<typename T>
class graph;

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

