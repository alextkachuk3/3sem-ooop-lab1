/*! vector << operator file
* \file ostream_vector_operator.hpp
* \author Alex Tkachuk
* \version 1.0 11/10/20
*/
#pragma once
#include <vector>
#include <iostream>

using namespace std;

/*! Defines << ostream operator for vector*/
template<typename T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << "{ ";
		for (auto& a : v)
		{
			out << a << " ";
		}
	out << "}";
	return out;
}

/*! Defines + operator for vector*/
template<typename T>
vector<T> operator+(vector<T> lft, vector<T> rgt)
{
	
	vector<T> result;
	if (lft.size() > rgt.size())
	{
		int i = 0;
		while (i < rgt.size())
		{
			int t = lft[i] + rgt[i];
			result.push_back(t);
			i++;
		}
		while (i < lft.size())
		{
			result.push_back(lft[i]);
			i++;
		}
	}
	else
	{
		int i = 0;
		while (i < lft.size())
		{
			int t = lft[i] + rgt[i];
			result.push_back(t);
			i++;
		}
		while (i < rgt.size())
		{
			result.push_back(rgt[i]);
			i++;
		}
	}
	return result;
}


template<typename T>
vector<T>& operator+=(vector<T>& lft, const vector<T>& rgh)
{
	lft = lft + rgh;
	return lft;
}
