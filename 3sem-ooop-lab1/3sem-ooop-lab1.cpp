﻿#include "Menu/main_menu.hpp"
#include <iostream>

using namespace std;


/*
* From main menu we chosee type of struct
*/
int main()
{
	main_menu my_menu;
	int op;
	while (true)
	{
		cout << "1.Dice(0, 1, 2, 3 ...)" << endl << "2.Dice(a, b, c...)" << endl << "3.Graph<int>" << endl << "4.Graph<vector<string>" << endl << "5.Exit" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			system("cls");
			my_menu.dice_graph_int();
			break;
		}
		case 2:
		{
			system("cls");
			my_menu.dice_graph_char();
			break;
		}
		case 3:
		{
			system("cls");
			my_menu.int_graph();
			break;
		}
		case 4:
		{
			system("cls");
			my_menu.vector_string_graph();
			break;
		}
		case 5:
		{
			return 0;
		}
		default:
		{
			system("cls");
			cout << "Wrong operation" << endl;
			break;
		}
		}
	}
	return 0;
}