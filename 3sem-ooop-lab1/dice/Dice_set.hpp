#pragma once
#include "Dice.hpp"

using namespace std;

template <typename T>
class Dice_set
{
	set<Dice<T>> d;
};