/*! File with functions which test matrix and list graph with different rype of data.
* \file UI.hpp
* \author Alex Tkachuk
* \version 1.0 11/10/20
*/

#pragma once
#include "graphs/Graph_list.hpp"
#include "graphs/Graph_matrix.hpp"
#include "dice/Dice_set.hpp"
#include "char_dice/dice_char.hpp"
#include <vector>
#include <time.h>

class UI
{
public:

	/*! Create randon string*/
	string random_string();
	/*! Create randon vector<int>*/
	vector<int> random_vector();
	/*! Create matrix graph for int values and test its functionality*/
	void graph_matrix_int();
	/*! Create matrix graph for double values and test its functionality*/
	void graph_matrix_double();
	/*! Create matrix graph for string values and test its functionality*/
	void graph_matrix_string();
	/*! Create matrix graph for vector<int> values and its his functionality*/
	void graph_matrix_vector_int();
	/*! Create list graph for int values and test its functionality*/
	void graph_list_int();
	/*! Create list graph for double values and test its functionality*/
	void graph_list_double();
	/*! Create list graph for string values and test its functionality*/
	void graph_list_string();
	/*! Create list graph for vector<int> values and test its functionality*/
	void graph_list_vector_int();
	/*! Create list graph for Dice_set<int> values and test its functionality*/
	void graph_list_dice_int();
	/*! Create matrix graph for Dice_set<int> values and test its functionality*/
	void graph_matrix_dice_int();
	/*! Create matrix graph for Dice_set<char> values and test its functionality*/
	void graph_matrix_dice_char();
};
