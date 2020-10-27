#include "Menu\main_menu.hpp"

using namespace std;


/**
* Here we create graph which tops contain int and use function on them using console
*/
void main_menu::int_graph()
{
	graph<int> Graph;
	while (true)
	{
		int op1 = 0, op2 = 0;
		cout << "1.Create new graph" << endl << "2.Edit graph" << endl << "3.Print graph" << endl << "4.Algorithms" << endl << "5.Back" << endl;
		cin >> op1;
		switch (op1)
		{
		case 1:
		{
			system("cls");
			create_new_graph_menu my_create_new_graph_menu;
			int op2;
			while (true)
			{
				cout << "1.Empty graph" << endl << "2.Use adjacency matrix" << endl << "3.Use adjacency list" << endl << "4.Back" << endl;
				cin >> op2;
				switch (op2)
				{
				case 1: my_create_new_graph_menu.empty_graph(Graph);
					break;
				case 2: my_create_new_graph_menu.adjacency_matrix(Graph);
					break;
				case 3: my_create_new_graph_menu.adjacency_list(Graph);
					break;
				case 4:	system("cls");
					break;
				default:this->wrong_operation();
				}
				break;
			}
			break;
		}
		case 2:
		{
			system("cls");
			edit_graph_menu my_edit_graph_menu;
			while (op2 != 4)
			{
				cout << "1.Add top" << endl << "2.Change top data" << endl << "3.Double connect top" << endl << "4.Single connect top" << endl << "5.Delete top" << endl << "6.Back" << endl;
				cin >> op2;
				switch (op2)
				{
				case 1:my_edit_graph_menu.add_top(Graph);
					break;
				case 2:my_edit_graph_menu.change_top_data(Graph);
					break;
				case 3:my_edit_graph_menu.double_connect_top(Graph);
					break;
				case 4:my_edit_graph_menu.single_connect_top(Graph);
					break;
				case 5:my_edit_graph_menu.delete_top(Graph);
					break;
				case 6:system("cls");
					break;
				default:this->wrong_operation();
					break;
				}
				break;
			}
			break;
		}
		case 3:	Graph.print_graph();
			break;
		case 4:
		{
			system("cls");
			algorithm_menu my_algotihhm_menu;
			cout << "1.Find distanse" << endl << "100.Back" << endl;
			int op2;
			cin >> op2;
			switch (op2)
			{
			case 1:my_algotihhm_menu.find_distance(Graph);
				break;
			case 100:system("cls");
				break;
			default:this->wrong_operation();
				break;
			}
			break;
		}
		case 5:system("cls");
			return;
		default:this->wrong_operation();
			break;
		}
	}
}


/**
* Here we create graph which tops contain vector<int> and use function on them using console
*/
void main_menu::vector_string_graph()
{
	graph<vector<string>> Graph;
	while (true)
	{
		int op1 = 0, op2 = 0;
		cout << "1.Create new graph" << endl << "2.Edit graph" << endl << "3.Print graph" << endl << "4.Algorithms" << endl << "5.Back" << endl;
		cin >> op1;
		switch (op1)
		{
		case 1:
		{
			system("cls");
			create_new_graph_menu my_create_new_graph_menu;
			int op2;
			while (true)
			{
				cout << "1.Empty graph" << endl << "2.Use adjacency matrix" << endl << "3.Use adjacency list" << endl << "4.Back" << endl;
				cin >> op2;
				switch (op2)
				{
				case 1: my_create_new_graph_menu.empty_graph(Graph);
					break;
				case 2: my_create_new_graph_menu.adjacency_matrix(Graph);
					break;
				case 3: my_create_new_graph_menu.adjacency_list(Graph);
					break;
				case 4:	system("cls");
					break;
				default:this->wrong_operation();
				}
				break;
			}
			break;
		}
		case 2:
		{
			system("cls");
			edit_graph_menu my_edit_graph_menu;
			while (op2 != 4)
			{
				cout << "1.Add top" << endl << "2.Change top data" << endl << "3.Connect top" << endl << "4.Delete top" << endl << "5.Back" << endl;
				cin >> op2;
				switch (op2)
				{
				case 1:my_edit_graph_menu.add_top(Graph);
					break;
				case 2:my_edit_graph_menu.change_top_data(Graph);
					break;
				case 3:my_edit_graph_menu.double_connect_top(Graph);
					break;
				case 4:my_edit_graph_menu.delete_top(Graph);
					break;
				case 5:system("cls");
					break;
				default:this->wrong_operation();
					break;
				}
				break;
			}
			break;
		}
		case 3:	Graph.print_graph();
			break;
		case 4:
		{
			system("cls");
			algorithm_menu my_algotihhm_menu;
			cout << "1.Find distanse" << endl << "100.Back" << endl;
			int op2;
			cin >> op2;
			switch (op2)
			{
			case 1:
			{
				my_algotihhm_menu.find_distance(Graph);
				break;
			}
			case 100:
			{
				system("cls");
				break;
			}
			default:this->wrong_operation();
				break;
			}
			break;
		}
		case 5:system("cls");
			return;
		default:this->wrong_operation();
			break;
		}
	}
}


/*
* Here we create two dice set with 0, 1, 2, 3... numeration
*/
void main_menu::dice_graph_int()
{
	dice<int> first_dice;
	dice<int> second_dice;
	while (true)
	{
		cout << "1.Add dice" << endl << "2.Print all dice" << endl << "3.Change chance" << endl << "4.Print sum" << endl << "5.Compare two combinations" << endl << "6.Exit" << endl;
		dice_menu my_dice_menu;
		int op;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			int sel_dice;
			cout << "1.First dice set" << endl << "2.Second dice set" << endl;
			cin >> sel_dice;
			switch (sel_dice)
			{
			case 1:	my_dice_menu.add_dice(first_dice, 0);
				break;
			case 2: my_dice_menu.add_dice(second_dice, 0);
				break;
			default:wrong_operation();
				break;
			}
			break;
		}
		case 2:
		{
			cout << "First set:" << endl;
			my_dice_menu.print_dice(first_dice);
			cout << "Second set:" << endl;
			my_dice_menu.print_dice(second_dice);
			break;
		}
		case 3:my_dice_menu.change_chance(first_dice);
			break;
		case 4:
		{
			cout << "First set:" << endl;
			my_dice_menu.print_set_of_combination(first_dice);
			cout << "Second set:" << endl;
			my_dice_menu.print_set_of_combination(second_dice);
			break;
		}
		case 5:
		{
			string comb;
			cout << "Enter your sum:";
			cin >> comb;
			my_dice_menu.compare_two_comb(comb, first_dice, second_dice);
			break;
		}
		case 6:system("cls");
			return;
		}
	}
}


/*
* Here we create two dice set with a, b, c, ... numeration
*/
void main_menu::dice_graph_char()
{
	dice<char> first_dice;
	dice<char> second_dice;
	while (true)
	{
		cout << "1.Add dice" << endl << "2.Print all dice" << endl << "3.Change chance" << endl << "4.Print sum" << endl << "5.Compare two combinations" << endl << "6.Exit" << endl;
		dice_menu my_dice_menu;
		int op;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			int sel_dice;
			cout << "1.First dice set" << endl << "2.Second dice set" << endl;
			cin >> sel_dice;
			switch (sel_dice)
			{
			case 1:	my_dice_menu.add_dice(first_dice, 'a');
				break;
			case 2: my_dice_menu.add_dice(second_dice, 'a');
				break;
			default:wrong_operation();
				break;
			}
			break;
		}
		case 2:
		{
			cout << "First set:" << endl;
			my_dice_menu.print_dice(first_dice);
			cout << "Second set:" << endl;
			my_dice_menu.print_dice(second_dice);
			break;
		}
		case 3:my_dice_menu.change_chance(first_dice);
			break;
		case 4:
		{
			cout << "First set:" << endl;
			my_dice_menu.print_set_sum_of_combination(first_dice);
			cout << "Second set:" << endl;
			my_dice_menu.print_set_sum_of_combination(second_dice);
			break;
		}
		case 5:
		{
			int sum;
			cout << "Enter your sum:";
			cin >> sum;
			my_dice_menu.compare_sum_of_two_comb(sum, first_dice, second_dice);
			break;
		}
		case 6:system("cls");
			return;
		}
	}
}

void main_menu::wrong_operation()
{
	system("cls");
	cout << "Wrong operation" << endl;
}