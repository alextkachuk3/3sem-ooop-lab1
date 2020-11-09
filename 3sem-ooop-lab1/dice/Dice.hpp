#pragma once
#include "Dice_side.hpp"

template <typename T>
class Dice
{
public:
	~Dice();
	Dice() = default;
	Dice(vector<pair<T, int>> sides);
	vector<Dice_side<T>*> sides;
	double chance;
};

template<typename T>
inline Dice<T>::~Dice()
{
	for (auto& a : sides)
	{
		if (a)
		{
			auto temp = a;
			a = nullptr;
			delete a;
		}
	}
}

template<typename T>
inline Dice<T>::Dice(vector<pair<T, int>> sides)
{
	for (auto& a : sides)
	{
		Dice_side<T>* new_side = new Dice_side<T>(a.first);
		for (int i = 0; i < a.second; i++)
		{
			this->sides.push_back(new_side);
		}
	}
	this->chance = 1.0 / this->sides.size();
}
