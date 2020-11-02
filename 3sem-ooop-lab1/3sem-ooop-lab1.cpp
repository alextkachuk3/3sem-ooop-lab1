#include "graphs/Graph_list.hpp"
#include "graphs/Graph_matrix.hpp"

int main()
{
	Graph_list<string>* graph_list = new Graph_list<string>;
	Graph_matrix<string>* graph_matrix = new Graph_matrix<string>;

	graph_matrix->add_vertex("hello");
	graph_matrix->add_vertex("meow");

	delete graph_list;
	delete graph_matrix;
	return 0;
}