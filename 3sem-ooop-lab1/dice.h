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
	graph<map<T, double>> dice_graph;
public:
	void add_dice(map<T, double>& new_dice);
	void change_chance(double chance);
	void print_all_dice();
	friend class dice_menu;
};


template<typename T>
void dice<T>::add_dice(map<T, double>& new_dice)
{
	//dice_graph.add_top(new_dice);
}
