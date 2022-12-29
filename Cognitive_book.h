#pragma once
#include "standart.h"
#include "Scientific_book.h"
#include "Queue.cpp"

/***����� ������-�������������� ����***/
class Cognitive_book : public Scientific_book
{
private:

	int _sum_of_search; //����������� �������� �� ������������  

public:

	/***����������� �/��� ����������***/
	Cognitive_book(int id = -1, const char* name = "",
		const char* second_name = "",
		const char* title = "", int copies = -1,
		int no_active = -1, const char* topic = "",
		int sum_of_search = -1) :
		Scientific_book(id, name, second_name, title, 
			copies, no_active, topic)
	{
		_sum_of_search = sum_of_search;
	}

	/***����������***/
	virtual ~Cognitive_book() {}

	/***����������� �����������***/
	Cognitive_book(const Cognitive_book& T) :
		Scientific_book(dynamic_cast<const Scientific_book&>(T))
	{
		_sum_of_search = T._sum_of_search;
	}

	/***���������� ��������� ������������***/
	Cognitive_book operator=(const Cognitive_book& T);

	/***���������� ��������� �����***/
	bool operator==(const Cognitive_book& T);

	/***���������� ��������� ������***/
	bool operator>(const Cognitive_book& T);

	/***���������� ��������� ������***/
	bool operator<(const Cognitive_book& T);

	/***��������� ����� ������������***/
	int& get_sum_of_search();

	/***��������� ����� ������������***/
	void set_sum_of_search(int sum_of_search);

	/***���������� ������***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Cognitive_book& T);

	/***���������� �����***/
	friend std::istream& operator>>(std::istream& in, 
		Cognitive_book& T);

	/*__________���������� ������ � ��������� �����__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		Cognitive_book& T);

	/*__________���������� ������ �� ��������� �����__________*/
	friend std::fstream& operator>>(std::fstream& is, 
		Cognitive_book& T);

	/***����� �������***/
	virtual void table();

	/***���� ����������***/
	int menu_sort();

	/***�������� ������ ������� � ��������� �����***/
	Cognitive_book copy_place(int choice);

	/*__________������� ���� ��� ������__________*/
	Cognitive_book menu_for_poisk();
};

//���� ��������� ����������
Queue<Cognitive_book> menu_correct(Queue<Cognitive_book> T,
	int size, int pos);