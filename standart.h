#pragma once

#include <iostream>
#include <windows.h>
#include <iso646.h>
#include <iomanip>
#include <fstream>
#include <list>
#include <algorithm>

#define password_length 9   //����� ������
#define _length_80 81
#define length_12 13           
#define standart_MAX 5      //���������� ���������� ��������

#define pass "admin123"     //������ �������� ������
#define nam "������"        //��� �������� ������
#define fam "����"          //��� �������� ������

#define file1 "Admin.bin"   //��� ����� � ����������� �� �������
#define file2 "Member.bin"  //��� ����� � ����������� � �������������
#define file3 "Audio.bin"   //��� ����� � ����������� �� �����������
#define file4 "Fiction_book.bin"     //��� ����� � ����������� � �������������� ������
#define file5 "Technical_book.bin"   //��� ����� � ����������� � ����������� ������
#define file6 "Cognitive_book.bin"   //��� ����� � ����������� � �������������� ������
#define file7 "Active_Lit.bin"       //��� ����� � ����������� � ������ ����������

using namespace std;

//��������� ����
struct date
{
	int day = 0;               //����
	int month = 0;             //�����
	int year = 0;              //���


	/*__________���������� ��������� �����__________*/
	bool operator==(const date& T)
	{
		if (T.day != day)
			return false;
		if (T.month != month)
			return false;
		if (T.year != year)
			return false;
	
		return true;
	}

	/*__________���������� ��������� ������__________*/
	bool operator>(const date& T)
	{
		if (T.year > year)
			return false;
		if (T.month > month)
			return false;
		if (T.day >= day)
			return false;

		return true;
	}

	/*__________���������� ��������� ������__________*/
	bool operator<(const date& T)
	{
		if (T.year < year)
			return false;
		if (T.month < month)
			return false;
		if (T.day <= day)
			return false;

		return true;
	}

	/*__________���������� ������__________*/
	friend std::ostream& operator<<(std::ostream& out, const date& T)
	{
		out << setfill('0')
			<< setw(2) << T.day << "."
			<< setw(2) << T.month << "."
			<< setw(4) << T.year;
		return out;
	}

	/*__________���������� �����__________*/
	friend std::istream& operator>>(std::istream& in, date& T);
};

/*__________������� ��������� ���������__________*/
void end_program();

/*__________���� ������� ������__________*/
char* input_rus(istream& in, char*);

/*__________���� ���������� ������__________*/
char* input_eng(istream& in, char*);

/*__________���� ������ �����__________*/
int input_int(istream& in, int _a, int _b);

/*__________����� ������� ����� ������__________*/
void setColor(int color);

/*__________���� ������__________*/
char* input_password(istream& in, char*);