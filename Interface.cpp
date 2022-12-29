#include "Interface.h"

/*__________меню__________*/
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
		cout << ">> 1 - войти." << endl;
		cout << ">> 2 - регистрация." << endl;
		setColor(12);
		cout << ">> 0 - выйти." << endl;
		setColor(6);
		choice = input_int(cin, 0, 2);

		switch (choice)
		{
		case 0:
			
			system("CLS");
			break;

		case 1:

			//*ВХОД*//
			system("CLS");
			signing_menu();
			break;

		case 2:
			//*РЕГИСТРАЦИЯ*//
			system("CLS");
			registretion();
			break;
		}

	}
}

/*__________регистрация читателя__________*/
void Interface::registretion()
{
	Member obj;
	//*ПРОВЕРКА АЙДИ*//
	checking_id(obj);
	//*ЧТЕНИЕ ИЗ ФАЙЛА ПОЛЬЗОВАТЕЛЕЙ*//
	member.readQueueFromfile(file2);
	cout << "Введите имя(на русском языке):" << endl;
	input_rus(cin, obj.get_name());
	cout << "Введите фамилию(на русском языке):" << endl;
	input_rus(cin, obj.get_second_name());
	cout << "Введите пароль:" << endl;
	input_password(cin, obj.get_password());
	system("CLS");
	obj.get_status() = 0;
	//*ПДОБАВЛЕНИЕ НОВОГО ПОЛЬЗОВАТЕЛЯ*//
	member.push_back(obj);
	member.writeQueueInfile(file2);
	//*ВЫЗОВ МЕНЮ ПОЛЬЗОВАТЕЛЯ*//
	menu_user(obj.get_id());
}

/*__________меню входа__________*/
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
		cout << ">> 1 - войти как АДМИНИСТРАТОР." << endl;
		cout << ">> 2 - войти как ПОЛЬЗОВАТЕЛЬ." << endl;
		setColor(12);
		cout << ">> 0 - выйти." << endl;
		setColor(6);
		choice = input_int(cin, 0, 2);

		switch (choice)
		{
		case 0:

			system("CLS");
			break;

		case 1:
			//*ВХОД ДЛЯ АДМИНИСТРАЦИИ*//
			system("CLS");
			signing_admin();
			break;

		case 2:
			//*ВХОД ДЛЯ ПОЛЬЗОВАТЕЛЕЙ*//
			system("CLS");
			signing_member();
			break;
		}

	}
}

/*__________меню входа администратора__________*/
void Interface::signing_admin()
{
	//*ЧТЕНИЕ ВСЕХ АДМИНИСТРАТОРОВ ИЗ ФАЙЛА*//
	admin.readQueueFromfile(file1);
	char password[password_length];  //пароль
	char name[length_12];            //имя
	char sur[length_12];             //фамилия
	date DATA;                       //дата входа
	int flag = 0;                    //флаг входа
	cout << "Введите имя(на русском языке):" << endl;
	input_rus(cin, name);
	cout << "Введите фамилию(на русском языке):" << endl;
	input_rus(cin, sur);
	cout << "Введите пароль:" << endl;
	input_password(cin, password);
	cout << "Введите дату входа:" << endl;
	cin >> DATA;
	system("CLS");
	try
	{
		//*ВХОД ГЛАВНОГО АДМИНА*//
		if (!strcmp(password, pass) and !strcmp(name, nam) 
			and !strcmp(sur, fam))
		{
			admin.writeQueueInfile(file1);
			setColor(2);
			cout << "Вы успешно вошли!" << endl;
			setColor(6);
			menu_tech(DATA);
		}
		else
		{
			//*ВХОД АДМИНИСТРАТОРОВ*//
			for (int i = 0; i < admin.size(); ++i)
			{
				if (!strcmp(password, admin[i].get_password())
					and !strcmp(name, admin[i].get_name())
					and !strcmp(sur, admin[i].get_second_name()))
				{
					flag = 1;
					admin[i].get_time_of_work() = DATA;
					setColor(2);
					cout << "Вы успешно вошли!" << endl;
					setColor(6);
					admin.writeQueueInfile(file1);
					//*ВЫЗОВ МЕНЮ АДМИНИСТРАТОРОВ*//
					menu_tech(DATA);
				}
			}
			if (!flag)
				throw Input_error(11, "Неверный ввод данных",
					"Введенные ФИО и пароль не найдены");
		}
	}
	catch (Input_error obj)
	{
		obj.show_e();
		admin.writeQueueInfile(file1);
	}
}

/*__________меню входа читателя__________*/
void Interface::signing_member()
{
	//*ЧТЕНИЕ ВСЕХ ЧИТАТЕЛЕЙ ИЗ ФАЙЛА*//
	member.readQueueFromfile(file2);
	char password[password_length];  //пароль
	char name[length_12];            //имя
	char sur[length_12];             //фамилия
	int ID = 0;                      //айди пользователя
	int flag = 0;                    //флаг входа
	cout << "Введите имя(на русском языке):" << endl;
	input_rus(cin, name);
	cout << "Введите фамилию(на русском языке):" << endl;
	input_rus(cin, sur);
	cout << "Введите пароль:" << endl;
	input_password(cin, password);
	system("CLS");
	try
	{
		//*ВХОД ЧИТАТЕЛЕЙ*//
		for (int i = 0; i < member.size(); ++i)
		{
			if (!strcmp(password, member[i].get_password())
				and !strcmp(name, member[i].get_name())
				and !strcmp(sur, member[i].get_second_name()))
			{
				flag = 1;
				if (member[i].get_status())
					throw Input_error(11, "Вы заблокированы",
						"Обратитесь в службу поддержки VK: n1_ta");
				ID = member[i].get_id();
				setColor(2);
				cout << "Вы успешно вошли!" << endl;
				setColor(6);
				member.writeQueueInfile(file2);
				menu_user(ID);
			}
		}
		if (!flag)
			throw Input_error(11, "Неверный ввод данных",
				"Введенные ФИО и пароль не найдены");
	}
	catch (Input_error obj)
	{
		obj.show_e();
		member.writeQueueInfile(file2);
	}
}

/*_________меню для читателей__________*/
void Interface::menu_user(int ID)
{
	Active_Lit req;  //объект взятой литературы для обработки запросов
	int flag = 0;    //флаг для обработки запросов
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
		cout << ">> 1 - просмотр задолжностей." << endl;
		cout << ">> 2 - возврат книги." << endl;
		cout << ">> 3 - просмотр всей истории запросов." << endl;
		cout << ">> 4 - запрос на аудиокнигу." << endl;
		cout << ">> 5 - запрос на художественную книгу." << endl;
		cout << ">> 6 - запрос на техническую книгу." << endl;
		cout << ">> 7 - запрос на научно-познавательную книгу." << endl;
		setColor(12);
		cout << ">> 0 - назад." << endl;
		setColor(6);
		choice = input_int(cin, 0, 7);
		switch (choice)
		{
		case 0:

			system("cls");
			break;

		case 1:
			//*просмотр задолжностей*//
			system("cls");
			req.table();
			flag = 0;
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
				}
				//*цикл по задолжностям*//
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
					cout << "Задолжностей нет!" << endl;
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

			//*возврат книги*//
			system("cls");
			flag = 0;
			req.table();
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
				}
				//*цикл по задолжностям*//
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
					cout << "Задолжностей нет!" << endl;
					setColor(6);
				}
				else
				{
					cout << "Введите айди книги которую хотите вернуть:" << endl;
					int check = input_int(cin, 0, 9999);
					setColor(12);
					cout << ">> 0 - назад." << endl;
					setColor(6);
					if (!check)
					{
						system("CLS");
						break;
					}
					//получение позиции по айди
					int pos = active_lit.get_pos_by_id(check);

					if (pos == -1)
					{
						throw Container_error(7, "Книга не найдена",
							"Возможно выхотели выполнить другое действие");
					}
					else
					{
						system("cls");
						setColor(2);
						cout << "Запрос отправлен!" << endl;
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
			//*просмотр всей истории запросов*//
			system("cls");
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
				}
				req.table();
				flag = 0;
				//*цикл по задолжностям*//
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
					cout << "История пуста!" << endl;
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
			//*запрос по айдикнигам*//
			system("cls");
			req = request(audio, file3, ID);
			if (req.get_id_lit() != -1)
			{
				active_lit.push_back(req);
			}
			break;

		case 5:
			//*запрос по художественным книгам*//
			system("cls");
			req = request(fiction_book, file4, ID);
			if (req.get_id_lit() != -1)
			{
				active_lit.push_back(req);
			}
			break;

		case 6:
			//*запрос по техническим книгам*//
			system("cls");
			req = request(technical_book, file5, ID);
			if (req.get_id_lit() != -1)
			{
				active_lit.push_back(req);
			}
			break;

		case 7:
			//*запрос по позновательным книгам*//
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

/*__________запрос на взятие книги_________*/
template <class T>
Active_Lit Interface::request(Queue<T>& obj, const char* filename, int ID)
{
	Active_Lit req;  //объект для обработки запроса
	T for_add;       //для поиска
	Algos<T> point;  //объект алгоритма
	Queue<T> res;    //для результата поиска
	//*чтение очереди из файла*//
	obj.readQueueFromfile(filename);
	try
	{
		if (!obj.size())
		{
			throw Container_error(6, "Очередь пуста",
				"Возможно выхотели выполнить другое действие");
		}
		else
		{
			//меню для поиска
			for_add = for_add.menu_for_poisk();
			cout << "Параметры по которым ищете:" << endl;
			for_add.table();
			cout << for_add;
			//*ПОИСК*//
			for (auto it = obj.begin();; ++it)
			{
				it = point.poisk(it, obj.end(), for_add);
				if (it == obj.end())
					break;
				res.push_back(*it);
			}
			cout << "Результат поиска:" << endl;
			if (!res.empty())res.get_example_zero().table();
			res.show(0);
		}

		if (res.empty())
			throw Container_error(6, "Очередь пуста",
				"Возможно выхотели выполнить другое действие");

		setColor(2);
		cout << ">> Введите айди книги для взятия:" << endl;
		setColor(6);
		setColor(12);
		cout << ">> 0 - назад." << endl;
		setColor(6);
		int check = input_int(cin, 0, 9999);
		if (!check)
		{
			obj.writeQueueInfile(filename);
			system("CLS");
			return req;
		}
		//*получение позиции по айди*//
		int pos = res.get_pos_by_id(check);

		if (pos == -1)
			throw Container_error(7, "Книга не найдена",
				"Возможно выхотели выполнить другое действие");
		else
		{
			system("cls");
			setColor(2);
			cout << "Запрос отправлен!" << endl;
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


/*__________функциональное меню__________*/
template <class T>
void Interface::menu_func(Queue<T>& obj, const char* filename)
{
	Algos<T> point;       //класс алгоритма
	int pos;              //для выбора позиции
	int choice = 1;       //для выбора опций
	Queue<T> res;         //для результата поиска
	//*чтение очереди из файла*//
	obj.readQueueFromfile(filename);
	//*стек для отмены действий*//
	list<Queue<T> > Q;
	for (; choice;)
	{
		if (standart_MAX <= Q.size())
		{
			Q.pop_back();
		}
		T for_add;        //объект для добавления
		//*ПРОВЕРКА АЙДИ НА ПОВТОР*//
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
		cout << ">>  1 - вывод с начала." << endl;
		cout << ">>  2 - вывод с конца." << endl;
		cout << ">>  3 - добавление в конец." << endl;
		cout << ">>  4 - добавление в начало." << endl;
		cout << ">>  5 - добавление по индексу." << endl;
		cout << ">>  6 - удаление из конца." << endl;
		cout << ">>  7 - удаление из начала." << endl;
		cout << ">>  8 - удаление по айди." << endl;
		cout << ">>  9 - изменение параметров по айди." << endl;
		cout << ">> 10 - сортировка по убыванию." << endl;
		cout << ">> 11 - сортировка по возрастанию." << endl;
		cout << ">> 12 - поиск." << endl;
		cout << ">> 13 - полная очистка." << endl;
		cout << ">> 14 - отмена действия." << endl;
		setColor(12);
		cout << ">> 0 - назад." << endl;
		setColor(6);
		choice = input_int(cin, 0, 14);
		switch (choice)
		{
		case 0:

			obj.writeQueueInfile(filename);
			system("cls");
			break;

		case 1:
			//*вывод с начала*//
			system("cls");
			if (!obj.empty())obj.get_example_zero().table();
			obj.show(0);
			break;

		case 2:
			//*вывод с конца*//
			system("cls");
			if (!obj.empty())obj.get_example_zero().table();
			obj.show(1);
			break;

		case 3:
			//*добавление в конец*//
			Q.push_front(obj); //сохранение действия 
			system("cls");
			setColor(2);
			cout << "Введите информацию:" << endl;
			setColor(6);
			cin >> for_add;
			obj.push_back(for_add);
			setColor(2);
			cout << "Элемент добавлен!" << endl;
			setColor(6);
			break;

		case 4:
			//*добавление в начало*//
			Q.push_front(obj); //сохранение действия 
			system("cls");
			setColor(2);
			cout << "Введите информацию:" << endl;
			setColor(6);
			cin >> for_add;
			obj.push_front(for_add);
			setColor(2);
			cout << "Элемент добавлен!" << endl;
			setColor(6);
			break;

		case 5:
			//*добавление по индексу*//
			Q.push_front(obj); //сохранение действия 
			system("cls");
			setColor(2);
			cout << "Введите индекс:" << endl;
			setColor(6);
			pos = input_int(cin, 0, obj.size());
			setColor(2);
			cout << "Введите информацию:" << endl;
			setColor(6);
			cin >> for_add;
			obj.push_any(for_add, pos);
			setColor(2);
			cout << "Элемент добавлен!" << endl;
			setColor(6);
			break;

		case 6:
			//*удаление с конца*//
			Q.push_front(obj); //сохранение действия 
			system("cls");
			obj.pop_back();
			break;

		case 7:
			//*удаление с начала*//
			Q.push_front(obj); //сохранение действия 
			system("cls");
			obj.pop_front();
			setColor(2);
			cout << "Элемент удален из головы!" << endl;
			setColor(6);
			break;

		case 8:
			//*удаление по айди*//
			Q.push_front(obj);
			system("cls");
			for (;;)
			{
				try
				{
					if (obj.empty())
						throw Container_error(6, "Очередь пуста",
							"Возможно выхотели выполнить другое действие");

					obj.get_example_zero().table();
					obj.show(0);
					setColor(2);
					cout << ">> Введите айди объекта для удаления:" << endl;
					setColor(4);
					cout << ">> 0 - назад.                          " << endl;
					setColor(6);
					int check = input_int(cin, 0, 9999);
					if (!check)
					{
						system("CLS");
						break;
					}
					int pos = obj.get_pos_by_id(check);

					if (pos == -1)
						throw Container_error(7, "Пользователь не найден",
							"Возможно выхотели выполнить другое действие");
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
			//*изменение по айди*//
			Q.push_front(obj); //сохранение действия 
			system("cls");
			for (;;)
			{
				try
				{
					if (obj.empty())
						throw Container_error(6, "Очередь пуста",
							"Возможно выхотели выполнить другое действие");

					obj.get_example_zero().table();
					obj.show(0);
					setColor(2);
					cout << ">> Введите айди объекта для изменения:" << endl;
					setColor(4);
					cout << ">> 0 - назад.                          " << endl;
					setColor(6);
					int check = input_int(cin, 0, 9999);
					if (!check)
					{
						system("CLS");
						break;
					}
					int pos = obj.get_pos_by_id(check);

					if (pos == -1)
						throw Container_error(7, "Пользователь не найден",
							"Возможно выхотели выполнить другое действие");
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
			
			Q.push_front(obj);  //сохранение действия 
			system("cls");
			try
			{
				if (!obj.size())
				{
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
				}
				else
				{
					//*сортировка*//
					int choice = (*(obj.begin())).menu_sort();
					point.sort(obj.begin(), obj.end(),
						[](T& ob1, T& ob2)
						{
							return ob1 > ob2;
						}
					, choice);
					system("cls");
					setColor(2);
					cout << "Очередь отсортирована!" << endl;
					setColor(7);
				}
			}
			catch (Container_error e)
			{
				e.show_e();
			}
			break;

		case 11:
			
			Q.push_front(obj); //сохранение действия 
			system("cls");
			try
			{
				if (!obj.size())
				{
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
				}
				else
				{
					//*сортировка*//
					int choice = (*(obj.begin())).menu_sort();
					point.sort(obj.begin(), obj.end(),
						[](T& ob1, T& ob2)
						{
							return ob1 < ob2;
						}
					, choice);
					system("cls");
					setColor(2);
					cout << "Очередь отсортирована!" << endl;
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
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
				}
				else
				{
					for_add = for_add.menu_for_poisk();
					cout << "Параметры по которым ищете:" << endl;
					for_add.table();
					cout << for_add;
					//*ПОИСК*//
					for (auto it = obj.begin();; ++it)
					{
						it = point.poisk(it, obj.end(), for_add);
						if (it == obj.end()) 
							break;
						res.push_back(*it);
					}
					cout << "Результат поиска:" << endl;
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
			//*очистка очереди*//
			Q.push_front(obj); //сохранение действия 
			system("cls");
			obj.clear();
			setColor(2);
			cout << "Очередь очищена!" << endl;
			setColor(6);
			break;

		case 14:
			//*отмена действия*//
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

/*_________меню для администрации__________*/
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
		cout << ">> 1 - выполнение технических работ с администрацией." << endl;
		cout << ">> 2 - выполнение технических работ с пользователями." << endl;
		cout << ">> 3 - выполнение технических работ с аудиокнигами." << endl;
		cout << ">> 4 - выполнение технических работ с художественными книгами." << endl;
		cout << ">> 5 - выполнение технических работ с техническими книгами." << endl;
		cout << ">> 6 - выполнение технических работ с научно-познавательными книгами." << endl;
		cout << ">> 7 - обработка запросов." << endl;
		setColor(12);
		cout << ">> 0 - назад." << endl;
		setColor(6);
		choice = input_int(cin, 0, 7);
		switch (choice)
		{
		case 0:
			system("cls");
			break;

		case 1:
			//*технические работы с админами*// 
			system("cls");
			menu_func(admin, file1);
			break;

		case 2:
			//*технические работы с читателями*// 
			system("cls");
			menu_func(member, file2);
			break;

		case 3:
			//*технические работы с аудиокнигами*// 
			system("cls");
			menu_func(audio, file3);
			break;

		case 4:
			//*технические работы с художественными книгами*// 
			system("cls");
			menu_func(fiction_book, file4);
			break;

		case 5:
			//*технические работы с техническими книгами*// 
			system("cls");
			menu_func(technical_book, file5);
			break;

		case 6:
			//*технические работы с позновательными книгами*// 
			system("cls");
			menu_func(cognitive_book, file6);
			break;

		case 7:
			//*вызов обработки запросов*// 
			system("cls");
			menu_request(DATA);
			break;

		default:

			system("cls");
			break;
		}
	}
}

/*__________метод обработки запросов_________*/
void Interface::menu_request(date DATA)
{
	int flag = 0;         //флаг для обработки
	date DATA_ret = DATA; //дата возврата книги
	DATA_ret.year++;
	//*чтение очереди с запросами*//
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
		cout << ">> 1 - выдача книг." << endl;
		cout << ">> 2 - прием книг." << endl;
		cout << ">> 3 - просмотр задолжностей." << endl;
		cout << ">> 4 - просмотр всей истории." << endl;
		cout << ">> 5 - очистка истории(кроме запросов и выданных книг)." << endl;
		setColor(12);
		cout << ">> 0 - назад." << endl;
		setColor(6);
		choice = input_int(cin, 0, 5);
		switch (choice)
		{
		case 0:

			system("cls");
			break;

		case 1:
			//выдача книг
			system("cls");
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
				}

				flag = 0;
				//цикл по запросам
				for (auto it = active_lit.begin(); it != active_lit.end(); it++)
				{
					if ((*it).get_status() == 0)
					{
						flag = 1;
						(*it).table();
						cout << *it;
						cout << "0 - назад." << endl;
						cout << "1 - не выдавать книгу." << endl;
						cout << "2 - выдать книгу." << endl;
						int choice = input_int(cin, 0, 2);
						if (!choice)
						{
							system("cls");
							break;
						}
						if (choice == 1)
						{
							//смена статуса на отменено
							(*it).get_status() = 2;
							system("cls");
							setColor(2);
							cout << "Книга НЕ выдана!" << endl;
							setColor(6);
						}
						else
						{
							//проверка есть ли копии книг
							if (!get_no_active_lit((*it).get_id_lit()))
							{
								//смена статуса на отменено
								(*it).get_status() = 2;
								system("cls");
								setColor(2);
								cout << "Книга НЕ выдана!Количество копий в библиотеке закончилось!" 
									<< endl;
								setColor(6);
							}
							else
							{
								//смена статуса на выдано
								(*it).get_status() = 3;
								//учет количества копий в библиотеке
								add_no_active_lit((*it).get_id_lit(), -1);
								(*it).set_date_issuance(DATA);
								(*it).set_date_ret(DATA_ret);
								system("cls");
								setColor(2);
								cout << "Книга выдана!" << endl;
								setColor(6);
							}
						}
					}
				}

				if (!flag)
				{
					system("cls");
					setColor(2);
					cout << "Запросов нет!" << endl;
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
			//прием книг
			system("cls");
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
				}

				flag = 0;
				//цикл по запросам
				for (auto it = active_lit.begin(); it != active_lit.end(); it++)
				{
					if ((*it).get_status() == 1)
					{
						flag = 1;
						(*it).table();
						cout << *it;
						cout << "0 - назад." << endl;
						cout << "1 - принять книгу." << endl;
						int choice = input_int(cin, 0, 1);
						if (!choice)
						{
							system("cls");
							break;
						}
						else
						{
							//смена статуса на возвращена
							(*it).get_status() = 4;
							//учет книг в библиотеке
							add_no_active_lit((*it).get_id_lit(), 1);
							system("cls");
							setColor(2);
							cout << "Книга возвращена!" << endl;
							setColor(6);	
						}
					}
				}

				if (!flag)
				{
					system("cls");
					setColor(2);
					cout << "Запросов нет!" << endl;
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
			//вывод задолжностей
			system("cls");
			flag = 0;
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
				}
				//цикл по запросам
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
					cout << "Задолжностей нет!" << endl;
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
			//вывод истории запросов
			system("cls");
			flag = 0;
			try
			{
				if (!active_lit.size())
				{
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
				}
				//цикл по запросам
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
					cout << "Задолжностей нет!" << endl;
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
					throw Container_error(6, "Очередь пуста",
						"Возможно выхотели выполнить другое действие");
				}
				//цикл по запросам
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
					cout << "Истории нет!" << endl;
					setColor(6);
				}
				else
				{
					system("cls");
					setColor(2);
					cout << "История очищена!" << endl;
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
	//запись запросов в файл
	active_lit.writeQueueInfile(file7);
}

/*__________функция проверки айди на оригинальность__________*/
template <class T>
void Interface::checking_id(T obj)
{
	//запоминаем если вошли через уже прочитанную очередь
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

	//смена айди на новое в случае нахождения дубликата
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

	//сохранение данных
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