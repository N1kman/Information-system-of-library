#include "standart.h"
#include "Interface.h"

//*�������� ������*//
int main()
{
	//*����������� �������� �����*//
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//*��� ����������� ������������*//
	srand((unsigned int)time(0));

	//*��������� ����� � ������� ������*//
	setColor(6);
	system("CLS");

	//*��������� ���������*//
	Interface a;
	//*����� �������� ����*//
	a.main_menu();

	setColor(4);
	cout << "---����������---" << endl;
	setColor(6);

	return 0;
}