#include "UI.hpp"

string UI::random_string()
{
	string result;
	for (int i = 0; i < 10; i++)
	{
		result += rand() % 64 + 58;
	}
	return result;
}

vector<int> UI::random_vector()
{
	vector<int> result;
	for (int i = 0; i < 3; i++)
	{
		result.push_back(rand() % 10 + 1);
	}
	return result;
}

void UI::graph_matrix_int()
{
	system("cls");

	vector<vector<int>> matrix;
	for (int i = 0; i < 4; i++)
	{
		vector<int> row;
		for (int j = 0; j < 4; j++)
		{
			row.push_back(rand() % 10000 + 1);
		}
		matrix.push_back(row);
	}
	cout << "Create graph using matrix:" << endl;
	for (const auto& a : matrix)
	{
		for (const auto& b : a)
		{
			cout << b << " ";
		}
		cout << endl;
	}
	Graph_matrix<int>* graph_matrix_int = new Graph_matrix<int>(matrix);
	cout << "Which vertices contain:" << endl;
	for (int i = 0; i < 4; i++)
	{
		int t = rand();
		cout << i << ":" << t << " ";
		graph_matrix_int->set_data(i, t);
	}
	cout << endl;
	graph_matrix_int->print();
	cout << "Check connectivity:" << graph_matrix_int->is_connected() << endl;
	cout << "Add 3 vertices:" << endl;
	for (int i = 0; i < 3; i++)
	{
		int t = rand();
		cout << t << endl;
		graph_matrix_int->insert(t);
	}
	graph_matrix_int->print();
	cout << "Check connectivity:" << graph_matrix_int->is_connected() << endl;
	cout << "Connect vertices: 5 to 3 (1241)" << endl;
	graph_matrix_int->connect(5, 3, 1241);
	graph_matrix_int->print();
	cout << "Connect vertices: 5 to 3 (1241)" << endl;
	graph_matrix_int->connect(5, 3, 1241);
	graph_matrix_int->print();
	cout << "Unconnect 5 to 3" << endl;
	graph_matrix_int->disconect(5, 3);
	graph_matrix_int->print();
	cout << "Connect vertices: 6 to 1 (564)" << endl;
	graph_matrix_int->connect(6, 1, 564);
	cout << "Connect vertices: 1 to 5 (742)" << endl;
	graph_matrix_int->connect(1, 5, 742);
	graph_matrix_int->print();
	cout << "Delete 3th vertex" << endl;
	graph_matrix_int->erase(3);
	cout << "Add vertex with data 3424" << endl;
	graph_matrix_int->insert(3424);
	graph_matrix_int->print();
	cout << "Delete 5th vertex" << endl;
	graph_matrix_int->erase(5);
	graph_matrix_int->print();
	cout << "Connect vertices: 5 to 0 (7642)" << endl;
	graph_matrix_int->connect(5, 0, 7642);
	cout << "Connect vertices: 5 to 4 (635)" << endl;
	graph_matrix_int->connect(5, 4, 635);
	cout << "Connect vertices: 4 to 3 (525)" << endl;
	graph_matrix_int->connect(4, 3, 525);
	graph_matrix_int->print();
	cout << "Find path from 5 to 2:" << endl;
	auto path52 = graph_matrix_int->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl << "Change data connection 0 2 to 99999" << endl;
	graph_matrix_int->disconect(0, 2);
	graph_matrix_int->connect(0, 2, 99999);
	graph_matrix_int->print();
	cout << "Find path from 5 to 2:" << endl;
	path52 = graph_matrix_int->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl;
	delete graph_matrix_int;
}

void UI::graph_matrix_double()
{
	vector<vector<double>> matrix;
	for (int i = 0; i < 4; i++)
	{
		vector<double> row;
		for (int j = 0; j < 4; j++)
		{
			row.push_back((rand() % 10000) * 1.0 / (rand() % 10000) + 1);
		}
		matrix.push_back(row);
	}
	cout << "Create graph using matrix:" << endl;
	for (const auto& a : matrix)
	{
		for (const auto& b : a)
		{
			cout << b << " ";
		}
		cout << endl;
	}
	Graph_matrix<double>* graph_matrix_double = new Graph_matrix<double>(matrix);
	cout << "Which vertices contain:" << endl;
	for (int i = 0; i < 4; i++)
	{
		int t = (rand() % 10000) * 1.0 / (rand() % 10000) + 1;
		cout << i << ":" << t << " ";
		graph_matrix_double->set_data(i, t);
	}
	cout << endl;
	graph_matrix_double->print();
	cout << "Check connectivity:" << graph_matrix_double->is_connected() << endl;
	cout << "Add 3 vertices:" << endl;
	for (int i = 0; i < 3; i++)
	{
		int t = rand();
		cout << t << endl;
		graph_matrix_double->insert(t);
	}
	graph_matrix_double->print();
	cout << "Check connectivity:" << graph_matrix_double->is_connected() << endl;
	cout << "Connect vertices: 5 to 3 (1241.1441)" << endl;
	graph_matrix_double->connect(5, 3, 1241.1441);
	graph_matrix_double->print();
	cout << "Connect vertices: 5 to 3 (1241.646)" << endl;
	graph_matrix_double->connect(5, 3, 1241.646);
	graph_matrix_double->print();
	cout << "Unconnect 5 to 3" << endl;
	graph_matrix_double->disconect(5, 3);
	graph_matrix_double->print();
	cout << "Connect vertices: 6 to 1 (564.1)" << endl;
	graph_matrix_double->connect(6, 1, 564.1);
	cout << "Connect vertices: 1 to 5 (742.424)" << endl;
	graph_matrix_double->connect(1, 5, 742.424);
	graph_matrix_double->print();
	cout << "Delete 3th vertex" << endl;
	graph_matrix_double->erase(3);
	cout << "Add vertex with data 3424.6" << endl;
	graph_matrix_double->insert(3424.6);
	graph_matrix_double->print();
	cout << "Delete 5th vertex" << endl;
	graph_matrix_double->erase(5);
	graph_matrix_double->print();
	cout << "Connect vertices: 5 to 0 (7642.85)" << endl;
	graph_matrix_double->connect(5, 0, 7642.85);
	cout << "Connect vertices: 5 to 4 (635.6351)" << endl;
	graph_matrix_double->connect(5, 4, 635.6351);
	cout << "Connect vertices: 4 to 3 (525.535353)" << endl;
	graph_matrix_double->connect(4, 3, 525.535353);
	graph_matrix_double->print();
	cout << "Find path from 5 to 2:" << endl;
	auto path52 = graph_matrix_double->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl << "Change data connection 0 2 to 99999.9" << endl;
	graph_matrix_double->disconect(0, 2);
	graph_matrix_double->connect(0, 2, 99999.9);
	graph_matrix_double->print();
	cout << "Find path from 5 to 2:" << endl;
	path52 = graph_matrix_double->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl;
	delete graph_matrix_double;
	system("pause");
	system("cls");
}

void UI::graph_matrix_string()
{
	vector<vector<string>> matrix;
	for (int i = 0; i < 4; i++)
	{
		vector<string> row;
		for (int j = 0; j < 4; j++)
		{
			row.push_back(this->random_string());
		}
		matrix.push_back(row);
	}
	cout << "Create graph using matrix:" << endl;
	for (const auto& a : matrix)
	{
		for (const auto& b : a)
		{
			cout << b << " ";
		}
		cout << endl;
	}
	Graph_matrix<string>* graph_matrix_int = new Graph_matrix<string>(matrix);
	cout << "Which vertices contain:" << endl;
	for (int i = 0; i < 4; i++)
	{
		string t = this->random_string();
		cout << i << ":" << t << " ";
		graph_matrix_int->set_data(i, t);
	}
	cout << endl;
	graph_matrix_int->print();
	cout << "Check connectivity:" << graph_matrix_int->is_connected() << endl;
	cout << "Add 3 vertices:" << endl;
	for (int i = 0; i < 3; i++)
	{
		string t = this->random_string();
		cout << t << endl;
		graph_matrix_int->insert(t);
	}
	graph_matrix_int->print();
	cout << "Check connectivity:" << graph_matrix_int->is_connected() << endl;
	string cur_str = random_string();
	cout << "Connect vertices: 5 to 3 (" << cur_str << ")" << endl;
	graph_matrix_int->connect(5, 3, cur_str);
	graph_matrix_int->print();
	cur_str = random_string();
	cout << "Connect vertices: 5 to 3 (" << cur_str <<")" << endl;
	graph_matrix_int->connect(5, 3, cur_str);
	graph_matrix_int->print();
	cout << "Unconnect 5 to 3" << endl;
	graph_matrix_int->disconect(5, 3);
	graph_matrix_int->print();
	cur_str = random_string();
	cout << "Connect vertices: 6 to 1 (" << cur_str << ")" << endl;
	graph_matrix_int->connect(6, 1, cur_str);
	cur_str = random_string();
	cout << "Connect vertices: 1 to 5 (" << cur_str << ")" << endl;
	graph_matrix_int->connect(1, 5, cur_str);
	graph_matrix_int->print();
	cout << "Delete 3th vertex" << endl;
	graph_matrix_int->erase(3);
	cur_str = random_string();
	cout << "Add vertex with data " << cur_str << endl;
	graph_matrix_int->insert(cur_str);
	graph_matrix_int->print();
	cout << "Delete 5th vertex" << endl;
	graph_matrix_int->erase(5);
	graph_matrix_int->print();
	cur_str = random_string();
	cout << "Connect vertices: 5 to 0 (" << cur_str << ")" << endl;
	graph_matrix_int->connect(5, 0, cur_str);
	cur_str = random_string();
	cout << "Connect vertices: 5 to 4 (" <<cur_str << ")" << endl;
	graph_matrix_int->connect(5, 4, cur_str);
	cur_str = random_string();
	cout << "Connect vertices: 4 to 3 (" << cur_str << ")" << endl;
	graph_matrix_int->connect(4, 3, cur_str);
	graph_matrix_int->print();
	cout << "Find path from 5 to 2:" << endl;
	auto path52 = graph_matrix_int->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl << "Change data connection 0 2 to zzzzzzz" << endl;
	graph_matrix_int->disconect(0, 2);
	graph_matrix_int->connect(0, 2, "zzzzzz");
	graph_matrix_int->print();
	cout << "Find path from 5 to 2:" << endl;
	path52 = graph_matrix_int->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl;
	delete graph_matrix_int;
	system("pause");
	system("cls");
}

void UI::graph_matrix_vector_int()
{
	vector<vector<vector<int>>> matrix;
	for (int i = 0; i < 4; i++)
	{
		vector<vector<int>> row;
		for (int j = 0; j < 4; j++)
		{
			row.push_back(this->random_vector());
		}
		matrix.push_back(row);
	}
	cout << "Create graph using matrix:" << endl;
	for (const auto& a : matrix)
	{
		for (const auto& b : a)
		{
			cout << b << " ";
		}
		cout << endl;
	}
	Graph_matrix<vector<int>>* graph_matrix_int = new Graph_matrix<vector<int>>(matrix);
	cout << "Which vertices contain:" << endl;
	for (int i = 0; i < 4; i++)
	{
		vector<int> t = this->random_vector();
		cout << i << ":" << t << " ";
		graph_matrix_int->set_data(i, t);
	}
	cout << endl;
	graph_matrix_int->print();
	cout << "Check connectivity:" << graph_matrix_int->is_connected() << endl;
	cout << "Add 3 vertices:" << endl;
	for (int i = 0; i < 3; i++)
	{
		vector<int> t = this->random_vector();
		cout << t << endl;
		graph_matrix_int->insert(t);
	}
	graph_matrix_int->print();
	cout << "Check connectivity:" << graph_matrix_int->is_connected() << endl;
	vector<int> cur_vec = random_vector();
	cout << "Connect vertices: 5 to 3 (" << cur_vec << ")" << endl;
	graph_matrix_int->connect(5, 3, cur_vec);
	graph_matrix_int->print();
	cur_vec = random_vector();
	cout << "Connect vertices: 5 to 3 (" << cur_vec << ")" << endl;
	graph_matrix_int->connect(5, 3, cur_vec);
	graph_matrix_int->print();
	cout << "Unconnect 5 to 3" << endl;
	graph_matrix_int->disconect(5, 3);
	graph_matrix_int->print();
	cur_vec = random_vector();
	cout << "Connect vertices: 6 to 1 (" << cur_vec << ")" << endl;
	graph_matrix_int->connect(6, 1, cur_vec);
	cur_vec = random_vector();
	cout << "Connect vertices: 1 to 5 (" << cur_vec << ")" << endl;
	graph_matrix_int->connect(1, 5, cur_vec);
	graph_matrix_int->print();
	cout << "Delete 3th vertex" << endl;
	graph_matrix_int->erase(3);
	cur_vec = random_vector();
	cout << "Add vertex with data " << cur_vec << endl;
	graph_matrix_int->insert(cur_vec);
	graph_matrix_int->print();
	cout << "Delete 5th vertex" << endl;
	graph_matrix_int->erase(5);
	graph_matrix_int->print();
	cur_vec = random_vector();
	cout << "Connect vertices: 5 to 0 (" << cur_vec << ")" << endl;
	graph_matrix_int->connect(5, 0, cur_vec);
	cur_vec = random_vector();
	cout << "Connect vertices: 5 to 4 (" << cur_vec << ")" << endl;
	graph_matrix_int->connect(5, 4, cur_vec);
	cur_vec = random_vector();
	cout << "Connect vertices: 4 to 3 (" << cur_vec << ")" << endl;
	graph_matrix_int->connect(4, 3, cur_vec);
	graph_matrix_int->print();
	cout << "Find path from 5 to 2:" << endl;
	auto path52 = graph_matrix_int->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl << "Change data connection 0 2 to {3, 4, 5, 2}" << endl;
	graph_matrix_int->disconect(0, 2);
	graph_matrix_int->connect(0, 2, { 3, 4, 5, 2 });
	graph_matrix_int->print();
	cout << "Find path from 5 to 2:" << endl;
	path52 = graph_matrix_int->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl;
	delete graph_matrix_int;
	system("pause");
	system("cls");
}

void UI::graph_list_int()
{
	system("cls");
	vector<vector<pair<int, int>>> list;
	for (int i = 0; i < 4; i++)
	{
		vector<pair<int, int>> row;
		for (int j = 0; j < 4; j++)
		{
			row.push_back({ j, rand() % 10000 + 1 });
		}
		list.push_back(row);
	}
	cout << "Create graph using list:" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		cout << i << " : ";
		for (const auto& b : list[i])
		{
			cout << b.first << " " << b.second << " ";
		}
		cout << endl;
	}
	Graph_list<int>* graph_list_int = new Graph_list<int>(list);
	cout << "Which vertices contain:" << endl;
	for (int i = 0; i < 4; i++)
	{
		int t = rand();
		cout << i << ":" << t << " ";
		graph_list_int->set_data(i, t);
	}
	cout << endl;
	graph_list_int->print();
	cout << "Check connectivity:" << graph_list_int->is_connected() << endl;
	cout << "Add 3 vertices:" << endl;
	for (int i = 0; i < 3; i++)
	{
		int t = rand();
		cout << t << endl;
		graph_list_int->insert(t);
	}
	graph_list_int->print();
	cout << "Check connectivity:" << graph_list_int->is_connected() << endl;
	cout << "Connect vertices: 5 to 3 (1241)" << endl;
	graph_list_int->connect(5, 3, 1241);
	graph_list_int->print();
	cout << "Connect vertices: 5 to 3 (1241)" << endl;
	graph_list_int->connect(5, 3, 1241);
	graph_list_int->print();
	cout << "Unconnect 5 to 3" << endl;
	graph_list_int->disconect(5, 3);
	graph_list_int->print();
	cout << "Connect vertices: 6 to 1 (564)" << endl;
	graph_list_int->connect(6, 1, 564);
	cout << "Connect vertices: 1 to 5 (742)" << endl;
	graph_list_int->connect(1, 5, 742);
	graph_list_int->print();
	cout << "Delete 3th vertex" << endl;
	graph_list_int->erase(3);
	cout << "Add vertex with data 3424" << endl;
	graph_list_int->insert(3424);
	graph_list_int->print();
	cout << "Delete 5th vertex" << endl;
	graph_list_int->erase(5);
	graph_list_int->print();
	cout << "Connect vertices: 5 to 0 (7642)" << endl;
	graph_list_int->connect(5, 0, 7642);
	cout << "Connect vertices: 5 to 4 (635)" << endl;
	graph_list_int->connect(5, 4, 635);
	cout << "Connect vertices: 4 to 3 (525)" << endl;
	graph_list_int->connect(4, 3, 525);
	graph_list_int->print();
	cout << "Find path from 5 to 2:" << endl;
	auto path52 = graph_list_int->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl << "Change data connection 0 2 to 99999" << endl;
	graph_list_int->disconect(0, 2);
	graph_list_int->connect(0, 2, 99999);
	graph_list_int->print();
	cout << "Find path from 5 to 2:" << endl;
	path52 = graph_list_int->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl;
	delete graph_list_int;
}

void UI::graph_list_double()
{
	system("cls");
	vector<vector<pair<int, double>>> list;
	for (int i = 0; i < 4; i++)
	{
		vector<pair<int, double>> row;
		for (int j = 0; j < 4; j++)
		{
			row.push_back({ j, ((rand() % 10000) * 1.0 / (rand() % 10000) + 1) });
		}
		list.push_back(row);
	}
	cout << "Create graph using list:" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		cout << i << " : ";
		for (const auto& b : list[i])
		{
			cout << b.first << " " << b.second << " ";
		}
		cout << endl;
	}
	Graph_list<double>* graph_list_double = new Graph_list<double>(list);
	cout << "Which vertices contain:" << endl;
	for (int i = 0; i < 4; i++)
	{
		double t = (rand() % 10000) * 1.0 / (rand() % 10000) + 1;
		cout << i << ":" << t << " ";
		graph_list_double->set_data(i, t);
	}
	cout << endl;
	graph_list_double->print();
	cout << "Check connectivity:" << graph_list_double->is_connected() << endl;
	cout << "Add 3 vertices:" << endl;
	for (int i = 0; i < 3; i++)
	{
		int t = rand();
		cout << t << endl;
		graph_list_double->insert(t);
	}
	graph_list_double->print();
	cout << "Check connectivity:" << graph_list_double->is_connected() << endl;
	cout << "Connect vertices: 5 to 3 (1241.1441)" << endl;
	graph_list_double->connect(5, 3, 1241.1441);
	graph_list_double->print();
	cout << "Connect vertices: 5 to 3 (1241.646)" << endl;
	graph_list_double->connect(5, 3, 1241.646);
	graph_list_double->print();
	cout << "Unconnect 5 to 3" << endl;
	graph_list_double->disconect(5, 3);
	graph_list_double->print();
	cout << "Connect vertices: 6 to 1 (564.1)" << endl;
	graph_list_double->connect(6, 1, 564.1);
	cout << "Connect vertices: 1 to 5 (742.424)" << endl;
	graph_list_double->connect(1, 5, 742.424);
	graph_list_double->print();
	cout << "Delete 3th vertex" << endl;
	graph_list_double->erase(3);
	cout << "Add vertex with data 3424.6" << endl;
	graph_list_double->insert(3424.6);
	graph_list_double->print();
	cout << "Delete 5th vertex" << endl;
	graph_list_double->erase(5);
	graph_list_double->print();
	cout << "Connect vertices: 5 to 0 (7642.85)" << endl;
	graph_list_double->connect(5, 0, 7642.85);
	cout << "Connect vertices: 5 to 4 (635.6351)" << endl;
	graph_list_double->connect(5, 4, 635.6351);
	cout << "Connect vertices: 4 to 3 (525.535353)" << endl;
	graph_list_double->connect(4, 3, 525.535353);
	graph_list_double->print();
	cout << "Find path from 5 to 2:" << endl;
	auto path52 = graph_list_double->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl << "Change data connection 0 2 to 99999.9" << endl;
	graph_list_double->disconect(0, 2);
	graph_list_double->connect(0, 2, 99999.9);
	graph_list_double->print();
	cout << "Find path from 5 to 2:" << endl;
	path52 = graph_list_double->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl;
	delete graph_list_double;
	system("pause");
	system("cls");
}

void UI::graph_list_string()
{
	system("cls");
	vector<vector<pair<int, string>>> list;
	for (int i = 0; i < 4; i++)
	{
		vector<pair<int, string>> row;
		for (int j = 0; j < 4; j++)
		{
			row.push_back({ j, this->random_string() });
		}
		list.push_back(row);
	}
	cout << "Create graph using list:" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		cout << i << " : ";
		for (const auto& b : list[i])
		{
			cout << b.first << " " << b.second << " ";
		}
		cout << endl;
	}
	Graph_list<string>* graph_list_string = new Graph_list<string>(list);
	cout << "Which vertices contain:" << endl;
	for (int i = 0; i < 4; i++)
	{
		string t = random_string();
		cout << i << ":" << t << " ";
		graph_list_string->set_data(i, t);
	}
	cout << endl;
	graph_list_string->print();
	cout << "Check connectivity:" << graph_list_string->is_connected() << endl;
	cout << "Add 3 vertices:" << endl;
	for (int i = 0; i < 3; i++)
	{
		string t = this->random_string();
		cout << t << endl;
		graph_list_string->insert(t);
	}
	graph_list_string->print();
	cout << "Check connectivity:" << graph_list_string->is_connected() << endl;
	string cur_str = random_string();
	cout << "Connect vertices: 5 to 3 (" << cur_str << ")" << endl;
	graph_list_string->connect(5, 3, cur_str);
	graph_list_string->print();
	cur_str = random_string();
	cout << "Connect vertices: 5 to 3 (" << cur_str << ")" << endl;
	graph_list_string->connect(5, 3, cur_str);
	graph_list_string->print();
	cout << "Unconnect 5 to 3" << endl;
	graph_list_string->disconect(5, 3);
	graph_list_string->print();
	cur_str = random_string();
	cout << "Connect vertices: 6 to 1 (" << cur_str << ")" << endl;
	graph_list_string->connect(6, 1, cur_str);
	cur_str = random_string();
	cout << "Connect vertices: 1 to 5 (" << cur_str << ")" << endl;
	graph_list_string->connect(1, 5, cur_str);
	graph_list_string->print();
	cout << "Delete 3th vertex" << endl;
	graph_list_string->erase(3);
	cur_str = random_string();
	cout << "Add vertex with data " << cur_str << endl;
	graph_list_string->insert(cur_str);
	graph_list_string->print();
	cout << "Delete 5th vertex" << endl;
	graph_list_string->erase(5);
	graph_list_string->print();
	cur_str = random_string();
	cout << "Connect vertices: 5 to 0 (" << cur_str << ")" << endl;
	graph_list_string->connect(5, 0, cur_str);
	cur_str = random_string();
	cout << "Connect vertices: 5 to 4 (" << cur_str << ")" << endl;
	graph_list_string->connect(5, 4, cur_str);
	cur_str = random_string();
	cout << "Connect vertices: 4 to 3 (" << cur_str << ")" << endl;
	graph_list_string->connect(4, 3, cur_str);
	graph_list_string->print();
	cout << "Find path from 5 to 2:" << endl;
	auto path52 = graph_list_string->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl << "Change data connection 0 2 to zzzzzzz" << endl;
	graph_list_string->disconect(0, 2);
	graph_list_string->connect(0, 2, "zzzzzz");
	graph_list_string->print();
	cout << "Find path from 5 to 2:" << endl;
	path52 = graph_list_string->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl;
	delete graph_list_string;
	system("pause");
	system("cls");
}

void UI::graph_list_vector_int()
{
	system("cls");
	vector<vector<pair<int, vector<int>>>> list;
	for (int i = 0; i < 4; i++)
	{
		vector<pair<int, vector<int>>> row;
		for (int j = 0; j < 4; j++)
		{
			row.push_back({ j, this->random_vector() });
		}
		list.push_back(row);
	}
	cout << "Create graph using list:" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		cout << i << " : ";
		for (const auto& b : list[i])
		{
			cout << b.first << " " << b.second << " ";
		}
		cout << endl;
	}
	Graph_list<vector<int>>* graph_matrix_vector_int = new Graph_list<vector<int>>(list);
	vector<int> cur_vec;
	cout << "Which vertices contain:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cur_vec = this->random_vector();
		cout << i << ":" << cur_vec << " ";
		graph_matrix_vector_int->set_data(i, cur_vec);
	}
	cout << endl;
	graph_matrix_vector_int->print();
	cout << "Check connectivity:" << graph_matrix_vector_int->is_connected() << endl;
	cout << "Add 3 vertices:" << endl;
	for (int i = 0; i < 3; i++)
	{
		vector<int> t = this->random_vector();
		cout << t << endl;
		graph_matrix_vector_int->insert(t);
	}
	graph_matrix_vector_int->print();
	cout << "Check connectivity:" << graph_matrix_vector_int->is_connected() << endl;
	cur_vec = random_vector();
	cout << "Connect vertices: 5 to 3 (" << cur_vec << ")" << endl;
	graph_matrix_vector_int->connect(5, 3, cur_vec);
	graph_matrix_vector_int->print();
	cur_vec = random_vector();
	cout << "Connect vertices: 5 to 3 (" << cur_vec << ")" << endl;
	graph_matrix_vector_int->connect(5, 3, cur_vec);
	graph_matrix_vector_int->print();
	cout << "Unconnect 5 to 3" << endl;
	graph_matrix_vector_int->disconect(5, 3);
	graph_matrix_vector_int->print();
	cur_vec = random_vector();
	cout << "Connect vertices: 6 to 1 (" << cur_vec << ")" << endl;
	graph_matrix_vector_int->connect(6, 1, cur_vec);
	cur_vec = random_vector();
	cout << "Connect vertices: 1 to 5 (" << cur_vec << ")" << endl;
	graph_matrix_vector_int->connect(1, 5, cur_vec);
	graph_matrix_vector_int->print();
	cout << "Delete 3th vertex" << endl;
	graph_matrix_vector_int->erase(3);
	cur_vec = random_vector();
	cout << "Add vertex with data " << cur_vec << endl;
	graph_matrix_vector_int->insert(cur_vec);
	graph_matrix_vector_int->print();
	cout << "Delete 5th vertex" << endl;
	graph_matrix_vector_int->erase(5);
	graph_matrix_vector_int->print();
	cur_vec = random_vector();
	cout << "Connect vertices: 5 to 0 (" << cur_vec << ")" << endl;
	graph_matrix_vector_int->connect(5, 0, cur_vec);
	cur_vec = random_vector();
	cout << "Connect vertices: 5 to 4 (" << cur_vec << ")" << endl;
	graph_matrix_vector_int->connect(5, 4, cur_vec);
	cur_vec = random_vector();
	cout << "Connect vertices: 4 to 3 (" << cur_vec << ")" << endl;
	graph_matrix_vector_int->connect(4, 3, cur_vec);
	graph_matrix_vector_int->print();
	cout << "Find path from 5 to 2:" << endl;
	auto path52 = graph_matrix_vector_int->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl << "Change data connection 0 2 to {3, 4, 5, 2}" << endl;
	graph_matrix_vector_int->disconect(0, 2);
	graph_matrix_vector_int->connect(0, 2, { 3, 4, 5, 2 });
	graph_matrix_vector_int->print();
	cout << "Find path from 5 to 2:" << endl;
	path52 = graph_matrix_vector_int->find_paths(5, 2);
	for (const auto& a : path52)
	{
		cout << a.first->data << " --- " << a.second->index << "(" << a.second->data << ") --- ";
	}
	cout << endl;
	delete graph_matrix_vector_int;
	system("pause");
	system("cls");
}

void UI::graph_list_dice_int()
{
	Graph_list<Dice_set<int>*>* dice_list_int_graph = new Graph_list<Dice_set<int>*>;

	Dice_set<int>* first_dice_set = new Dice_set<int>;

	Dice_set<int>* second_dice_set = new Dice_set<int>;

	Dice_set<int>* third_dice_set = new Dice_set<int>;

	cout << "first_dice_set->add({ {1,3}, {2, 8}, {3, 1} });" << endl

		<< "first_dice_set->add({ {1,1}, {2, 1}, {3, 1}, {4, 2} });" << endl

		<< "second_dice_set->add({ {1,3}, {2, 4}, {3, 1} });" << endl

		<< "second_dice_set->add({ {1,1}, {2, 1}, {3, 1}, {4, 2} });" << endl;

	first_dice_set->add({ {1,3}, {2, 8}, {3, 1} });

	first_dice_set->add({ {1,1}, {2, 1}, {3, 1}, {4, 2} });

	second_dice_set->add({ {1,3}, {2, 4}, {3, 1} });

	second_dice_set->add({ {1,1}, {2, 1}, {3, 1}, {4, 2} });

	
	cout << "FIRST SUMS" << endl;
	auto sums = first_dice_set->combinations_chances_sums();

	for (const auto& a : sums)
	{
		cout << a.first << " " << a.second << endl;
	}

	cout << "SECOND SUMS" << endl;
	sums = first_dice_set->combinations_chances_sums();

	for (const auto& a : sums)
	{
		cout << a.first << " " << a.second << endl;
	}

	cout << "Compare first sums with second sums" << endl;

	auto compare_comb = first_dice_set->compare_with_other_dice_set_combination_chances_sums(*second_dice_set);

	for (auto& a : compare_comb.first)
	{
		cout << a.first << " " << a.second << endl;
	}

	for (auto& a : compare_comb.second)
	{
		cout << a.first << " " << a.second << endl;
	}

	cout << "third_dice_set->add({ {2,3}, {3, 3} });" << endl

		<< "dice_list_int_graph->insert(first_dice_set);" << endl

		<< "dice_list_int_graph->insert(first_dice_set);" << endl

		<< "dice_list_int_graph->connect(0, 1, third_dice_set);" << endl

		<< endl << "dice_list_int_graph->print();";

	third_dice_set->add({ {2,3}, {3, 3} });

	dice_list_int_graph->insert(first_dice_set);

	dice_list_int_graph->insert(first_dice_set);

	dice_list_int_graph->connect(0, 1, third_dice_set);

	dice_list_int_graph->print();

	delete dice_list_int_graph;
}

void UI::graph_matrix_dice_int()
{
	Graph_matrix<Dice_set<int>*>* dice_matrix_int_graph = new Graph_matrix<Dice_set<int>*>;

	Dice_set<int>* first_dice_set = new Dice_set<int>;

	Dice_set<int>* second_dice_set = new Dice_set<int>;

	Dice_set<int>* third_dice_set = new Dice_set<int>;

	cout << "first_dice_set->add({ {1,3}, {2, 8}, {3, 1} });" << endl

		<< "first_dice_set->add({ {1,1}, {2, 1}, {3, 1}, {4, 2} });" << endl

		<< "second_dice_set->add({ {1,3}, {2, 4}, {3, 1} });" << endl

		<< "second_dice_set->add({ {1,1}, {2, 1}, {3, 1}, {4, 2} });" << endl;

	first_dice_set->add({ {1,3}, {2, 8}, {3, 1} });

	first_dice_set->add({ {1,1}, {2, 1}, {3, 1}, {4, 2} });

	second_dice_set->add({ {1,3}, {2, 4}, {3, 1} });

	second_dice_set->add({ {1,1}, {2, 1}, {3, 1}, {4, 2} });


	cout << "FIRST SUMS" << endl;
	auto sums = first_dice_set->combinations_chances_sums();

	for (const auto& a : sums)
	{
		cout << a.first << " " << a.second << endl;
	}

	cout << "SECOND SUMS" << endl;
	sums = second_dice_set->combinations_chances_sums();

	for (const auto& a : sums)
	{
		cout << a.first << " " << a.second << endl;
	}

	cout << "Compare first sums with second sums" << endl;

	auto compare_comb = first_dice_set->compare_with_other_dice_set_combination_chances_sums(*second_dice_set);

	for (auto& a : compare_comb.first)
	{
		cout << a.first << " " << a.second << endl;
	}

	for (auto& a : compare_comb.second)
	{
		cout << a.first << " " << a.second << endl;
	}

	cout << "third_dice_set->add({ {2,3}, {3, 3} });" << endl

		<< "dice_list_int_graph->insert(first_dice_set);" << endl

		<< "dice_list_int_graph->insert(first_dice_set);" << endl

		<< "dice_list_int_graph->connect(0, 1, third_dice_set);" << endl

		<< endl << "dice_list_int_graph->print();";

	third_dice_set->add({ {2,3}, {3, 3} });

	dice_matrix_int_graph->insert(first_dice_set);

	dice_matrix_int_graph->insert(first_dice_set);

	dice_matrix_int_graph->connect(0, 1, third_dice_set);

	dice_matrix_int_graph->print();

	delete dice_matrix_int_graph;
}

void UI::graph_matrix_dice_char()
{
	Graph_matrix<Dice_set<dice_char>*>* dice_list_int_graph = new Graph_matrix<Dice_set<dice_char>*>;

	Dice_set<dice_char>* first_dice_set = new Dice_set<dice_char>;

	Dice_set<dice_char>* second_dice_set = new Dice_set<dice_char>;

	Dice_set<dice_char>* third_dice_set = new Dice_set<dice_char>;

	cout << "first_dice_set->add({ {'a',3}, {'b', 4}, {'c', 1} });" << endl

		<< "first_dice_set->add({ {'a',1}, {'b', 1}, {'c', 1}, {'d', 2} });" << endl

		<< "second_dice_set->add({ {'a',3}, {'b', 4}, {'c', 1} });" << endl

		<< "second_dice_set->add({ {'a',1}, {'b', 1}, {'c', 1}, {'d', 2} });" << endl;


	first_dice_set->add({ {'a',3}, {'b', 4}, {'c', 1} });

	first_dice_set->add({ {'a',1}, {'b', 1}, {'c', 1}, {'d', 2} });

	second_dice_set->add({ {'a',3}, {'b', 4}, {'c', 1} });

	second_dice_set->add({ {'a',1}, {'b', 1}, {'c', 1}, {'d', 2} });




	cout << "SUMS FIRST" << endl;
	auto sums = first_dice_set->combinations_chances_sums();

	for (const auto& a : sums)
	{
		cout << a.first << " " << a.second << endl;
	}
	
	cout << "SUMS SECOND" << endl;
	sums = second_dice_set->combinations_chances_sums();

	for (const auto& a : sums)
	{
		cout << a.first << " " << a.second << endl;
	}

	third_dice_set->add({ {'a',3}, {'b', 3} });

	dice_list_int_graph->insert(first_dice_set);

	dice_list_int_graph->insert(first_dice_set);

	dice_list_int_graph->connect(0, 1, third_dice_set);

	dice_list_int_graph->erase(1);

	cout << "third_dice_set->add({ {'a',3}, {'b', 3} });" << endl

		<< "dice_list_int_graph->insert(first_dice_set);" << endl

		<< "dice_list_int_graph->insert(first_dice_set);" << endl

		<< "dice_list_int_graph->connect(0, 1, third_dice_set);" << endl

		<< "dice_list_int_graph->erase(1);" << endl;

	dice_list_int_graph->print();

	delete dice_list_int_graph;
}
