#pragma once
#include "top.h"
#include <map>

using namespace std;

template<typename T>
class graph
{
public:
	void clean();
	void add_top(T data);
	int size() const;
	void del_top(const int& index);
private:
	map<int, top<T>> graph_map;
};
