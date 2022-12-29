#pragma once
#include "standart.h"
#include "Literature.h"

/***����� �����***/
class Book : public Literature
{
protected:

	int _copies;       //���������� �����������
	int _no_active;    //���������� ��������� �����������

public:

	/***����������� �/��� ����������***/
	Book(int id = -1, const char* name = "",
		const char* second_name = "",
		const char* title = "", int copies = -1,
		int no_active = -1) :
		Literature(id, name, second_name, title)
	{
		_copies = copies;
		_no_active = no_active;
	}

	/***����������***/
	virtual ~Book() = 0;

	/***����������� �����������***/
	Book(const Book& T):
		Literature(dynamic_cast<const Literature&>(T))
	{
		_copies = T._copies;
		_no_active = T._no_active;
	}

	/***��������� ���������� �����***/
	int& get_copies();

	/***��������� ���������� ������***/
	void set_copies(int copies);

	/***��������� ���������� ����� �������� ����***/
	int& get_no_active();

	/***��������� ���������� ��������� ����***/
	void set_no_active(int no_active);

	/***���������� �����***/
	friend std::istream& operator>>(std::istream& in, Book& T);

	/***���������� ������***/
	friend std::ostream& operator<<(std::ostream& out, const Book& T);

	/***����� �������***/
	virtual void table();

};

