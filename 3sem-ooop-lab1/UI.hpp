#pragma once
#include "graphs/Graph_list.hpp"
#include "graphs/Graph_matrix.hpp"
#include "dice/Dice_set.hpp"
#include <vector>

class UI
{
public:
	void graph_matrix_int();
	void graph_matrix_double();
	void graph_matrix_string();
	void graph_matrix_vector_int();
	void graph_list_int();
	void graph_list_double();
	void graph_list_string();
	void graph_list_vector_int();
	void graph_list_dice_int();
};
