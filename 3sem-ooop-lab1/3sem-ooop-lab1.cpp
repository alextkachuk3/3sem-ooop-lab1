#include "graph.h"
#include "graph.cpp"

int main()
{
	graph<int> test;
	test.add_top(30);
	test.add_top(10);
	test.connect(0, 1, 1337);
	return 0;
}