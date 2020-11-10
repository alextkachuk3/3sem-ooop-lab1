/*! Dice_side class file
* \file dice/Dice_side.hpp
* \author Alex Tkachuk
* \version 1.0 11/10/20
*/
#pragma once

template <typename T>
class Dice_side
{
public:
	/*! Create dice side with given side name
	* \param[in] side_index name for new side
	*/
	Dice_side(T side_index);
	/*Name of dice side*/
	T side_index;
};

template<typename T>
inline Dice_side<T>::Dice_side(T side_index)
{
	this->side_index = side_index;
}
