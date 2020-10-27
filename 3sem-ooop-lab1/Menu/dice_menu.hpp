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
	template<typename T>
	void compare_sum_of_two_comb(const int& sum, dice<T>& firstDice, dice<T>& secondDice);
	template<typename T>
	void compare_two_comb(const string& comb, dice<T>& firstDice, dice<T>& secondDice);
	template<typename T>
	void print_set_of_combination(dice<T>& Dice);
};


/*
* Get count and chances from console and add to dice graph
\param Dice dice set in which we will add new dice
\param begin_numeration Symbol or num from which we begin numberation
*/
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
		cout << "Enter chance for side " << cur_name << ":";
		cin >> cur_chance;
		chance_sum += cur_chance;
		new_dice[cur_name] = cur_chance;
		cur_name += 1;
	}
	if (chance_sum > 1)
		throw exception("Invalid chances");
	Dice.add_dice(new_dice);
}

/*
* Get dice index and new chance from console and apply it
\param Dice dice set in which we will change chance
*/
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
	case 1:Dice.change_dice_chance(dice_index, side_name, new_chance);
		break;
	default:cout << "Wrong operation" << endl;
		return;
	}
}


/*
* Print all dice in set
\param Dice dice set from which we will print dice
*/
template<typename T>
void dice_menu::print_dice(dice<T>& Dice)
{
	Dice.print();
}


/*
* Print all combination and its chance, sum of all combination and its chance
*/
template<typename T>
void dice_menu::print_set_sum_of_combination(dice<T>& Dice)
{
	map<T, double> sums;
	for (auto& a : Dice.get_all_combination_and_chance())
	{
		T cur_sum = 0;
		for (auto& b : a.first)
		{
			cout << b;
			cur_sum += b;
		}
		cout << "(" << a.second << ")" << endl;
		sums[cur_sum] += a.second;
	}
	for (auto& a : sums)
	{
		cout << "Sum:" << a.first << " Chance:" << a.second << endl;
	}
}


/*
* Print all combination and its chance
*/
template<typename T>
void dice_menu::print_set_of_combination(dice<T>& Dice)
{
	for (auto& a : Dice.get_all_combination_and_chance())
	{
		for (auto& b : a.first)
		{
			cout << b;
		}
		cout << "(" << a.second << ")" << endl;
	}
}

/*
* Compare chances of given sum from two dice sets
*/
template<typename T>
void dice_menu::compare_sum_of_two_comb(const int& sum, dice<T>& firstDice, dice<T>& secondDice)
{
	double chance1 = 0, chance2 = 0;
	for (auto& a : firstDice.get_all_combination_and_chance())
	{
		T cur_sum = 0;
		for (auto& b : a.first)
		{
			cur_sum += b;
		}
		if (cur_sum == sum)
			chance1 = a.second;
	}
	for (auto& a : secondDice.get_all_combination_and_chance())
	{
		T cur_sum = 0;
		for (auto& b : a.first)
		{
			cur_sum += b;
		}
		if (cur_sum == sum)
			chance2 = a.second;
	}
	cout << "First set chance of this sum:" << chance1 << endl << "Second set chance of this sum:" << chance2 << endl;
}


/*
* Compare chances of given combination from two dice sets
*/
template<typename T>
void dice_menu::compare_two_comb(const string& comb, dice<T>& firstDice, dice<T>& secondDice)
{
	double chance1 = 0, chance2 = 0;
	for (auto& a : firstDice.get_all_combination_and_chance())
	{
		string cur_comb;
		for (auto& b : a.first)
		{
			cur_comb += b;
		}
		if (cur_comb == comb)
			chance1 = a.second;
	}
	for (auto& a : secondDice.get_all_combination_and_chance())
	{
		string cur_comb;
		for (auto& b : a.first)
		{
			cur_comb += b;
		}
		if (cur_comb == comb)
			chance2 = a.second;
	}
	cout << "First set chance of this combination:" << chance1 << endl << "Second set chance of this combination:" << chance2 << endl;
}


