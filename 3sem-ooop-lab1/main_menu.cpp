#include "main_menu.h"

using namespace std;

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
			int op2 = 0;
			while (op2 != 4)
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
				case 4:
				{
					system("cls");
					op2 = 0;
					break;
				}
				default:
					system("cls");
					cout << "Wrong operation" << endl;
					break;
				}
				break;
			}
			break;
		}
		case 2:
		{
			system("cls");
			while (op2 != 4)
			{
				cout << "1.Add top" << endl << "2.Change top data" << endl << "3.Connect top" << endl << "4.Delete top" << endl << "5.Back" << endl;
				cin >> op2;
				switch (op2)
				{
				case 1:
				{
					int data;
					cout << "Enter data:";
					cin >> data;
					Graph.add_top(data);
					break;
				}
				case 2:
				{
					int index, new_data;
					cout << "Enter index of top:";
					cin >> index;
					cout << "Enter data:";
					cin >> new_data;
					Graph.change_top_data(index, new_data);
					break;
				}
				case 3:
				{
					int first, second, weight;
					cout << "Enter number of first top:";
					cin >> first;
					cout << "Enter number of second top";
					cin >> second;
					cout << "Enter weight of connection:";
					cin >> weight;
					Graph.connect(first, second, weight);
					break;
				}
				case 4:
				{
					int num_t;
					cout << "Enter number of top:";
					cin >> num_t;
					Graph.del_top(num_t);
					break;
				}
				case 5:
				{
					system("cls");
					break;
				}
				default:
				{
					system("cls");
					cout << "Wrong operation" << endl;
					break;
				}
				}
				break;
			}
			break;
		}
		case 3:
		{
			Graph.print_graph();
			break;
		}
		case 4:
		{
			cout << "1.Find distanse" << endl << "100.Exit" << endl;
			int op2;
			cin >> op2;
			switch (op2)
			{
				/*
			case 1:
			{
				system("cls");
				int ind_from, ind_to;
				cout << "Enter index of top(from):";
				cin >> ind_from;
				cout << "Enter index of top(to):";
				cin >> ind_to;
				cout << Graph.distance(ind_from, ind_to);
				break;
			}

			case 2:
			{
				system("cls");
				if (Graph.chech_connectivity())
					cout << "Graph is connectivited" << endl;
				else
					cout << "Graph is not connectivited" << endl;
				break;
			} */
			case 100:
			{
				system("cls");
				break;
			}
			}
			break;
		}
		case 5:
		{
			system("cls");
			return;
		}
		default:
		{
			system("cls");
			cout << "Wrong operation" << endl;
			break;
		}
		}
	}
}

void main_menu::vector_string_graph()
{

}

void main_menu::dice_graph()
{

}
