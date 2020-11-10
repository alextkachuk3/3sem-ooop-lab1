/*! vector << operator file
* \file ostream_vector_operator.hpp
* \author Alex Tkachuk
* \version 1.0 11/10/20
*/
#pragma once
#include<vector>
#include<iostream>

using namespace std;

/*Defines << ostream operator for vector*/
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