#include "Work_with_graph_dice.hpp"

//Recurice function which insert in comb all possible combination from set of dice from dices
template <typename T>
void Work_with_graph_dice::get_all_comb(vector<pair<vector<T>, double>>& comb, pair<vector<T>, double>& current ,int pos, vector<Node<Dice<T>>*> dices, int length)
{
	for (const auto& a : dices[pos]->data.sides)
	{
		current.first.push_back(a.first);
		double save_chance = current.second;
		current.second *= a.second;
		if (pos == length - 1)
		{
			comb.push_back(current);

		}
		else
		{
			get_all_comb(comb, current, pos + 1, dices, length);
		}
		current.second = save_chance;
		current.first.pop_back();
	}
}

//Get sum chances of all combination from graph_dice
map<int, double> Work_with_graph_dice::get_comb_sum(Graph_list<Dice<int>>& graph_dice)
{
	map<int, double> result;
	vector<pair<vector<int>, double>> comb;
	pair<vector<int>, double> empty_comb = { {}, 1.0 };
	vector<Node<Dice<int>>*> vertices = graph_dice.get_vertices();
	get_all_comb(comb, empty_comb, 0, vertices, vertices.size());
	for (auto& a : comb)
	{
		int cur_sum = 0;
		for (auto& b : a.first)
		{
			cur_sum += b;
		}
		result[cur_sum] += a.second;
	}
	return result;
};

//Get all combination and their chance from dice_graph
map<vector<char>, double> Work_with_graph_dice::get_comb(Graph_matrix<Dice<char>>& graph_dice)
{
	map<vector<char>, double> result;
	vector<pair<vector<char>, double>> comb;
	pair<vector<char>, double> empty_comb = { {}, 1.0 };
	vector<Node<Dice<char>>*> vertices = graph_dice.get_vertices();
	get_all_comb<char>(comb, empty_comb, 0, vertices, vertices.size());;
	return result;
}
