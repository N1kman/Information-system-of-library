#include "Error.h"

/*__________�����__________*/
void Error::show_e()
{
	Beep(400, 700);
	setColor(12);
	cout << "��� ������: " << _code << ". ";
	cout << "��������: " << _msg << ". " << endl;
	setColor(6);
}