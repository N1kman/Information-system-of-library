#pragma once
#include "standart.h"
#include "User.h"

/***����� ��������������***/
class Admin : public User
{
private:

	date _time_of_work; //���� ���������� ������ � �������

public:

    /***����������� �/��� ����������***/
	Admin(int id = -1, const char* password = "", 
		const char* name = "",
		const char* second_name = "", 
		date* time_of_work = nullptr) :
		User(id, password, name, second_name)
	{
		if (time_of_work)
			_time_of_work = *time_of_work;
	}

	/***����������***/
	virtual ~Admin() {};

	/***����������� �����������***/
	Admin(const Admin& T) :
		User(dynamic_cast<const User&>(T))
	{
		this->_time_of_work = T._time_of_work;
	}

	/***���������� ��������� ������������***/
	Admin operator=(const Admin& T);

	/***���������� ��������� �����***/
	bool operator==(const Admin& T);

	/***���������� ��������� ������***/
	bool operator>(const Admin& T);

	/***���������� ��������� ������***/
	bool operator<(const Admin& T);

	/***��������� ���� �����***/
	void set_time_of_work(date time_of_work);

	/***��������� ���� �����***/
	date& get_time_of_work();

	/***���������� ������***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Admin& T);

	/*__________���������� ������ � ��������� �����__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		Admin& T);

	/*__________���������� ������ �� ��������� �����__________*/
	friend std::fstream& operator>>(std::fstream& is, 
		Admin& T);

	/***����� �������***/
	virtual void table();

	/***���� ����������***/
	int menu_sort();

	/***�������� ������ ������� � ��������� �����***/
	Admin copy_place(int choice);

	/*__________������� ���� ��� ������__________*/
	Admin menu_for_poisk();

};

//���� ��������� ����������
Queue<Admin> menu_correct(Queue<Admin> T, int size, int pos);