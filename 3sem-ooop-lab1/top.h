#pragma once
#include <set>

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

	friend bool operator<(const Top& lft, const Top& rth)
	{
		return lft.data < rth.data;
	}
};

template<typename T>
inline top<T>::top(T data)
{
	this->data = data;
}
