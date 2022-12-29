#pragma once
#include "standart.h"
#include "User.h"

/***КЛАСС АДМИНИСТРАТОРА***/
class Admin : public User
{
private:

	date _time_of_work; //дата последнего захода в систему

public:

    /***КОНСТРУКТОР С/БЕЗ ПАРАМЕТРОВ***/
	Admin(int id = -1, const char* password = "", 
		const char* name = "",
		const char* second_name = "", 
		date* time_of_work = nullptr) :
		User(id, password, name, second_name)
	{
		if (time_of_work)
			_time_of_work = *time_of_work;
	}

	/***ДЕСТРУКТОР***/
	virtual ~Admin() {};

	/***КОНСТРУКТОР КОПИРОВАНИЯ***/
	Admin(const Admin& T) :
		User(dynamic_cast<const User&>(T))
	{
		this->_time_of_work = T._time_of_work;
	}

	/***ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ***/
	Admin operator=(const Admin& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
	bool operator==(const Admin& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА БОЛЬШЕ***/
	bool operator>(const Admin& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА МЕНЬШЕ***/
	bool operator<(const Admin& T);

	/***УСТАНОВКА ДАТЫ ВХОДА***/
	void set_time_of_work(date time_of_work);

	/***ПОЛУЧЕНИЕ ДАТЫ ВХОДА***/
	date& get_time_of_work();

	/***ПЕРЕГРУЗКА ВЫВОДА***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Admin& T);

	/*__________перегрузка вывода в бинарного файла__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		Admin& T);

	/*__________перегрузка чтения из бинарного файла__________*/
	friend std::fstream& operator>>(std::fstream& is, 
		Admin& T);

	/***ВЫВОД ТАБЛИЦЫ***/
	virtual void table();

	/***МЕНЮ СОРТИРОВКИ***/
	int menu_sort();

	/***Создание нового объекта с выбранным полем***/
	Admin copy_place(int choice);

	/*__________функция меню для поиска__________*/
	Admin menu_for_poisk();

};

//меню изменения параметров
Queue<Admin> menu_correct(Queue<Admin> T, int size, int pos);