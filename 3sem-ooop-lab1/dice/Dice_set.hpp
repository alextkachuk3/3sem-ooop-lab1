#pragma once
#include "Dice.hpp"

using namespace std;

template <typename T>
class Dice_set
{
public:
	~Dice_set();
	void add(vector<pair<T, int>> sides);
	vector<pair<vector<T>, double>> combinations();
	void combinations_chances_sums();
	void compare_with_other_dice_set_combination_chances_sums(Dice_set& other_set);
private:
	void calculate_comb(vector<pair<vector<T>, double>>& result, int current = 0, double cur_chance = 1.0, vector<T> current_combination = {});
	vector<Dice<T>*> dice_set;
};

template<typename T>
inline Dice_set<T>::~Dice_set()
{
	for (auto& a : dice_set)
	{
		delete a;
	}
}

template<typename T>
inline void Dice_set<T>::add(vector<pair<T, int>> sides)
{
	Dice<T>* new_dice = new Dice<T>(sides);
	dice_set.push_back(new_dice);
}

template<typename T>
inline void Dice_set<T>::calculate_comb(vector<pair<vector<T>, double>>& result, int current, double cur_chance, vector<T> current_combination)
{
	for (auto& a : dice_set[current]->sides)
	{
		if (current == dice_set.size() - 1)
		{
			current_combination.push_back(a->side_index);
			result.push_back({ current_combination, cur_chance * dice_set[current]->chance });
			current_combination.pop_back();
		}
		else
		{
			current_combination.push_back(a->side_index);
			calculate_comb(result, current + 1, cur_chance * dice_set[current]->chance, current_combination);
			current_combination.pop_back();
		}
	}
}

template<typename T>
inline vector<pair<vector<T>, double>> Dice_set<T>::combinations()
{
	vector<pair<vector<T>, double>> result;
	calculate_comb(result);
	return result;
}