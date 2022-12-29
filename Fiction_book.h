#pragma once
#include "standart.h"
#include "Book.h"
#include "Queue.cpp"

/***����� �������������� ����***/
class Fiction_book : public Book
{
private:

	char _genre[length_12];     //����

public:

	/***����������� �/��� ����������***/
	Fiction_book(int id = -1, const char* name = "",
		const char* second_name = "",
		const char* title = "", int copies = -1,
		int no_active = -1, const char* genre = "") :
		Book(id, name, second_name, 
			title, copies, no_active)
	{
		strcpy_s(_genre, genre);
	}

	/***����������***/
	virtual ~Fiction_book() {}

	/***����������� �����������***/
	Fiction_book(const Fiction_book& T) :
		Book(dynamic_cast<const Book&>(T))
	{
		strcpy_s(_genre, T._genre);
	}

	/***���������� ��������� ������������***/
	Fiction_book operator=(const Fiction_book& T);

	/***���������� ��������� �����***/
	bool operator==(const Fiction_book& T);

	/***���������� ��������� ������***/
	bool operator>(const Fiction_book& T);

	/***���������� ��������� ������***/
	bool operator<(const Fiction_book& T);

	/***��������� ���� �����***/
	char* get_genre();

	/***��������� ���� �����***/
	void set_genre(const char* topic);

	/***���������� ������***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Fiction_book& T);

	/***���������� �����***/
	friend std::istream& operator>>(std::istream& in, 
		Fiction_book& T);

	/*__________���������� ������ � ��������� �����__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		Fiction_book& T);

	/*__________���������� ������ �� ��������� �����__________*/
	friend std::fstream& operator>>(std::fstream& is, 
		Fiction_book& T);

	/***����� �������***/
	virtual void table();

	/***���� ����������***/
	int menu_sort();

	/***�������� ������ ������� � ��������� �����***/
	Fiction_book copy_place(int choice);

	/*__________������� ���� ��� ������__________*/
	Fiction_book menu_for_poisk();
};

//���� ��������� ����������
Queue<Fiction_book> menu_correct(Queue<Fiction_book> T, 
	int size, int pos);