#pragma once
#include "../Graph/Graph.hpp"
#include "create_new_graph_menu.hpp"
#include "edit_graph_menu.hpp"
#include "algorithm_menu.hpp"
#include "dice_menu.hpp"

class main_menu
{
public:
	void int_graph();
	void vector_string_graph();
	void dice_graph_int();
	void wrong_operation();
	void dice_graph_char();
};

