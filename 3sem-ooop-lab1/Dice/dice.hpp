#pragma once
#include <utility>
#include <map>

using namespace std;

template<typename T>
class graph;

template<typename T>
class dice
{
private:
	graph<map<T, double>> first_dice_set_graph;
	graph<map<T, double>> second_dice_set_graph;
public:
	void add_first_dice(map<T, double>& new_dice);
	void add_second_dice(map<T, double>& new_dice);
	void change_first_dice_chance(int dice_index, T side_name, double chance);
	void change_second_dice_chance(int dice_index, T side_name, double chance);
	void print_all_dice();
	friend class dice_menu;
};

template<typename T>
void dice<T>::add_first_dice(map<T, double>& new_dice)
{
	first_dice_set_graph.add_top(new_dice);
}

template<typename T>
void dice<T>::add_second_dice(map<T, double>& new_dice)
{
	second_dice_set_graph.add_top(new_dice);
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

template<typename T>
void dice<T>::print_all_dice()
{
	cout << "First set:" << endl;
	for (const auto& a : first_dice_set_graph)
	{
		a.first;
	}
}
