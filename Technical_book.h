#pragma once
#include "standart.h"
#include "Scientific_book.h"
#include "Queue.cpp"

/***КЛАСС ТЕХНИЧЕСКИХ КНИГ***/
class Technical_book : public Scientific_book
{
private:

	char _application_area[length_12];           //область применения

public:

	/***КОНСТРУКТОР С/БЕЗ ПАРАМЕТРОВ***/
	Technical_book(int id = -1, const char* name = "",
		const char* second_name = "",
		const char* title = "", int copies = -1,
		int no_active = -1, const char* topic = "",
		const char* application_area = "") :
		Scientific_book(id, name, second_name, title, 
			copies, no_active, topic)
	{
		strcpy_s(_application_area, application_area);
	}

	/***ДЕСТРУКТОР***/
	virtual ~Technical_book() {}

	/***КОНСТРУКТОР КОПИРОВАНИЯ***/
	Technical_book(const Technical_book& T) :
		Scientific_book(dynamic_cast<const Scientific_book&>(T))
	{
		strcpy_s(_application_area, T._application_area);
	}

	/***ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ***/
	Technical_book operator=(const Technical_book& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
	bool operator==(const Technical_book& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА БОЛЬШЕ***/
	bool operator>(const Technical_book& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА МЕНЬШЕ***/
	bool operator<(const Technical_book& T);

	/***ПОЛУЧЕНИЕ ОБЛАСТИ ПРИМЕНЕНИЯ***/
	char* get_application_area();

	/***УСТАНОВКА ОБЛАСТИ ПРИМЕНЕНИЯ***/
	void set_application_area(const char* application_area);

	/***ПЕРЕГРУЗКА ВЫВОДА***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Technical_book& T);

	/***ПЕРЕГРУЗКА ВВОДА***/
	friend std::istream& operator>>(std::istream& in, 
		Technical_book& T);

	/*__________перегрузка вывода в бинарного файла__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		Technical_book& T);

	/*__________перегрузка чтения из бинарного файла__________*/
	friend std::fstream& operator>>(std::fstream& is, 
		Technical_book& T);

	/***ВЫВОД ТАБЛИЦЫ***/
	virtual void table();

	/***МЕНЮ СОРТИРОВКИ***/
	int menu_sort();

	/***Создание нового объекта с выбранным полем***/
	Technical_book copy_place(int choice);

	/*__________функция меню для поиска__________*/
	Technical_book menu_for_poisk();
};

//меню изменения параметров
Queue<Technical_book> menu_correct(Queue<Technical_book> T, 
	int size, int pos);