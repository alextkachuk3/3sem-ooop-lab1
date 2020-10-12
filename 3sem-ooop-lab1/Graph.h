#include "top.h"
#include <map>

template<typename T>
class graph
{
public:
	void add_graph(T data);
private:
	map<int, top<T>> graph_map;
};
