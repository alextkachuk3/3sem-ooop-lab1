#include "UI.hpp"

/*! Main project file.
* \file main.cpp
* \author Alex Tkachuk
* \version 1.0 11/10/20
*/


//! main function
/*!
* Starts a program. Assigns menus
*/
int main()
{
	auto my_UI = new UI;
	
	while (true)
	{
		cout << "1.graph_matrix_int" << endl << "2.graph_matrix_double" << endl << "3.graph_matrix_string" << endl << "4.graph_matrix_vector_int" << endl
			<< "5.graph_list_int" << endl << "6.graph_list_double" << endl << "7.graph_list_vector_string" << endl << "8.graph_list_vector_int" << endl
			<< "10.graph_dice_list_num" << endl << "11.Exit" << endl;
		int op;
		cin >> op;
		switch (op)
		{
		case 1:my_UI->graph_matrix_int();
			break;
		case 2:my_UI->graph_matrix_double();
			break;
		case 3:my_UI->graph_matrix_string();
			break;
		case 4:my_UI->graph_matrix_vector_int();
			break;
		case 5:my_UI->graph_list_int();
			break;
		case 6:my_UI->graph_list_double();
			break;
		case 7:my_UI->graph_list_string();
			break;
		case 8:my_UI->graph_list_vector_int();
			break;
		case 9:
			break;
		case 10:my_UI->graph_list_dice_int();
			break;
		case 11:return 0;
			break;
		default:system("cls");
			break;
		}
	}

	delete my_UI;
	return 0;
}