#pragma once
#include <set>
#include <map>

using namespace std;


/*
* Contain data and map of connected tops and weight of connections
*/
template<typename T>
class top
{
public:
	top() {};
	top(T data)
	{
		this->data = data;
	}
	map<top*, int> links;
	T data;

	friend bool operator<(const top& lft, const top& rth)
	{
		return lft.data < rth.data;
	}
};