#pragma once

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
	void connect_top(graph<T>& Graph);
	template<typename T>
	void delete_top(graph<T>& Graph);
};

