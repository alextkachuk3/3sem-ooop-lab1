/*! Dice class file
* \file dice/Dice.hpp
* \author Alex Tkachuk
* \version 1.0 11/10/20
*/
#pragma once
#include "Dice_side.hpp"

/*! Dice class
*  Contain dice sides which can be repeated
*/
template <typename T>
class Dice
{
public:
	/*Destructor*/
	~Dice();
	/*Default constructor*/
	Dice() = default;
	/*!Constructor
	* \param[in] sides vector of pair where first value is side name, second value is count of repeate of this side
	*/
	Dice(vector<pair<T, int>> sides);
	/*Contain dice sides of dice*/
	vector<Dice_side<T>*> sides;
	/*Side drop chance*/
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
