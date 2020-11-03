#pragma once
#include <map>
#include <vector>

using namespace std;

template<typename T>
class Dice
{
public:
	Dice(const vector<double>& chances);
	map<T, double> sides;
};

template<typename T>
inline Dice<T>::Dice(const vector<double>& chances)
{
	for (int i = 0; i < chances.size(); i++)
	{
		sides[i] = chances[i];
	}
}
