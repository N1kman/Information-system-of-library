#pragma once

#include <iostream>
#include <windows.h>
#include <iso646.h>
#include <iomanip>
#include <fstream>
#include <list>
#include <algorithm>

#define password_length 9   //длина пароля
#define _length_80 81
#define length_12 13           
#define standart_MAX 5      //количество отмененных действий

#define pass "admin123"     //пароль главного админа
#define nam "Никита"        //имя главного админа
#define fam "Гиль"          //имя главного админа

#define file1 "Admin.bin"   //имя файла с информацией об админах
#define file2 "Member.bin"  //имя файла с информацией о пользователях
#define file3 "Audio.bin"   //имя файла с информацией об аудиокнигах
#define file4 "Fiction_book.bin"     //имя файла с информацией о художественных книгах
#define file5 "Technical_book.bin"   //имя файла с информацией о технических книгах
#define file6 "Cognitive_book.bin"   //имя файла с информацией о позновательных книгах
#define file7 "Active_Lit.bin"       //имя файла с информацией о взятой литературе

using namespace std;

//структура даты
struct date
{
	int day = 0;               //день
	int month = 0;             //месяц
	int year = 0;              //год


	/*__________перегрузка оператора равно__________*/
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

	/*__________перегрузка оператора больше__________*/
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

	/*__________перегрузка оператора меньше__________*/
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

	/*__________перегрузка вывода__________*/
	friend std::ostream& operator<<(std::ostream& out, const date& T)
	{
		out << setfill('0')
			<< setw(2) << T.day << "."
			<< setw(2) << T.month << "."
			<< setw(4) << T.year;
		return out;
	}

	/*__________перегрузка ввода__________*/
	friend std::istream& operator>>(std::istream& in, date& T);
};

/*__________функция окончания программы__________*/
void end_program();

/*__________ввод русской строки__________*/
char* input_rus(istream& in, char*);

/*__________ввод английской строки__________*/
char* input_eng(istream& in, char*);

/*__________ввод целого числа__________*/
int input_int(istream& in, int _a, int _b);

/*__________метод задания цвета тексту__________*/
void setColor(int color);

/*__________ввод пароля__________*/
char* input_password(istream& in, char*);