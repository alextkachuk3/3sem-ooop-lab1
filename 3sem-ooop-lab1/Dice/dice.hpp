#pragma once
#include <utility>
#include <map>
#include <iostream>

using namespace std;

/*template<typename T>
class graph;*/

template<typename T>
class dice
{
private:
	graph<map<T, double>> first_dice_set_graph;
	graph<map<T, double>> second_dice_set_graph;
	void get_first_set_comb(top<T> current_top, vector<T>& cur, vector<vector<T>>&res);
	//vector<T> get_second_set_comb();
public:
	void add_first_dice(map<T, double>& new_dice);
	void add_second_dice(map<T, double>& new_dice);
	void change_first_dice_chance(int dice_index, T side_name, double chance);
	void change_second_dice_chance(int dice_index, T side_name, double chance);
	void print_all_dice();
	void print_sum_chance_of_combination();
	friend class dice_menu;
};

template<typename T>
void dice<T>::get_first_set_comb(top<T> current_top, vector<T>& cur, vector<vector<T>>& res)
{
	/*for (const auto& a : current_top.data)
	{
		if (current_top.links.size())
		{
			cur.push_back(a.first);
			get_first_set_comb(current_top.links.begin()->first, cur, res);
			cur.pop_back();
		}
		else
		{
			res.push_back(cur);
			cur.pop_back();
		}
	}*/
}

template<typename T>
void dice<T>::add_first_dice(map<T, double>& new_dice)
{
	first_dice_set_graph.add_top(new_dice);
	if (first_dice_set_graph.size() > 1)
	{
		first_dice_set_graph.single_connect(first_dice_set_graph.size() - 2, first_dice_set_graph.size() - 1, 1);
	}
}

template<typename T>
void dice<T>::add_second_dice(map<T, double>& new_dice)
{
	second_dice_set_graph.add_top(new_dice);
	if (second_dice_set_graph.size() > 1)
	{
		second_dice_set_graph.single_connect(second_dice_set_graph.size() - 2, second_dice_set_graph.size() - 1, 1);
	}
}

template<typename T>
void dice<T>::change_first_dice_chance(int dice_index, T side_name, double chance)
{
	first_dice_set_graph[dice_index][side_name] = chance;
}

template<typename T>
void dice<T>::change_second_dice_chance(int dice_index, T side_name, double chance)
{
	second_dice_set_graph[dice_index][side_name] = chance;
}


/*!
* Print first and second set of dice
*/
template<typename T>
void dice<T>::print_all_dice()
{
	cout << "First set:" << endl;
	for (auto& a : first_dice_set_graph.graph_map)
	{
		cout << "#" << a.first << ": ";
		for (auto& b : a.second.data)
		{
			cout << b.first << "(" << b.second << ") ";
		}
		cout << endl;
	}
	cout << "Second set:" << endl;
	for (auto& a : second_dice_set_graph.graph_map)
	{
		cout << "#" << a.first << ": ";
		for (auto& b : a.second.data)
		{
			cout << b.first << "(" << b.second << ") ";
		}
		cout << endl;
	}
}


template<typename T>
void dice<T>::print_sum_chance_of_combination()
{
	vector<vector<T>> comb;
	get_first_set_comb(first_dice_set_graph.graph_map[0], {}, comb);
	for (const auto& a : comb)
	{
		for (const auto& b : a)
		{
			cout << b;
		}
		cout << endl;
	}

}