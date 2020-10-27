#pragma once
#include <utility>
#include <map>
#include <iostream>

using namespace std;

template<typename T>
class dice
{
private:
	graph<map<T, double>> dice_graph;
	void get_comb(int pos, vector<T>& cur, vector<vector<T>>&combinations, double& cur_chance, vector<double>& chances);
	
public:
	void add_dice(map<T, double>& new_dice);
	void change_dice_chance(int dice_index, T side_name, double chance);
	void print();
	map<vector<T>, double> get_all_combination_and_chance();
};

/*
* Recursive function which fills vector<vector<T>> combinations by all combination and vector<double> chances by all chances
*/
template<typename T>
void dice<T>::get_comb(int pos, vector<T>& cur, vector<vector<T>>& combinations, double& cur_chance, vector<double>& chances)
{
	for(const auto& a : this->dice_graph[pos])
	{
		if (this->dice_graph.get_top_links_count(pos))
		{
			cur.push_back(a.first);
			double save_chance = cur_chance;
			cur_chance *= a.second;
			get_comb(pos + 1, cur, combinations, cur_chance, chances);
			cur_chance = save_chance;
			cur.pop_back();
		}
		else
		{
			cur.push_back(a.first);
			double save_chance = cur_chance;
			cur_chance *= a.second;
			combinations.push_back(cur);
			chances.push_back(cur_chance);
			cur_chance = save_chance;
			cur.pop_back();
		}
	}
}

/*
* Function allow add new dice
*/
template<typename T>
void dice<T>::add_dice(map<T, double>& new_dice)
{
	dice_graph.add_top(new_dice);
	if (dice_graph.size() > 1)
	{
		dice_graph.single_connect(dice_graph.size() - 2, dice_graph.size() - 1, 1);
	}
}

/*
* Fucntion allow to change side chance
*/
template<typename T>
void dice<T>::change_dice_chance(int dice_index, T side_name, double chance)
{
	dice_graph[dice_index][side_name] = chance;
}


/*!
* Print first and second set of dice
*/
template<typename T>
void dice<T>::print()
{
	for (auto& a : dice_graph.get_graph_map())
	{
		cout << "#" << a.first << ": ";
		for (auto& b : a.second.data)
		{
			cout << b.first << "(" << b.second << ") ";
		}
		cout << endl;
	}
}

/*
* function return all combination and their chance it set of dice
*/
template<typename T>
map<vector<T>, double> dice<T>::get_all_combination_and_chance()
{
	vector<vector<T>> comb;
	vector<T> empty;
	vector<double> chances;
	double start_chance = 1.0;
	get_comb(0, empty, comb, start_chance, chances);
	map<vector<T>, double> result;
	int i = 0;
	for (const auto& a : comb)
	{
		result[a] = chances[i];
		i++;
	}
	return result;
}