#include "Container_error.h"

/*__________�����__________*/
void Container_error::show_e()
{
	Beep(400, 700);
	Error::show_e();
	setColor(12);
	cout << "����������: " << _prim << "." << endl;
	setColor(6);
}