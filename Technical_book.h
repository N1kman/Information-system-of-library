#pragma once
#include "standart.h"
#include "Scientific_book.h"
#include "Queue.cpp"

/***����� ����������� ����***/
class Technical_book : public Scientific_book
{
private:

	char _application_area[length_12];           //������� ����������

public:

	/***����������� �/��� ����������***/
	Technical_book(int id = -1, const char* name = "",
		const char* second_name = "",
		const char* title = "", int copies = -1,
		int no_active = -1, const char* topic = "",
		const char* application_area = "") :
		Scientific_book(id, name, second_name, title, 
			copies, no_active, topic)
	{
		strcpy_s(_application_area, application_area);
	}

	/***����������***/
	virtual ~Technical_book() {}

	/***����������� �����������***/
	Technical_book(const Technical_book& T) :
		Scientific_book(dynamic_cast<const Scientific_book&>(T))
	{
		strcpy_s(_application_area, T._application_area);
	}

	/***���������� ��������� ������������***/
	Technical_book operator=(const Technical_book& T);

	/***���������� ��������� �����***/
	bool operator==(const Technical_book& T);

	/***���������� ��������� ������***/
	bool operator>(const Technical_book& T);

	/***���������� ��������� ������***/
	bool operator<(const Technical_book& T);

	/***��������� ������� ����������***/
	char* get_application_area();

	/***��������� ������� ����������***/
	void set_application_area(const char* application_area);

	/***���������� ������***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Technical_book& T);

	/***���������� �����***/
	friend std::istream& operator>>(std::istream& in, 
		Technical_book& T);

	/*__________���������� ������ � ��������� �����__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		Technical_book& T);

	/*__________���������� ������ �� ��������� �����__________*/
	friend std::fstream& operator>>(std::fstream& is, 
		Technical_book& T);

	/***����� �������***/
	virtual void table();

	/***���� ����������***/
	int menu_sort();

	/***�������� ������ ������� � ��������� �����***/
	Technical_book copy_place(int choice);

	/*__________������� ���� ��� ������__________*/
	Technical_book menu_for_poisk();
};

//���� ��������� ����������
Queue<Technical_book> menu_correct(Queue<Technical_book> T, 
	int size, int pos);