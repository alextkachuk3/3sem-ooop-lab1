#pragma once
#include <map>
#include "Dice.hpp"
#include "../graphs/Graph_matrix.hpp"
#include "../graphs/Node.hpp"
#include "../graphs/Graph_list.hpp"


class Work_with_graph_dice
{
public:
	map<int, double> get_comb(Graph_list<Dice<int>>& graph_dice);
	map<int, double> get_comb(Graph_matrix<Dice<char>>& graph_dice);
private:
	void get_all_comb(vector<pair<vector<int>, double>>& comb, pair<vector<int>, double>& current, int pos, vector<Node<Dice<int>>*> dices, int length);
};