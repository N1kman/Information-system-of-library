#pragma once
#include "Input_error.h"
#include "File_error.h"
#include "Container_error.h"
#include "standart.h"
#include "Audio.h"
#include "Fiction_book.h"
#include "Technical_book.h"
#include "Cognitive_book.h"
#include "Queue.cpp"

/***����� ������ ����������***/
class Active_Lit
{
private:

	int _id_user;    //���� ������������
	int _id_lit;     //���� �����
	int _status;     //������: 0 - ������, 1 - ������ �� �������,
	                 //2 - ��������, 3 - ������,4 - ����������
	date _issuance;  //���� ������
	date _ret;       //���� ��������

public:

	/***����������� �/��� ����������***/
	Active_Lit(int id_user = -1, int id_lit = -1, int status = -1,
		date* issuance = nullptr, date* ret = nullptr)
		:_id_user(id_user), _id_lit(id_lit), _status(status)
	{
		if (issuance)_issuance = *issuance;
		if (ret) _ret = *ret;
	}

	/***����������� �����������***/
	Active_Lit(const Active_Lit& T)
	{
		_id_user = T._id_user;
		_id_lit = T._id_lit;
		_status = T._status;
		_issuance = T._issuance;
		_ret = T._ret;
	}

	/***���������� ��������� ������������***/
	Active_Lit operator=(const Active_Lit& T);

	/***���������� ��������� �����***/
	bool operator==(const Active_Lit& T);

	/***����������***/
	~Active_Lit() {}

	/***���������� ������***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Active_Lit& T);

	/*__________���������� ������ �� ��������� �����__________*/
	friend std::fstream& operator>>(std::fstream& is, 
		Active_Lit& T);

	/*__________���������� ������ � ��������� �����__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		Active_Lit& T);

	/***��������� ���� ��������***/
	date& get_date_ret();

	/***��������� ���� ��������***/
	void set_date_ret(date ret);

	/***��������� ���� ���������***/
	date& get_date_issuance();

	/***��������� ���� ���������***/
	void set_date_issuance(date issuance);

	/***��������� �������***/
	int& get_status();

	/***��������� �������***/
	void set_status(int status);

	/***��������� ���� �����***/
	int& get_id_lit();

	/***��������� ���� �����***/
	void set_id_lit(int id_lit);

	/***��������� ���� ������������***/
	int& get_id_user();

	/***��������� ���� ������������***/
	void set_id_user(int id_user);

	/***�������� ����***/
	bool check_id(int id);

	/***����� �������***/
	void table();
};

/*__________��������� �������� �� ����__________*/
char* get_title_by_id(int ID);

/*__________��������� ������� �� ����__________*/
char* get_second_name_by_id(int ID);

/*__________��������� ���������� ��������� ����� �� ����__________*/
int get_no_active_lit(int ID);

/*__________������� ���������� ���������� �������� �����__________*/
void add_no_active_lit(int ID, int buff);