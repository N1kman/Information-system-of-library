#include "standart.h"
#include "Literature.h"

/*__________ввод русской строки__________*/
char* input_rus(istream& in, char* str)
{
	setColor(13);
	cout << "[" << length_12 - 1 << "]" << endl;
	setColor(6);
	bool flag = false;
	do
	{
		flag = true;
		try
		{
			rewind(stdin);
			in.getline(str, length_12);
			//проверка переполнения строки
			if (!cin)
			{
				cin.clear();
				throw Input_error(4, "Ошибка ввода строки"
					, "Ограничение на 12 символов");
			}
			//проверка на ввод строки
			if (!strlen(str))
				throw Input_error(1, "Ошибка ввода строки"
					, "Строка не введена");
			//проверка на русские символы
			for (size_t i = 0; i < strlen(str); ++i)
			{
				if ((str[i] < 'А' or str[i] >'я') and str[i] != ' ')
					throw Input_error(1, "Ошибка ввода строки"
						, "Введены нерусские буквы");
			}
		}
		catch (Input_error obj)
		{
			obj.show_e();
			flag = false;
		}
	} while (!flag);
	return str;
}

/*__________ввод английской строки__________*/
char* input_eng(istream& in, char* str)
{
	setColor(13);
	cout << "[" << length_12 - 1 << "]" << endl;
	setColor(6);
	bool flag = false;
	do
	{
		flag = true;
		try
		{
			rewind(stdin);
			in.getline(str, length_12);
			//проверка переполнения строки
			if (!cin)
			{
				cin.clear();
				throw Input_error(4, "Ошибка ввода строки",
					"Ограничение на 12 символов");
			}
			//проверка на ввод строки
			if (!strlen(str))
				throw Input_error(1, "Ошибка ввода строки",
					"Строка не введена");
			//проверка на английские символы
			for (size_t i = 0; i < strlen(str); ++i)
			{
				if ((str[i] < 'a' or str[i] >'z') and (str[i] < 'A' or str[i] >'Z')
					and str[i] != ' ' and (str[i] < '0' or str[i] >'9'))
					throw Input_error(1, "Ошибка ввода строки",
						"Введены неанглийские буквы");
			}
		}
		catch (Input_error obj)
		{
			obj.show_e();
			flag = false;
		}
	} while (!flag);
	return str;
}

/*__________ввод целого числа__________*/
int input_int(istream& in, int _a, int _b)
{
	setColor(13);
	cout << "[" << _a << ";" << _b << "]" << endl;
	setColor(6);
	int _int;
	bool flag = false;
	do
	{
		flag = true;
		try
		{
			rewind(stdin);
			in >> _int;
			//проверка введено ли число
			if (cin.peek() != '\n')
			{
				throw Input_error(2, "Ошибка ввода", 
					"Введено не число");
			}
			//проверка введено ли число
			if (!in)
			{
				throw Input_error(2, "Ошибка ввода", 
					"Введено не число");
			}
			//проверка выхода за границу
			if (_int<_a or _int>_b)
			{
				throw Input_error(2, "Ошибка ввода",
					"Выход за границы");
			}
		}
		catch (Input_error obj)
		{
			obj.show_e();
			flag = false;
			in.clear();
		}
	} while (!flag);
	return _int;
}

/*__________функция задания цвета тексту__________*/
void setColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//задание цвета текста
	SetConsoleTextAttribute(hConsole, color | 7 << 4);
}

/*__________перегрузка ввода__________*/
std::istream& operator>>(std::istream& in, date& T)
{
	cout << "Введите день:" << endl;
	T.day = input_int(cin, 1, 31);
	cout << "Введите месяц:" << endl;
	T.month = input_int(cin, 1, 12);
	cout << "Введите год:" << endl;
	T.year = input_int(cin, 1900, 2022);
	return in;
}

/*__________ввод пароля__________*/
char* input_password(istream& in, char* str)
{
	setColor(13);
	cout << "[" << password_length - 1 << "]" << endl;
	setColor(6);
	bool flag = false;
	do
	{
		flag = true;
		try
		{
			rewind(stdin);
			in.getline(str, password_length);
			//проверка переполнения строки
			if (!cin or strlen(str) < password_length - 1)
			{
				cin.clear();
				throw Input_error(4, "Ошибка ввода строки", "Пароль состоит из 8 символов");
			}
			//проверка серии
			for (size_t i = 0; i < 8; ++i)
			{
				if ((str[i] < 'a' or str[i] >'z') and (str[i] < 'A' or str[i] >'Z')
					and (str[i] < '0' or str[i] >'9'))
					throw Input_error(3, "Ошибка ввода паспорта",
						"В пароль может состоять из английских буквы и цифр");
			}
		}
		catch (Input_error obj)
		{
			obj.show_e();
			flag = false;
		}
	} while (!flag);
	return str;
}