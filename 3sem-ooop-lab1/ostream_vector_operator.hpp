#pragma once
#include<vector>
#include<iostream>

using namespace std;

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