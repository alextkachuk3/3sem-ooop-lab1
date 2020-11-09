#pragma once
#include "Dice.hpp"

using namespace std;

template <typename T>
class Dice_set
{
public:
	~Dice_set();
	void add(vector<pair<T, int>> sides);
	void combinations();
	void combinations_chances_sums();
	void compare_with_other_dice_set_combination_chances_sums(Dice_set& other_set);
private:
	void calculate_comb(map<T, double> result, double cur_chance = 1.0, vector<T> current_combination = {});
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
