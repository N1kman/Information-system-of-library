#include "standart.h"
#include "Interface.h"

//*головной модуль*//
int main()
{
	//*подключение русского языка*//
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//*для организации рандомайзера*//
	srand((unsigned int)time(0));

	//*установка цвета и очистка экрана*//
	setColor(6);
	system("CLS");

	//*интерфейс программы*//
	Interface a;
	//*вызов главного меню*//
	a.main_menu();

	setColor(4);
	cout << "---ЗАВЕРШЕНИЕ---" << endl;
	setColor(6);

	return 0;
}