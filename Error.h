#pragma once
#include "Standart.h"

/*__________����� ������__________*/
class Error
{
protected:

	int _code;             //��� ������
	char _msg[_length_80]; //���������

public:
	/*__________�����������__________*/
	Error(int code, const char* str) :_code(code)
	{
		strcpy_s(_msg, str);
	}

    /*__________����������__________*/
	~Error(){}

    /*__________�����__________*/
	virtual void show_e();

};

