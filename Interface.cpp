#include "Interface.h"

/*__________����__________*/
void Interface::main_menu()
{
	int choice = 1;
	for (; choice;)
	{
		setColor(5);
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		setColor(2);
		cout << "_______#####_____________MENU______________#####_______" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(6);
		cout << ">> 1 - �����." << endl;
		cout << ">> 2 - �����������." << endl;
		setColor(12);
		cout << ">> 0 - �����." << endl;
		setColor(6);
		choice = input_int(cin, 0, 2);

		switch (choice)
		{
		case 0:
			
			system("CLS");
			break;

		case 1:

			//*����*//
			system("CLS");
			signing_menu();
			break;

		case 2:
			//*�����������*//
			system("CLS");
			registretion();
			break;
		}

	}
}

/*__________����������� ��������__________*/
void Interface::registretion()
{
	Member obj;
	//*�������� ����*//
	checking_id(obj);
	//*������ �� ����� �������������*//
	member.readQueueFromfile(file2);
	cout << "������� ���(�� ������� �����):" << endl;
	input_rus(cin, obj.get_name());
	cout << "������� �������(�� ������� �����):" << endl;
	input_rus(cin, obj.get_second_name());
	cout << "������� ������:" << endl;
	input_password(cin, obj.get_password());
	system("CLS");
	obj.get_status() = 0;
	//*����������� ������ ������������*//
	member.push_back(obj);
	member.writeQueueInfile(file2);
	//*����� ���� ������������*//
	menu_user(obj.get_id());
}

/*__________���� �����__________*/
void Interface::signing_menu()
{
	int choice = 1;
	for (; choice;)
	{
		setColor(5);
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		setColor(2);
		cout << "_______#####_______SIGNING_____MENU________#####_______" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(6);
		cout << ">> 1 - ����� ��� �������������." << endl;
		cout << ">> 2 - ����� ��� ������������." << endl;
		setColor(12);
		cout << ">> 0 - �����." << endl;
		setColor(6);
		choice = input_int(cin, 0, 2);

		switch (choice)
		{
		case 0:

			system("CLS");
			break;

		case 1:
			//*���� ��� �������������*//
			system("CLS");
			signing_admin();
			break;

		case 2:
			//*���� ��� �������������*//
			system("CLS");
			signing_member();
			break;
		}

	}
}

/*__________���� ����� ��������������__________*/
void Interface::signing_admin()
{
	//*������ ���� ��������������� �� �����*//
	admin.readQueueFromfile(file1);
	char password[password_length];  //������
	char name[length_12];            //���
	char sur[length_12];             //�������
	date DATA;                       //���� �����
	int flag = 0;                    //���� �����
	cout << "������� ���(�� ������� �����):" << endl;
	input_rus(cin, name);
	cout << "������� �������(�� ������� �����):" << endl;
	input_rus(cin, sur);
	cout << "������� ������:" << endl;
	input_password(cin, password);
	cout << "������� ���� �����:" << endl;
	cin >> DATA;
	system("CLS");
	try
	{
		//*���� �������� ������*//
		if (!strcmp(password, pass) and !strcmp(name, nam) 
			and !strcmp(sur, fam))
		{
			admin.writeQueueInfile(file1);
			setColor(2);
			cout << "�� ������� �����!" << endl;
			setColor(6);
			menu_tech(DATA);
		}
		else
		{
			//*���� ���������������*//
			for (int i = 0; i < admin.size(); ++i)
			{
				if (!strcmp(password, admin[i].get_password())
					and !strcmp(name, admin[i].get_name())
					and !strcmp(sur, admin[i].get_second_name()))
				{
					flag = 1;
					admin[i].get_time_of_work() = DATA;
					setColor(2);
					cout << "�� ������� �����!" << endl;
					setColor(6);
					admin.writeQueueInfile(file1);
					//*����� ���� ���������������*//
					menu_tech(DATA);
				}
			}
			if (!flag)
				throw Input_error(11, "�������� ���� ������",
					"��������� ��� � ������ �� �������");
		}
	}
	catch (Input_error obj)
	{
		obj.show_e();
		admin.writeQueueInfile(file1);
	}
}

/*__________���� ����� ��������__________*/
void Interface::signing_member()
{
	//*������ ���� ��������� �� �����*//
	member.readQueueFromfile(file2);
	char password[password_length];  //������
	char name[length_12];            //���
	char sur[length_12];             //�������
	int ID = 0;                      //���� ������������
	int flag = 0;                    //���� �����
	cout << "������� ���(�� ������� �����):" << endl;
	input_rus(cin, name);
	cout << "������� �������(�� ������� �����):" << endl;
	input_rus(cin, sur);
	cout << "������� ������:" << endl;
	input_password(cin, password);
	system("CLS");
	try
	{
		//*���� ���������*//
		for (int i = 0; i < member.size(); ++i)
		{
			if (!strcmp(password, member[i].get_password())
				and !strcmp(name, member[i].get_name())
				and !strcmp(sur, member[i].get_second_name()))
			{
				flag = 1;
				if (member[i].get_status())
					throw Input_error(11, "�� �������������",
						"���������� � ������ ��������� VK: n1_ta");
				ID = member[i].get_id();
				setColor(2);
				cout << "�� ������� �����!" << endl;
				setColor(6);
				member.writeQueueInfile(file2);
				menu_user(ID);
			}
		}
		if (!flag)
			throw Input_error(11, "�������� ���� ������",
				"��������� ��� � ������ �� �������");
	}
	catch (Input_error obj)
	{
		obj.show_e();
		member.writeQueueInfile(file2);
	}
}

/*_________���� ��� ���������__________*/
void Interface::menu_user(int ID)
{
	Active_Lit req;  //������ ������ ���������� ��� ��������� ��������
	int flag = 0;    //���� ��� ��������� ��������
	active_lit.readQueueFromfile(file7);
	int choice = 1;
	for (; choice;)
	{
		setColor(5);
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		setColor(2);
		cout << "_______#####_______MEMBER_______MENU_______#####_______" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(6);
		cout << ">> 1 - �������� ������������." << endl;
		cout << ">> 2 - ������� �����." << endl;
		cout << ">> 3 - �������� ���� ������� ��������." << endl;
		cout << ">> 4 - ������ �� ����������." << endl;
		cout << ">> 5 - ������ �� �������������� �����." << endl;
		cout << ">> 6 - ������ �� ����������� �����." << endl;
		cout << ">> 7 - ������ �� ������-�������������� �����." << endl;
		setColor(12);
		cout << ">> 0 - �����." << endl;
		setColor(6);
		choice = input_int(cin, 0, 7);
		switch (choice)
		{
		case 0:

			system("cls");
			break;

		case 1:
			//*�������� ������������*//
			system("cls");
			req.table();
			flag = 0;
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				//*���� �� ������������*//
				for (auto it = active_lit.begin(); it != active_lit.end(); it++)
				{
					if ((*it).get_id_user() == ID and (*it).get_status() == 3)
					{
						cout << *it;
						flag = 1;
					}
				}

				if (!flag)
				{
					system("cls");
					setColor(2);
					cout << "������������ ���!" << endl;
					setColor(6);
				}
			}
			catch (Container_error obj)
			{
				system("CLS");
				obj.show_e();
			}

			break;

		case 2:

			//*������� �����*//
			system("cls");
			flag = 0;
			req.table();
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				//*���� �� ������������*//
				for (auto it = active_lit.begin(); it != active_lit.end(); it++)
				{
					if ((*it).get_id_user() == ID and (*it).get_status() == 3)
					{
						cout << *it;
						flag = 1;
					}
				}

				if (!flag)
				{
					system("cls");
					setColor(2);
					cout << "������������ ���!" << endl;
					setColor(6);
				}
				else
				{
					cout << "������� ���� ����� ������� ������ �������:" << endl;
					int check = input_int(cin, 0, 9999);
					setColor(12);
					cout << ">> 0 - �����." << endl;
					setColor(6);
					if (!check)
					{
						system("CLS");
						break;
					}
					//��������� ������� �� ����
					int pos = active_lit.get_pos_by_id(check);

					if (pos == -1)
					{
						throw Container_error(7, "����� �� �������",
							"�������� �������� ��������� ������ ��������");
					}
					else
					{
						system("cls");
						setColor(2);
						cout << "������ ���������!" << endl;
						setColor(6);
						active_lit[pos].set_status(1);
					}
				}
			}
			catch (Container_error obj)
			{
				system("CLS");
				obj.show_e();
			}
			break;

		case 3:
			//*�������� ���� ������� ��������*//
			system("cls");
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				req.table();
				flag = 0;
				//*���� �� ������������*//
				for (auto it = active_lit.begin(); it != active_lit.end(); it++)
				{
					if ((*it).get_id_user() == ID)
					{
						cout << *it;
						flag = 1;
					}
				}

				if (!flag)
				{
					system("cls");
					setColor(2);
					cout << "������� �����!" << endl;
					setColor(6);
				}
			}
			catch (Container_error obj)
			{
				system("CLS");
				obj.show_e();
			}
			break;

		case 4:
			//*������ �� ����������*//
			system("cls");
			req = request(audio, file3, ID);
			if (req.get_id_lit() != -1)
			{
				active_lit.push_back(req);
			}
			break;

		case 5:
			//*������ �� �������������� ������*//
			system("cls");
			req = request(fiction_book, file4, ID);
			if (req.get_id_lit() != -1)
			{
				active_lit.push_back(req);
			}
			break;

		case 6:
			//*������ �� ����������� ������*//
			system("cls");
			req = request(technical_book, file5, ID);
			if (req.get_id_lit() != -1)
			{
				active_lit.push_back(req);
			}
			break;

		case 7:
			//*������ �� �������������� ������*//
			system("cls");
			req = request(cognitive_book, file6, ID);
			if (req.get_id_lit() != -1)
			{
				active_lit.push_back(req);
			}
			break;

		default:
			system("cls");
			break;
		}
	}
	active_lit.writeQueueInfile(file7);
}

/*__________������ �� ������ �����_________*/
template <class T>
Active_Lit Interface::request(Queue<T>& obj, const char* filename, int ID)
{
	Active_Lit req;  //������ ��� ��������� �������
	T for_add;       //��� ������
	Algos<T> point;  //������ ���������
	Queue<T> res;    //��� ���������� ������
	//*������ ������� �� �����*//
	obj.readQueueFromfile(filename);
	try
	{
		if (!obj.size())
		{
			throw Container_error(6, "������� �����",
				"�������� �������� ��������� ������ ��������");
		}
		else
		{
			//���� ��� ������
			for_add = for_add.menu_for_poisk();
			cout << "��������� �� ������� �����:" << endl;
			for_add.table();
			cout << for_add;
			//*�����*//
			for (auto it = obj.begin();; ++it)
			{
				it = point.poisk(it, obj.end(), for_add);
				if (it == obj.end())
					break;
				res.push_back(*it);
			}
			cout << "��������� ������:" << endl;
			if (!res.empty())res.get_example_zero().table();
			res.show(0);
		}

		if (res.empty())
			throw Container_error(6, "������� �����",
				"�������� �������� ��������� ������ ��������");

		setColor(2);
		cout << ">> ������� ���� ����� ��� ������:" << endl;
		setColor(6);
		setColor(12);
		cout << ">> 0 - �����." << endl;
		setColor(6);
		int check = input_int(cin, 0, 9999);
		if (!check)
		{
			obj.writeQueueInfile(filename);
			system("CLS");
			return req;
		}
		//*��������� ������� �� ����*//
		int pos = res.get_pos_by_id(check);

		if (pos == -1)
			throw Container_error(7, "����� �� �������",
				"�������� �������� ��������� ������ ��������");
		else
		{
			system("cls");
			setColor(2);
			cout << "������ ���������!" << endl;
			setColor(6);
			req.set_id_lit(res[pos].get_id());
			req.set_id_user(ID);
			req.set_status(0);
		}

	}
	catch (Container_error obj)
	{
		system("CLS");
		obj.show_e();
	}
	obj.writeQueueInfile(filename);
	return req;
}


/*__________�������������� ����__________*/
template <class T>
void Interface::menu_func(Queue<T>& obj, const char* filename)
{
	Algos<T> point;       //����� ���������
	int pos;              //��� ������ �������
	int choice = 1;       //��� ������ �����
	Queue<T> res;         //��� ���������� ������
	//*������ ������� �� �����*//
	obj.readQueueFromfile(filename);
	//*���� ��� ������ ��������*//
	list<Queue<T> > Q;
	for (; choice;)
	{
		if (standart_MAX <= Q.size())
		{
			Q.pop_back();
		}
		T for_add;        //������ ��� ����������
		//*�������� ���� �� ������*//
		checking_id(for_add);
		setColor(5);
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		setColor(2);
		cout << "_______#####______FUNCTION_______MENU______#####_______" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(6);
		cout << ">>  1 - ����� � ������." << endl;
		cout << ">>  2 - ����� � �����." << endl;
		cout << ">>  3 - ���������� � �����." << endl;
		cout << ">>  4 - ���������� � ������." << endl;
		cout << ">>  5 - ���������� �� �������." << endl;
		cout << ">>  6 - �������� �� �����." << endl;
		cout << ">>  7 - �������� �� ������." << endl;
		cout << ">>  8 - �������� �� ����." << endl;
		cout << ">>  9 - ��������� ���������� �� ����." << endl;
		cout << ">> 10 - ���������� �� ��������." << endl;
		cout << ">> 11 - ���������� �� �����������." << endl;
		cout << ">> 12 - �����." << endl;
		cout << ">> 13 - ������ �������." << endl;
		cout << ">> 14 - ������ ��������." << endl;
		setColor(12);
		cout << ">> 0 - �����." << endl;
		setColor(6);
		choice = input_int(cin, 0, 14);
		switch (choice)
		{
		case 0:

			obj.writeQueueInfile(filename);
			system("cls");
			break;

		case 1:
			//*����� � ������*//
			system("cls");
			if (!obj.empty())obj.get_example_zero().table();
			obj.show(0);
			break;

		case 2:
			//*����� � �����*//
			system("cls");
			if (!obj.empty())obj.get_example_zero().table();
			obj.show(1);
			break;

		case 3:
			//*���������� � �����*//
			Q.push_front(obj); //���������� �������� 
			system("cls");
			setColor(2);
			cout << "������� ����������:" << endl;
			setColor(6);
			cin >> for_add;
			obj.push_back(for_add);
			setColor(2);
			cout << "������� ��������!" << endl;
			setColor(6);
			break;

		case 4:
			//*���������� � ������*//
			Q.push_front(obj); //���������� �������� 
			system("cls");
			setColor(2);
			cout << "������� ����������:" << endl;
			setColor(6);
			cin >> for_add;
			obj.push_front(for_add);
			setColor(2);
			cout << "������� ��������!" << endl;
			setColor(6);
			break;

		case 5:
			//*���������� �� �������*//
			Q.push_front(obj); //���������� �������� 
			system("cls");
			setColor(2);
			cout << "������� ������:" << endl;
			setColor(6);
			pos = input_int(cin, 0, obj.size());
			setColor(2);
			cout << "������� ����������:" << endl;
			setColor(6);
			cin >> for_add;
			obj.push_any(for_add, pos);
			setColor(2);
			cout << "������� ��������!" << endl;
			setColor(6);
			break;

		case 6:
			//*�������� � �����*//
			Q.push_front(obj); //���������� �������� 
			system("cls");
			obj.pop_back();
			break;

		case 7:
			//*�������� � ������*//
			Q.push_front(obj); //���������� �������� 
			system("cls");
			obj.pop_front();
			setColor(2);
			cout << "������� ������ �� ������!" << endl;
			setColor(6);
			break;

		case 8:
			//*�������� �� ����*//
			Q.push_front(obj);
			system("cls");
			for (;;)
			{
				try
				{
					if (obj.empty())
						throw Container_error(6, "������� �����",
							"�������� �������� ��������� ������ ��������");

					obj.get_example_zero().table();
					obj.show(0);
					setColor(2);
					cout << ">> ������� ���� ������� ��� ��������:" << endl;
					setColor(4);
					cout << ">> 0 - �����.                          " << endl;
					setColor(6);
					int check = input_int(cin, 0, 9999);
					if (!check)
					{
						system("CLS");
						break;
					}
					int pos = obj.get_pos_by_id(check);

					if (pos == -1)
						throw Container_error(7, "������������ �� ������",
							"�������� �������� ��������� ������ ��������");
					system("cls");
					obj.pop_any(pos);
				}
				catch (Container_error obj)
				{
					system("CLS");
					obj.show_e();
					break;
				}
			}
			break;

		case 9:
			//*��������� �� ����*//
			Q.push_front(obj); //���������� �������� 
			system("cls");
			for (;;)
			{
				try
				{
					if (obj.empty())
						throw Container_error(6, "������� �����",
							"�������� �������� ��������� ������ ��������");

					obj.get_example_zero().table();
					obj.show(0);
					setColor(2);
					cout << ">> ������� ���� ������� ��� ���������:" << endl;
					setColor(4);
					cout << ">> 0 - �����.                          " << endl;
					setColor(6);
					int check = input_int(cin, 0, 9999);
					if (!check)
					{
						system("CLS");
						break;
					}
					int pos = obj.get_pos_by_id(check);

					if (pos == -1)
						throw Container_error(7, "������������ �� ������",
							"�������� �������� ��������� ������ ��������");
					system("cls");
					obj = menu_correct(obj, obj.size(), pos);
				}
				catch (Container_error obj)
				{
					system("CLS");
					obj.show_e();
					break;
				}
			}
			break;

		case 10:
			
			Q.push_front(obj);  //���������� �������� 
			system("cls");
			try
			{
				if (!obj.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				else
				{
					//*����������*//
					int choice = (*(obj.begin())).menu_sort();
					point.sort(obj.begin(), obj.end(),
						[](T& ob1, T& ob2)
						{
							return ob1 > ob2;
						}
					, choice);
					system("cls");
					setColor(2);
					cout << "������� �������������!" << endl;
					setColor(7);
				}
			}
			catch (Container_error e)
			{
				e.show_e();
			}
			break;

		case 11:
			
			Q.push_front(obj); //���������� �������� 
			system("cls");
			try
			{
				if (!obj.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				else
				{
					//*����������*//
					int choice = (*(obj.begin())).menu_sort();
					point.sort(obj.begin(), obj.end(),
						[](T& ob1, T& ob2)
						{
							return ob1 < ob2;
						}
					, choice);
					system("cls");
					setColor(2);
					cout << "������� �������������!" << endl;
					setColor(7);
				}
			}
			catch (Container_error e)
			{
				e.show_e();
			}
			break;

		case 12:

			system("cls");
			try
			{
				if (!obj.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				else
				{
					for_add = for_add.menu_for_poisk();
					cout << "��������� �� ������� �����:" << endl;
					for_add.table();
					cout << for_add;
					//*�����*//
					for (auto it = obj.begin();; ++it)
					{
						it = point.poisk(it, obj.end(), for_add);
						if (it == obj.end()) 
							break;
						res.push_back(*it);
					}
					cout << "��������� ������:" << endl;
					if (!res.empty())res.get_example_zero().table();
					res.show(0);
					res.clear();
				}
			}
			catch (Container_error e)
			{
				e.show_e();
			}
			system("cls");

			break;

		case 13:
			//*������� �������*//
			Q.push_front(obj); //���������� �������� 
			system("cls");
			obj.clear();
			setColor(2);
			cout << "������� �������!" << endl;
			setColor(6);
			break;

		case 14:
			//*������ ��������*//
			system("cls");
			if (Q.size())
			{
				obj = Q.front();
				Q.pop_front();
			}
			break;

		default:

			system("cls");
			break;
		}
	}
}

/*_________���� ��� �������������__________*/
void Interface::menu_tech(date DATA)
{
	int choice = 1;
	for (; choice;)
	{
		setColor(5);
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		setColor(2);
		cout << "_______#####_______ADMIN________MENU_______#####_______" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(6);
		cout << ">> 1 - ���������� ����������� ����� � ��������������." << endl;
		cout << ">> 2 - ���������� ����������� ����� � ��������������." << endl;
		cout << ">> 3 - ���������� ����������� ����� � ������������." << endl;
		cout << ">> 4 - ���������� ����������� ����� � ��������������� �������." << endl;
		cout << ">> 5 - ���������� ����������� ����� � ������������ �������." << endl;
		cout << ">> 6 - ���������� ����������� ����� � ������-��������������� �������." << endl;
		cout << ">> 7 - ��������� ��������." << endl;
		setColor(12);
		cout << ">> 0 - �����." << endl;
		setColor(6);
		choice = input_int(cin, 0, 7);
		switch (choice)
		{
		case 0:
			system("cls");
			break;

		case 1:
			//*����������� ������ � ��������*// 
			system("cls");
			menu_func(admin, file1);
			break;

		case 2:
			//*����������� ������ � ����������*// 
			system("cls");
			menu_func(member, file2);
			break;

		case 3:
			//*����������� ������ � ������������*// 
			system("cls");
			menu_func(audio, file3);
			break;

		case 4:
			//*����������� ������ � ��������������� �������*// 
			system("cls");
			menu_func(fiction_book, file4);
			break;

		case 5:
			//*����������� ������ � ������������ �������*// 
			system("cls");
			menu_func(technical_book, file5);
			break;

		case 6:
			//*����������� ������ � ��������������� �������*// 
			system("cls");
			menu_func(cognitive_book, file6);
			break;

		case 7:
			//*����� ��������� ��������*// 
			system("cls");
			menu_request(DATA);
			break;

		default:

			system("cls");
			break;
		}
	}
}

/*__________����� ��������� ��������_________*/
void Interface::menu_request(date DATA)
{
	int flag = 0;         //���� ��� ���������
	date DATA_ret = DATA; //���� �������� �����
	DATA_ret.year++;
	//*������ ������� � ���������*//
	active_lit.readQueueFromfile(file7);
	int choice = 1;
	for (; choice;)
	{

		setColor(5);
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		setColor(2);
		cout << "_______#####_______ADMIN________MENU_______#####_______" << endl;
		setColor(5);
		cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
		cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
		setColor(6);
		cout << ">> 1 - ������ ����." << endl;
		cout << ">> 2 - ����� ����." << endl;
		cout << ">> 3 - �������� ������������." << endl;
		cout << ">> 4 - �������� ���� �������." << endl;
		cout << ">> 5 - ������� �������(����� �������� � �������� ����)." << endl;
		setColor(12);
		cout << ">> 0 - �����." << endl;
		setColor(6);
		choice = input_int(cin, 0, 5);
		switch (choice)
		{
		case 0:

			system("cls");
			break;

		case 1:
			//������ ����
			system("cls");
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}

				flag = 0;
				//���� �� ��������
				for (auto it = active_lit.begin(); it != active_lit.end(); it++)
				{
					if ((*it).get_status() == 0)
					{
						flag = 1;
						(*it).table();
						cout << *it;
						cout << "0 - �����." << endl;
						cout << "1 - �� �������� �����." << endl;
						cout << "2 - ������ �����." << endl;
						int choice = input_int(cin, 0, 2);
						if (!choice)
						{
							system("cls");
							break;
						}
						if (choice == 1)
						{
							//����� ������� �� ��������
							(*it).get_status() = 2;
							system("cls");
							setColor(2);
							cout << "����� �� ������!" << endl;
							setColor(6);
						}
						else
						{
							//�������� ���� �� ����� ����
							if (!get_no_active_lit((*it).get_id_lit()))
							{
								//����� ������� �� ��������
								(*it).get_status() = 2;
								system("cls");
								setColor(2);
								cout << "����� �� ������!���������� ����� � ���������� �����������!" 
									<< endl;
								setColor(6);
							}
							else
							{
								//����� ������� �� ������
								(*it).get_status() = 3;
								//���� ���������� ����� � ����������
								add_no_active_lit((*it).get_id_lit(), -1);
								(*it).set_date_issuance(DATA);
								(*it).set_date_ret(DATA_ret);
								system("cls");
								setColor(2);
								cout << "����� ������!" << endl;
								setColor(6);
							}
						}
					}
				}

				if (!flag)
				{
					system("cls");
					setColor(2);
					cout << "�������� ���!" << endl;
					setColor(6);
				}
			}
			catch (Container_error err)
			{
				system("cls");
				err.show_e();
			}
			break;

		case 2:
			//����� ����
			system("cls");
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}

				flag = 0;
				//���� �� ��������
				for (auto it = active_lit.begin(); it != active_lit.end(); it++)
				{
					if ((*it).get_status() == 1)
					{
						flag = 1;
						(*it).table();
						cout << *it;
						cout << "0 - �����." << endl;
						cout << "1 - ������� �����." << endl;
						int choice = input_int(cin, 0, 1);
						if (!choice)
						{
							system("cls");
							break;
						}
						else
						{
							//����� ������� �� ����������
							(*it).get_status() = 4;
							//���� ���� � ����������
							add_no_active_lit((*it).get_id_lit(), 1);
							system("cls");
							setColor(2);
							cout << "����� ����������!" << endl;
							setColor(6);	
						}
					}
				}

				if (!flag)
				{
					system("cls");
					setColor(2);
					cout << "�������� ���!" << endl;
					setColor(6);
				}
			}
			catch (Container_error err)
			{
				system("cls");
				err.show_e();
			}
			break;

		case 3:
			//����� ������������
			system("cls");
			flag = 0;
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				//���� �� ��������
				for (auto it = active_lit.begin(); it != active_lit.end(); it++)
				{
					if ((*it).get_status() == 3)
					{
						if (!flag)
							(*it).table();
						cout << *it;
						flag = 1;
					}
				}

				if (!flag)
				{
					system("cls");
					setColor(2);
					cout << "������������ ���!" << endl;
					setColor(6);
				}
			}
			catch (Container_error err)
			{
				system("cls");
				err.show_e();
			}
			break;

		case 4:
			//����� ������� ��������
			system("cls");
			flag = 0;
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				//���� �� ��������
				for (auto it = active_lit.begin(); it != active_lit.end(); it++)
				{
					if (!flag)
						(*it).table();
					cout << *it;
					flag = 1;
				}

				if (!flag)
				{
					system("cls");
					setColor(2);
					cout << "������������ ���!" << endl;
					setColor(6);
				}
			}
			catch (Container_error err)
			{
				system("cls");
				err.show_e();
			}
			break;

		case 5:

			system("cls");
			flag = 0;
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "������� �����",
						"�������� �������� ��������� ������ ��������");
				}
				//���� �� ��������
				for (int i = 0; i < active_lit.size(); i++)
				{
					if (active_lit[i].get_status() != 3
						and active_lit[i].get_status() != 1
						and active_lit[i].get_status() != 0)
					{
						active_lit.pop_any(i);
						i--;
						flag = 1;
					}
				}

				if (!flag)
				{
					system("cls");
					setColor(2);
					cout << "������� ���!" << endl;
					setColor(6);
				}
				else
				{
					system("cls");
					setColor(2);
					cout << "������� �������!" << endl;
					setColor(6);
				}
			}
			catch (Container_error err)
			{
				system("cls");
				err.show_e();
			}
			break;

		default:
			system("cls");
			break;
		}
	}
	//������ �������� � ����
	active_lit.writeQueueInfile(file7);
}

/*__________������� �������� ���� �� ��������������__________*/
template <class T>
void Interface::checking_id(T obj)
{
	//���������� ���� ����� ����� ��� ����������� �������
	int pos = -1;
	if (!admin.size())
		admin.readQueueFromfile(file1);
	else
		pos = 1;

	if (!member.size())
		member.readQueueFromfile(file2);
	else
		pos = 2;

	if (!audio.size())
		audio.readQueueFromfile(file3);
	else
		pos = 3;

	if (!fiction_book.size())
		fiction_book.readQueueFromfile(file4);
	else
		pos = 4;

	if (!technical_book.size())
		technical_book.readQueueFromfile(file5);
	else
		pos = 5;

	if (!cognitive_book.size())
		cognitive_book.readQueueFromfile(file6);
	else
		pos = 6;

	//����� ���� �� ����� � ������ ���������� ���������
	int flag = 1;
	for (; flag;)
	{
		flag = 0;
		if (admin.find_id(obj.get_id()))
		{
			obj.get_id() = rand() % (rand() % 10000);
			flag = 1;
		}

		if (member.find_id(obj.get_id()))
		{
			obj.get_id() = rand() % (rand() % 10000);
			flag = 1;
		}

		if (fiction_book.find_id(obj.get_id()))
		{
			obj.get_id() = rand() % (rand() % 10000);
			flag = 1;
		}

		if (audio.find_id(obj.get_id()))
		{
			obj.get_id() = rand() % (rand() % 10000);
			flag = 1;
		}

		if (cognitive_book.find_id(obj.get_id()))
		{
			obj.get_id() = rand() % (rand() % 10000);
			flag = 1;
		}

		if (technical_book.find_id(obj.get_id()))
		{
			obj.get_id() = rand() % (rand() % 10000);
			flag = 1;
		}
	}

	//���������� ������
	if (pos != 1)
		admin.writeQueueInfile(file1);
	if (pos != 2)
		member.writeQueueInfile(file2);
	if (pos != 3)
		audio.writeQueueInfile(file3);
	if (pos != 4)
		fiction_book.writeQueueInfile(file4);
	if (pos != 5)
		technical_book.writeQueueInfile(file5);
	if (pos != 6)
		cognitive_book.writeQueueInfile(file6);
}