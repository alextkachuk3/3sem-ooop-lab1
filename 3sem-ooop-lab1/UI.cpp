#include "UI.hpp"

void UI::graph_matrix_int()
{
	system("cls");
	Graph_matrix<int>* graph_matrix = new Graph_matrix<int>({
		{rand(), rand(), rand()},
		{rand(), rand(), rand()},
		{rand(), rand(), rand()}
		});
	graph_matrix->insert(1.0);
	graph_matrix->insert(4.0);
	graph_matrix->print();
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


	auto dist = graph_matrix->find_paths(0, 2);


	for (auto& a : dist)
	{
		cout << a << "-";
	}

	cout << endl;

	graph_matrix->erase(1);

	graph_matrix->print();

	delete graph_matrix;
}

void UI::graph_list_int()
{
	system("cls");
	Graph_list<int>* graph_list = new Graph_list<int>({
		{{1, rand()}},
		{{0, rand()}, {2, rand()}},
		{}
		});

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

	cout << "Graph is connectivited " << graph_list->is_connected() << endl;

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

void UI::graph_list_dice_int()
{
	Graph_list<Dice_set<int>*>* dice_list_int_graph = new Graph_list<Dice_set<int>*>;

	Dice_set<int>* first_dice_set = new Dice_set<int>;

	Dice_set<int>* second_dice_set = new Dice_set<int>;

	Dice_set<int>* third_dice_set = new Dice_set<int>;

	first_dice_set->add({ {1,3}, {2, 4}, {3, 1} });

	first_dice_set->add({ {1,1}, {2, 1}, {3, 1}, {4, 2} });

	second_dice_set->add({ {1,3}, {2, 4}, {3, 1} });

	second_dice_set->add({ {1,1}, {2, 1}, {3, 1}, {4, 2} });

	

	auto comb = first_dice_set->combinations();

	cout << "COMBINATIONS" << endl;

	for (const auto& a : comb)
	{
		for (const auto& b : a.first)
		{
			cout << b << " ";
		}
		cout << a.second << endl;
	}
	
	cout << "SUMS" << endl;
	auto sums = first_dice_set->combinations_chances_sums();

	for (const auto& a : sums)
	{
		cout << a.first << " " << a.second << endl;
	}

	auto compare_comb = first_dice_set->compare_with_other_dice_set_combination_chances_sums(*second_dice_set);

	third_dice_set->add({ {2,3}, {3, 3} });

	dice_list_int_graph->insert(first_dice_set);

	dice_list_int_graph->insert(first_dice_set);

	dice_list_int_graph->connect(0, 1, third_dice_set);


	delete dice_list_int_graph;
}

void UI::graph_matrix_dice_char()
{
	Graph_matrix<Dice_set<char>*>* dice_list_int_graph = new Graph_matrix<Dice_set<char>*>;

	Dice_set<char>* first_dice_set = new Dice_set<char>;

	Dice_set<char>* second_dice_set = new Dice_set<char>;

	Dice_set<char>* third_dice_set = new Dice_set<char>;

	first_dice_set->add({ {'a',3}, {'b', 4}, {'c', 1} });

	first_dice_set->add({ {'a',1}, {'b', 1}, {'c', 1}, {'d', 2} });

	second_dice_set->add({ {'a',3}, {'b', 4}, {'c', 1} });

	second_dice_set->add({ {'a',1}, {'b', 1}, {'c', 1}, {'d', 2} });



	auto comb = first_dice_set->combinations();

	cout << "COMBINATIONS" << endl;

	for (const auto& a : comb)
	{
		for (const auto& b : a.first)
		{
			cout << b << " ";
		}
		cout << a.second << endl;
	}

	

	third_dice_set->add({ {'a',3}, {'b', 3} });

	dice_list_int_graph->insert(first_dice_set);

	dice_list_int_graph->insert(first_dice_set);

	dice_list_int_graph->connect(0, 1, third_dice_set);


	delete dice_list_int_graph;
}
