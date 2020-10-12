#include "Menu.h"
#include <iostream>

using namespace std;

int main()
{
	Menu my_menu;
	int op;
	while (true)
	{
		cout << "1.Dice" << endl << "2.Graph<int>" << endl << "3.Graph<vector<string>" << endl << "4.Exit" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
		{
			my_menu.dice_graph();
			break;
		}
		case 2:
		{
			my_menu.int_graph();
			break;
		}
		case 3:
		{
			my_menu.vector_string_graph();
			break;
		}
		case 4:
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