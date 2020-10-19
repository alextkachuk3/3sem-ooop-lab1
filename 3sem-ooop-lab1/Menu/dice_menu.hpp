#pragma once
#include <iostream>
#include <set>
#include "../Dice/dice.hpp"

class dice_menu
{
public:
	template<typename T>
	void add_dice(dice<T>& Dice);
};

template<typename T>
void dice_menu::add_dice(dice<T>& Dice)
{
	int count;
	cout << "Enter count of sides:";
	cin >> count;
	double chance_sum = 0.0;
	double cur_chance;
	T cur_name;
	map<T, double> new_dice;
	for (int i = 0; i < count; i++)
	{
		cout << "Enter name of side:";
		cin >> cur_name;
		cout << "Enter chance";
		cin >> cur_chance;
		chance_sum += cur_chance;
		new_dice[cur_name] = cur_chance;
	}
	if (chance_sum > 1)
		throw exception("Invalid chances");
	Dice.add_dice(new_dice);
}
