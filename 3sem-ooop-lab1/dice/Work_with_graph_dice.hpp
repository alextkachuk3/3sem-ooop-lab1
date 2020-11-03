#pragma once
#include <map>
#include "Dice.hpp"
#include "../graphs/Graph_matrix.hpp"
#include "../graphs/Node.hpp"
#include "../graphs/Graph_list.hpp"


class Work_with_graph_dice
{
public:
	map<int, double> get_comb_sum(Graph_list<Dice<int>>& graph_dice);
	map<vector<char>, double> get_comb(Graph_matrix<Dice<char>>& graph_dice);
private:
	template <typename T>
	void get_all_comb(vector<pair<vector<T>, double>>& comb, pair<vector<T>, double>& current, int pos, vector<Node<Dice<T>>*> dices, int length);
};