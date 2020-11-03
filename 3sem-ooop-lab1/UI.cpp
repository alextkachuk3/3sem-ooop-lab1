#include "UI.hpp"

void UI::graph_matrix_int()
{
	system("cls");
	Graph_matrix<int>* graph_matrix = new Graph_matrix<int>;
	delete graph_matrix;
}

void UI::graph_matrix_double()
{
	system("cls");
	Graph_matrix<double>* graph_matrix = new Graph_matrix<double>;

	graph_matrix->insert(1.0);
	graph_matrix->insert(4.0);
	graph_matrix->insert(16.4);
	graph_matrix->insert(13.2);
	graph_matrix->insert(11.2);
	graph_matrix->connect(3, 2, 3.2);

	graph_matrix->print();

	graph_matrix->erase(2);

	graph_matrix->print();

	delete graph_matrix;
}

void UI::graph_matrix_string()
{
	system("cls");
	Graph_matrix<string>* graph_matrix = new Graph_matrix<string>;

	graph_matrix->insert("hello");
	graph_matrix->insert("meow");
	graph_matrix->insert("test");
	graph_matrix->insert("cat");
	graph_matrix->insert("cow");
	graph_matrix->connect(3, 2, "connect 3 2");

	graph_matrix->print();

	graph_matrix->erase(2);

	graph_matrix->print();

	delete graph_matrix;
}

void UI::graph_matrix_vector_int()
{
	system("cls");
	Graph_matrix<vector<int>>* graph_matrix = new Graph_matrix<vector<int>>;
	graph_matrix->insert({ 3, 4 });
	graph_matrix->insert({ 5, 6 });
	graph_matrix->insert({ 7, 8 });

	graph_matrix->connect(0, 1, { 101, 102 });
	graph_matrix->connect(1, 2, { 101, 102 });
	graph_matrix->connect(2, 1, { 101, 102 });

	graph_matrix->erase(1);

	graph_matrix->print();

	delete graph_matrix;
}

void UI::graph_list_int()
{
	system("cls");
	Graph_list<int>* graph_list = new Graph_list<int>;

	graph_list->insert(1);
	graph_list->insert(4);
	graph_list->insert(16);
	graph_list->insert(13);
	graph_list->insert(11);
	graph_list->connect(3, 2, 32);

	graph_list->print();

	graph_list->erase(2);

	graph_list->print();

	delete graph_list;
}

void UI::graph_list_double()
{
	system("cls");
	Graph_list<double>* graph_list = new Graph_list<double>;

	graph_list->insert(1.0);
	graph_list->insert(4.0);
	graph_list->insert(16.4);
	graph_list->insert(13.2);
	graph_list->insert(11.2);
	graph_list->connect(3, 2, 3.2);

	graph_list->print();

	graph_list->erase(2);

	graph_list->print();

	delete graph_list;
}

void UI::graph_list_string()
{
	system("cls");
	Graph_list<string>* graph_list = new Graph_list<string>;

	graph_list->insert("null");
	graph_list->insert("first");
	graph_list->insert("second");
	graph_list->insert("third");
	graph_list->insert("fourth");
	graph_list->insert("fifth");
	graph_list->insert("sixth");
	graph_list->insert("seventh");
	graph_list->insert("eight");
	graph_list->insert("nineth");
	graph_list->insert("tenth");

	graph_list->connect(0, 2, "con1");
	graph_list->connect(1, 2, "con2");
	graph_list->connect(2, 4, "con3");
	graph_list->connect(2, 3, "con4");
	graph_list->connect(3, 5, "con5");
	graph_list->connect(4, 5, "con6");
	graph_list->connect(6, 5, "con7");
	graph_list->connect(7, 8, "con8");


	graph_list->print();

	graph_list->erase(1);
	graph_list->erase(5);

	graph_list->print();

	delete graph_list;
}

void UI::graph_list_vector_int()
{
	system("cls");
	Graph_list<vector<int>>* graph_list = new Graph_list<vector<int>>;
	graph_list->insert({ 3, 4 });
	graph_list->insert({ 5, 6 });
	graph_list->insert({ 7, 8 });

	graph_list->connect(0, 1, { 101, 102 });
	graph_list->connect(1, 2, { 101, 102 });
	graph_list->connect(2, 1, { 101, 102 });

	graph_list->erase(1);

	graph_list->print();

	delete graph_list;
}


void UI::graph_dice_list_num()
{
	system("cls");



	Graph_list<Dice<int>> graph_dice_first;
	Graph_list<Dice<int>> graph_dice_second;

	Work_with_graph_dice work_with_graph;

	
	graph_dice_first.insert(Dice<int>({ 0.1, 0.3, 0.1, 0.5 }));

	graph_dice_first.insert(Dice<int>({ 0.5, 0.5 }));

	graph_dice_first.insert(Dice<int>({0.1, 0.1, 0.2, 0.1, 0.1, 0.4 }));

	graph_dice_second.insert(Dice<int>({ 0.1, 0.1,0.1,0.1,0.1,0.1,0.1,0.3 }));

	graph_dice_second.insert(Dice<int>({ 0.4, 0.6 }));

	graph_dice_second.insert(Dice<int>({ 0.2, 0.1, 0.3, 0.4 }));

	auto sum_comb = work_with_graph.get_comb_sum(graph_dice_first);

	for (auto& a : sum_comb)
	{
		cout << a.first << " " << a.second << endl;
	}

	sum_comb = work_with_graph.get_comb_sum(graph_dice_second);

	for (auto& a : sum_comb)
	{
		cout << a.first << " " << a.second << endl;
	}
}

void UI::graph_dice_matrix_char()
{
	system("cls");
	Graph_matrix<Dice<char>> graph_dice_first;
	Graph_matrix<Dice<char>> graph_dice_second;

	Work_with_graph_dice work_with_graph;

	graph_dice_first.insert(Dice<char>({ 0, 0.3, 0.1, 0.5 }));

	graph_dice_first.insert(Dice<char>({ 0.5, 0.5 }));

	graph_dice_first.insert(Dice<char>({ 0.1, 0.1, 0.2, 0.1, 0.1, 0.4 }));

	graph_dice_second.insert(Dice<char>({ 0.1, 0.1,0.1,0.1,0.1,0.1,0.1,0.3 }));

	graph_dice_second.insert(Dice<char>({ 0.4, 0.6 }));

	graph_dice_second.insert(Dice<char>({ 0.2, 0.1, 0.3, 0.4 }));

	auto comb = work_with_graph.get_comb(graph_dice_first);

	for (auto& a : comb)
	{
		for (auto& b : a.first)
		{
			cout << b << " ";
		}
		cout << a.second << endl;
	}
}