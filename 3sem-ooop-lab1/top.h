#pragma once
#include <set>

using namespace std;

template<typename T>
class top
{
public:
	top(T data);
	struct edge
	{
		top<T>* first_connection;
		top<T>* second_connection;
		int weight;
	};
	set<edge*> links;
	T data;

	friend bool operator<(const top& lft, const top& rth)
	{
		return lft.data < rth.data;
	}
};

template<typename T>
inline top<T>::top(T data)
{
	this->data = data;
}
