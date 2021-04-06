#include "dice_char.hpp"

dice_char::dice_char(char c)
{
	this->c = c;
}

dice_char& operator+(const dice_char& lft, const dice_char& rgt)
{
	dice_char res(lft.c + rgt.c);
	return res;
}

dice_char& operator+=(dice_char& lft, const dice_char& rgt)
{
	lft.c = (lft.c + rgt.c - '`');
	return lft;
}

ostream& operator<<(ostream& out, const dice_char& c)
{
	out << c.c;
	return out;
}

bool operator<(const dice_char& lft, const dice_char& rgt)
{
	return lft.c < rgt.c;
}