#pragma once
#include "standart.h"
#include "User.h"

/***КЛАСС ЧИТАТЕЛЯ***/
class Member : public User
{
private:

	int _status;    //статус пользователя

public:

	/***КОНСТРУКТОР С/БЕЗ ПАРАМЕТРОВ***/
	Member(int id = -1, const char* password = "", 
		const char* name = "",
		const char* second_name = "", int status = -1) :
		User(id, password, name, second_name)
	{
		this->_status = status;
	}

	/***ДЕСТРУКТОР***/
	virtual ~Member() {};

	/***КОНСТРУКТОР КОПИРОВАНИЯ***/
	Member(const Member& T):User(dynamic_cast<const User&>(T))
	{
		this->_status = T._status;
	}

	/***ПОЛУЧЕНИЕ СТАТУСА***/
	Member operator=(const Member& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
	bool operator==(const Member& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА БОЛЬШЕ***/
	bool operator>(const Member& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА МЕНЬШЕ***/
	bool operator<(const Member& T);

	//получение статуса
	int& get_status();

	/***УСТАНОВКА СТАТУСА***/
	void set_status(int status);

	/***ПЕРЕГРУЗКА ВЫВОДА***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Member& T);

	/***ПЕРЕГРУЗКА ВВОДА***/
	friend std::istream& operator>>(std::istream& in, 
		Member& T);

	/*__________перегрузка вывода в бинарного файла__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		Member& T);

	/*__________перегрузка чтения из бинарного файла__________*/
	friend std::fstream& operator>>(std::fstream& is, 
		Member& T);

	/***ВЫВОД ТАБЛИЦЫ***/
	virtual void table();

	/***МЕНЮ СОРТИРОВКИ***/
	int menu_sort();

	/***Создание нового объекта с выбранным полем***/
	Member copy_place(int choice);

	/*__________функция меню для поиска__________*/
	Member menu_for_poisk();
};

//меню изменения параметров
Queue<Member> menu_correct(Queue<Member> T, 
	int size, int pos);