#pragma once
#include <iostream>
#include <set>
#include "dice.hpp"

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
	cin >> count;
	double chance_sum = 0.0;
	/*map<T, double> new_dice;
	for (auto& a: new_dice)
	{
		cout << "Enter name of side:";
		//cin >> a.first;
		cout << "Enter chance";
		//cin >> a.second;
		chance_sum += a.second;
	}*/
	if (chance_sum > 1)
		throw exception("Invalid chances");
	//Dice.add_dice(new_dice);
}
