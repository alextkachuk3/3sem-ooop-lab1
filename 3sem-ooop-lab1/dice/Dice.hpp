#pragma once
#include "Dice_side.hpp"

template <typename T>
class Dice
{
	vector<Dice_side<T>> sides;
	double chance;
};