#include "standart.h"
#include "Literature.h"

/*__________���� ������� ������__________*/
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
			//�������� ������������ ������
			if (!cin)
			{
				cin.clear();
				throw Input_error(4, "������ ����� ������"
					, "����������� �� 12 ��������");
			}
			//�������� �� ���� ������
			if (!strlen(str))
				throw Input_error(1, "������ ����� ������"
					, "������ �� �������");
			//�������� �� ������� �������
			for (size_t i = 0; i < strlen(str); ++i)
			{
				if ((str[i] < '�' or str[i] >'�') and str[i] != ' ')
					throw Input_error(1, "������ ����� ������"
						, "������� ��������� �����");
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

/*__________���� ���������� ������__________*/
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
			//�������� ������������ ������
			if (!cin)
			{
				cin.clear();
				throw Input_error(4, "������ ����� ������",
					"����������� �� 12 ��������");
			}
			//�������� �� ���� ������
			if (!strlen(str))
				throw Input_error(1, "������ ����� ������",
					"������ �� �������");
			//�������� �� ���������� �������
			for (size_t i = 0; i < strlen(str); ++i)
			{
				if ((str[i] < 'a' or str[i] >'z') and (str[i] < 'A' or str[i] >'Z')
					and str[i] != ' ' and (str[i] < '0' or str[i] >'9'))
					throw Input_error(1, "������ ����� ������",
						"������� ������������ �����");
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

/*__________���� ������ �����__________*/
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
			//�������� ������� �� �����
			if (cin.peek() != '\n')
			{
				throw Input_error(2, "������ �����", 
					"������� �� �����");
			}
			//�������� ������� �� �����
			if (!in)
			{
				throw Input_error(2, "������ �����", 
					"������� �� �����");
			}
			//�������� ������ �� �������
			if (_int<_a or _int>_b)
			{
				throw Input_error(2, "������ �����",
					"����� �� �������");
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

/*__________������� ������� ����� ������__________*/
void setColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//������� ����� ������
	SetConsoleTextAttribute(hConsole, color | 7 << 4);
}

/*__________���������� �����__________*/
std::istream& operator>>(std::istream& in, date& T)
{
	cout << "������� ����:" << endl;
	T.day = input_int(cin, 1, 31);
	cout << "������� �����:" << endl;
	T.month = input_int(cin, 1, 12);
	cout << "������� ���:" << endl;
	T.year = input_int(cin, 1900, 2022);
	return in;
}

/*__________���� ������__________*/
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
			//�������� ������������ ������
			if (!cin or strlen(str) < password_length - 1)
			{
				cin.clear();
				throw Input_error(4, "������ ����� ������", "������ ������� �� 8 ��������");
			}
			//�������� �����
			for (size_t i = 0; i < 8; ++i)
			{
				if ((str[i] < 'a' or str[i] >'z') and (str[i] < 'A' or str[i] >'Z')
					and (str[i] < '0' or str[i] >'9'))
					throw Input_error(3, "������ ����� ��������",
						"� ������ ����� �������� �� ���������� ����� � ����");
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