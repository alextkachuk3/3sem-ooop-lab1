/*! Dice class file
* \file dice/Dice.hpp
* \author Alex Tkachuk
* \version 1.0 11/10/20
*/
#pragma once
#include <iostream>

using namespace std;

/*!Class which contain one char. Using for special char sum (a+a=b, a+b=c) */
class dice_char
{
public:
	dice_char() = default;
	dice_char(char c);
	char c;
	/*! + operator*/
	friend dice_char& operator +(dice_char& lft, const dice_char& rgt);
	/*! += operator*/
	friend dice_char& operator +=(dice_char& lft, const dice_char& rgt);
	friend ostream& operator << (ostream& out, const dice_char& c);
	friend bool operator < (const dice_char& lft, const dice_char& rgt);
};