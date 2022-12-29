#pragma once
#include "standart.h"
#include "Literature.h"
#include "Queue.cpp"

/***����� ����������***/
class Audio : public Literature
{
private:

	int _time;       //��������������� ����� ����� � ������� 

public:

	/***����������� �/��� ����������***/
	Audio(int id = -1, const char* name = "",
		const char* second_name = "",
		const char* title = "", int time = -1) :
		Literature(id, name, second_name, title)
	{
		this->_time = time;
	}

	/***����������***/
	virtual ~Audio() {};

	/***����������� �����������***/
	Audio(const Audio& T) :
		Literature(dynamic_cast<const Literature&>(T))
	{
		this->_time = T._time;
	}

	/***���������� ��������� ������������***/
	Audio operator=(const Audio& T);

	/***���������� ��������� �����***/
	bool operator==(const Audio& T);

	/***���������� ��������� ������***/
	bool operator>(const Audio& T);

	/***���������� ��������� ������***/
	bool operator<(const Audio& T);

	/***��������� ������������ �����***/
	int& get_time();

	/***��������� ������������ �����***/
	void set_time(int time);

	/***���������� ������***/
	friend std::ostream& operator<<(std::ostream& out, 
		const  Audio& T);

	/***���������� �����***/
	friend std::istream& operator>>(std::istream& in, Audio& T);

	/*__________���������� ������ � ��������� �����__________*/
	friend std::fstream& operator<<(std::fstream& out, Audio& T);

	/*__________���������� ������ �� ��������� �����__________*/
	friend std::fstream& operator>>(std::fstream& is, Audio& T);

	/***����� �������***/
	virtual void table();

	/***���� ����������***/
	int menu_sort();

	/***�������� ������ ������� � ��������� �����***/
	Audio copy_place(int choice);

	/*__________������� ���� ��� ������__________*/
	Audio menu_for_poisk();
};

//���� ��������� ����������
Queue<Audio> menu_correct(Queue<Audio> T, int size, int pos);