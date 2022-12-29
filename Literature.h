#pragma once
#include "Input_error.h"
#include "File_error.h"
#include "Container_error.h"
#include "standart.h"
#include "Algos.cpp"

/***����� ����������***/
class Literature
{
protected:

	int _id;                        //����  
	char _name[length_12];          //��� ������
	char _second_name[length_12];   //������� ������
	char _title[length_12];         //��������

public:

	/***����������� �/��� ����������***/
	Literature(int id = -1, const char* name = "", 
		const char* second_name = "",
		const char* title = "") :_id(id)
	{
		if (_id == -1)
			_id = rand() % (rand() % 10000);
		strcpy_s(this->_name, name);
		strcpy_s(this->_second_name, second_name);
		strcpy_s(this->_title, title);
	}

	/***����������***/
	virtual ~Literature() = 0;

	/***����������� �����������***/
	Literature(const Literature& T)
	{
		this->_id = T._id;
		strcpy_s(this->_name, T._name);
		strcpy_s(this->_second_name, T._second_name);
		strcpy_s(this->_title, T._title);
	}

	/***���������� ��������� ���������***/
	bool operator>(const Literature& T);

	/***�������� ����***/
	bool check_id(int id);

	/***��������� ���� �����***/
	int& get_id();

	/***��������� ���� �����***/
	void set_id(int id);

	/***��������� ����� ������ �����***/
	char* get_name();

	/***��������� ����� ������ �����***/
	void set_name(const char* name);

	/***��������� ������� ������ �����***/
	char* get_second_name();

	/***��������� ������� ������ �����***/
	void set_second_name(const char* second_name);

	/***��������� �������� �����***/
	char* get_title();

	/***��������� �������� �����***/
	void set_title(const char* title);

	/***���������� ������***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Literature& T);

	/***���������� �����***/
	friend std::istream& operator>>(std::istream& in, 
		Literature& T);

	/***����� �������***/
	virtual void table();
};