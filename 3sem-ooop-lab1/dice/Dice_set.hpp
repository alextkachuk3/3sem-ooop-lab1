#pragma once
#include "Dice.hpp"
#include <map>

using namespace std;

template <typename T>
class Dice_set
{
public:
	~Dice_set();
	void add(vector<pair<T, int>> sides);
	vector<pair<vector<T>, float>> combinations();
	map<T, float> combinations_chances_sums();
	pair< map<T, float>, map<T, float>> compare_with_other_dice_set_combination_chances_sums(Dice_set& other_set);
private:
	void calculate_comb(vector<pair<vector<T>, float>>& result, int current = 0, float cur_chance = 1.0, vector<T> current_combination = {});
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
inline void Dice_set<T>::calculate_comb(vector<pair<vector<T>, float>>& result, int current, float cur_chance, vector<T> current_combination)
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
inline vector<pair<vector<T>, float>> Dice_set<T>::combinations()
{
	vector<pair<vector<T>, float>> result;
	calculate_comb(result);
	return result;
}

template<typename T>
inline map<T, float> Dice_set<T>::combinations_chances_sums()
{
	map<T, float> result;
	
	auto combs = this->combinations();
	for (auto& a : combs)
	{
		T cur_sum = 0;
		for (auto& b : a.first)
		{
			cur_sum += b;
		}
		result[cur_sum] += a.second;
	}
	return result;
}

template<typename T>
inline pair<map<T, float>, map<T, float>> Dice_set<T>::compare_with_other_dice_set_combination_chances_sums(Dice_set& other_set)
{
	auto first_sums = this->combinations_chances_sums();
	auto second_sums = other_set.combinations_chances_sums();
	for (auto& a : first_sums)
	{
		second_sums[a.first];
	}
	for (auto& a : second_sums)
	{
		first_sums[a.first];
	}
	return { first_sums, second_sums };
}
