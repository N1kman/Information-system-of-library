#pragma once
#include "Input_error.h"
#include "File_error.h"
#include "Container_error.h"
#include "standart.h"
#include "Algos.cpp"

/***����� ������������***/
class User
{
protected:

	int _id;                          //����  
	char _password[password_length];  //������
	char _name[length_12];            //���
	char _second_name[length_12];     //�������

public:

	/***����������� �/��� ����������***/
	User(int id = -1, const char* password = "", 
		const char* name = "",
		const char* second_name = "") :_id(id)
	{
		if (_id == -1)_id = rand() % (rand() % 10000);
		strcpy_s(this->_password, password);
		strcpy_s(this->_name, name);
		strcpy_s(this->_second_name, second_name);
	}

	/***����������***/
	virtual  ~User() = 0;

	/***����������� �����������***/
	User(const User& T)
	{
		_id = T._id;
		strcpy_s(_password, T._password);
		strcpy_s(_name, T._name);
		strcpy_s(_second_name, T._second_name);
	}

	/***���������� ��������� ���������***/
	bool operator>(const User& T);

	/***��������� ���� ������������***/
	int& get_id();

	/***��������� ���� ������������***/
	void set_id(int id);

	/***��������� ������ ������������***/
	char* get_password();

	/***��������� ������ ������������***/
	void set_password(const char* password);

	/***��������� ����� ������������***/
	char* get_name();

	/***��������� ����� ������������***/
	void set_name(const char* name);

	/***��������� ������� ������������***/
	char* get_second_name();

	/***��������� ������� ������������***/
	void set_second_name(const char* second_name);

	/***���������� ������***/
	friend std::ostream& operator<<(std::ostream& out, 
		const User& T);

	/***���������� �����***/
	friend std::istream& operator>>(std::istream& in, 
		User& T);

	/*__________���������� ������ � ��������� �����__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		User& T);

	/*__________���������� ������ �� ��������� �����__________*/
	friend std::fstream& operator>>(std::fstream& is,
		User& T);

	/***����� �������***/
	virtual void table();

	/***�������� ����***/
	bool check_id(int id);
};