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

/***КЛАСС ВЗЯТОЙ ЛИТЕРАТУРЫ***/
class Active_Lit
{
private:

	int _id_user;    //айди пользователя
	int _id_lit;     //айди книги
	int _status;     //статус: 0 - запрос, 1 - запрос на возврат,
	                 //2 - отменено, 3 - выдана,4 - возвращена
	date _issuance;  //дата выдачи
	date _ret;       //дата возврата

public:

	/***КОНСТРУКТОР С/БЕЗ ПАРАМЕТРОВ***/
	Active_Lit(int id_user = -1, int id_lit = -1, int status = -1,
		date* issuance = nullptr, date* ret = nullptr)
		:_id_user(id_user), _id_lit(id_lit), _status(status)
	{
		if (issuance)_issuance = *issuance;
		if (ret) _ret = *ret;
	}

	/***КОНСТРУКТОР КОПИРОВАНИЯ***/
	Active_Lit(const Active_Lit& T)
	{
		_id_user = T._id_user;
		_id_lit = T._id_lit;
		_status = T._status;
		_issuance = T._issuance;
		_ret = T._ret;
	}

	/***ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ***/
	Active_Lit operator=(const Active_Lit& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
	bool operator==(const Active_Lit& T);

	/***ДЕСТРУКТОР***/
	~Active_Lit() {}

	/***ПЕРЕГРУЗКА ВЫВОДА***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Active_Lit& T);

	/*__________перегрузка чтения из бинарного файла__________*/
	friend std::fstream& operator>>(std::fstream& is, 
		Active_Lit& T);

	/*__________перегрузка вывода в бинарного файла__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		Active_Lit& T);

	/***ПОЛУЧЕНИЕ ДАТЫ ВОЗВРАТА***/
	date& get_date_ret();

	/***УСТАНОВКА ДАТЫ ВОЗВРАТА***/
	void set_date_ret(date ret);

	/***ПОЛУЧЕНИЕ ДАТЫ ПОЛУЧЕНИЯ***/
	date& get_date_issuance();

	/***УСТАНОВКА ДАТЫ ПОЛУЧЕНИЯ***/
	void set_date_issuance(date issuance);

	/***ПОЛУЧЕНИЕ СТАТУСА***/
	int& get_status();

	/***УСТАНОВКА СТАТУСА***/
	void set_status(int status);

	/***ПОЛУЧЕНИЕ АЙДИ КНИГИ***/
	int& get_id_lit();

	/***УСТАНОВКА АЙДИ КНИГИ***/
	void set_id_lit(int id_lit);

	/***ПОЛУЧЕНИЕ АЙДИ ПОЛЬЗОВАТЕЛЯ***/
	int& get_id_user();

	/***УСТАНОВКА АЙДИ ПОЛЬЗОВАТЕЛЯ***/
	void set_id_user(int id_user);

	/***ПРОВЕРКА АЙДИ***/
	bool check_id(int id);

	/***ВЫВОД ТАБЛИЦЫ***/
	void table();
};

/*__________получение названия по айди__________*/
char* get_title_by_id(int ID);

/*__________получение фамилии по айди__________*/
char* get_second_name_by_id(int ID);

/*__________получение количество свободных копий по айди__________*/
int get_no_active_lit(int ID);

/*__________функция добавления количества активных копий__________*/
void add_no_active_lit(int ID, int buff);