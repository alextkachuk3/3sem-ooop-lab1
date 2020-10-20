#pragma once
#include <iostream>
#include <set>
#include "../Dice/dice.hpp"

class dice_menu
{
public:
	template<typename T>
	void add_dice(dice<T>& Dice, T begin_numeration);
	template<typename T>
	void change_chance(dice<T>& Dice);
	template<typename T>
	void print_dice(dice<T>& Dice);
	template<typename T>
	void print_set_sum_of_combination(dice<T>& Dice);
};

template<typename T>
void dice_menu::add_dice(dice<T>& Dice, T begin_numeration)
{
	int count;
	cout << "Enter count of sides:";
	cin >> count;
	double chance_sum = 0.0;
	double cur_chance;
	T cur_name = begin_numeration;
	map<T, double> new_dice;
	for (int i = 0; i < count; i++)
	{
		cout << "Enter chance for side" << cur_name << ":";
		cin >> cur_chance;
		chance_sum += cur_chance;
		new_dice[cur_name] = cur_chance;
		cur_name += 1;
	}
	if (chance_sum > 1)
		throw exception("Invalid chances");
	cout << "1.Add to first dice set" << endl << "2.Add to second dice set" << endl;
	int sel;
	cin >> sel;
	switch (sel)
	{
	case 1:Dice.add_first_dice(new_dice);
		break;
	case 2:Dice.add_second_dice(new_dice);
		break;
	default:cout << "Wrong operation";		
		return;
	}
}

template<typename T>
void dice_menu::change_chance(dice<T>& Dice)
{
	int dice_index;
	cout << "Enter dice index:";
	cin >> dice_index;
	T side_name;
	cout << "Enter name of side:";
	cin >> side_name;
	double new_chance;
	cout << "Enter new chance:";
	cin >> new_chance;
	cout << "1.Change in first dice set" << endl << "2.Change in second dice set" << endl;
	int sel;
	cin >> sel;
	switch (sel)
	{
	case 1:Dice.change_first_dice_chance(dice_index, side_name, new_chance);
		break;
	case 2:Dice.change_second_dice_chance(dice_index, side_name, new_chance);
		break;
	default:cout << "Wrong operation" << endl;
		return;
	}
}

template<typename T>
void dice_menu::print_dice(dice<T>& Dice)
{
	Dice.print_all_dice();
}

template<typename T>
void dice_menu::print_set_sum_of_combination(dice<T>& Dice)
{
	Dice.print_sum_chance_of_combination();
}
