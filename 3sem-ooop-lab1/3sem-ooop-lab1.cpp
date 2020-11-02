#include "graphs/Graph_list.hpp"
#include "graphs/Graph_matrix.hpp"

int main()
{
	Graph_list<string>* graph_list = new Graph_list<string>;
	Graph_matrix<string>* graph_matrix = new Graph_matrix<string>;

	graph_matrix->insert("hello");
	graph_matrix->insert("meow");
	graph_matrix->insert("test");
	graph_matrix->insert("cat");
	graph_matrix->insert("cow");
	graph_matrix->connect(3, 2, "connect 3 2");
	graph_matrix->erase(2);


	graph_list->insert("null");
	graph_list->insert("first");
	graph_list->insert("second");
	graph_list->insert("third");
	graph_list->insert("fourth");
	graph_list->insert("fifth");

	graph_list->erase(1);

	delete graph_list;
	delete graph_matrix;
	return 0;
}