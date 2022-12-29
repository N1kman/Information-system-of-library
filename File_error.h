#pragma once
#include "Error.h"

/*__________����� ������ ������__________*/
class File_error :public Error
{
private:

	char _prim[_length_80];   //����������

public:
	/*__________�����������__________*/
	File_error(int code, const char* str1, const char* str2) :Error(code, str1)
	{
		strcpy_s(_prim, str2);
	}

	/*__________����������__________*/
	~File_error() {}

	/*__________�����__________*/
	virtual void show_e();
};

