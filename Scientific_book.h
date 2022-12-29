#pragma once
#include "standart.h"
#include "Book.h"

/***����� ������� ����***/
class Scientific_book : public Book
{
protected:

	char _topic[length_12];     //����

public:

	/***����������� �/��� ����������***/
	Scientific_book(int id = -1, const char* name = "",
		const char* second_name = "",
		const char* title = "", int copies = -1,
		int no_active = -1, const char* topic = "") :
		Book(id, name, second_name, title, copies, no_active)
	{
		strcpy_s(_topic, topic);
	}

	/***����������***/
	virtual ~Scientific_book() = 0;

	/***����������� �����������***/
	Scientific_book(const Scientific_book& T) :
		Book(dynamic_cast<const Book&>(T))
	{
		strcpy_s(_topic, T._topic);
	}

	/***��������� ���� �����***/
	char* get_topic();

	/***��������� ���� �����***/
	void set_topic(const char* topic);

	/***���������� ������***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Scientific_book& T);

	/***���������� �����***/
	friend std::istream& operator>>(std::istream& in, 
		Scientific_book& T);

	/***����� �������***/
	virtual void table();
};

