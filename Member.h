#pragma once
#include "standart.h"
#include "User.h"

/***����� ��������***/
class Member : public User
{
private:

	int _status;    //������ ������������

public:

	/***����������� �/��� ����������***/
	Member(int id = -1, const char* password = "", 
		const char* name = "",
		const char* second_name = "", int status = -1) :
		User(id, password, name, second_name)
	{
		this->_status = status;
	}

	/***����������***/
	virtual ~Member() {};

	/***����������� �����������***/
	Member(const Member& T):User(dynamic_cast<const User&>(T))
	{
		this->_status = T._status;
	}

	/***��������� �������***/
	Member operator=(const Member& T);

	/***���������� ��������� �����***/
	bool operator==(const Member& T);

	/***���������� ��������� ������***/
	bool operator>(const Member& T);

	/***���������� ��������� ������***/
	bool operator<(const Member& T);

	//��������� �������
	int& get_status();

	/***��������� �������***/
	void set_status(int status);

	/***���������� ������***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Member& T);

	/***���������� �����***/
	friend std::istream& operator>>(std::istream& in, 
		Member& T);

	/*__________���������� ������ � ��������� �����__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		Member& T);

	/*__________���������� ������ �� ��������� �����__________*/
	friend std::fstream& operator>>(std::fstream& is, 
		Member& T);

	/***����� �������***/
	virtual void table();

	/***���� ����������***/
	int menu_sort();

	/***�������� ������ ������� � ��������� �����***/
	Member copy_place(int choice);

	/*__________������� ���� ��� ������__________*/
	Member menu_for_poisk();
};

//���� ��������� ����������
Queue<Member> menu_correct(Queue<Member> T, 
	int size, int pos);