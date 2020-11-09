#pragma once

template <typename T>
class Dice_side
{
public:
	Dice_side(T side_index);
	T side_index;
};

template<typename T>
inline Dice_side<T>::Dice_side(T side_index)
{
	this->side_index = side_index;
}
