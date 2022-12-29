#pragma once
#include "standart.h"
#include "Scientific_book.h"
#include "Queue.cpp"

/***КЛАСС НАУЧНО-ПОЗНОВАТЕЛЬНЫХ КНИГ***/
class Cognitive_book : public Scientific_book
{
private:

	int _sum_of_search; //потраченные средства на исследование  

public:

	/***КОНСТРУКТОР С/БЕЗ ПАРАМЕТРОВ***/
	Cognitive_book(int id = -1, const char* name = "",
		const char* second_name = "",
		const char* title = "", int copies = -1,
		int no_active = -1, const char* topic = "",
		int sum_of_search = -1) :
		Scientific_book(id, name, second_name, title, 
			copies, no_active, topic)
	{
		_sum_of_search = sum_of_search;
	}

	/***ДЕСТРУКТОР***/
	virtual ~Cognitive_book() {}

	/***КОНСТРУКТОР КОПИРОВАНИЯ***/
	Cognitive_book(const Cognitive_book& T) :
		Scientific_book(dynamic_cast<const Scientific_book&>(T))
	{
		_sum_of_search = T._sum_of_search;
	}

	/***ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ***/
	Cognitive_book operator=(const Cognitive_book& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
	bool operator==(const Cognitive_book& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА БОЛЬШЕ***/
	bool operator>(const Cognitive_book& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА МЕНЬШЕ***/
	bool operator<(const Cognitive_book& T);

	/***ПОЛУЧЕНИЕ СУММЫ ИССЛЕДОВАНИЯ***/
	int& get_sum_of_search();

	/***УСТАНОВКА СУММЫ ИССЛЕДОВАНИЯ***/
	void set_sum_of_search(int sum_of_search);

	/***ПЕРЕГРУЗКА ВЫВОДА***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Cognitive_book& T);

	/***ПЕРЕГРУЗКА ВВОДА***/
	friend std::istream& operator>>(std::istream& in, 
		Cognitive_book& T);

	/*__________перегрузка вывода в бинарного файла__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		Cognitive_book& T);

	/*__________перегрузка чтения из бинарного файла__________*/
	friend std::fstream& operator>>(std::fstream& is, 
		Cognitive_book& T);

	/***ВЫВОД ТАБЛИЦЫ***/
	virtual void table();

	/***МЕНЮ СОРТИРОВКИ***/
	int menu_sort();

	/***Создание нового объекта с выбранным полем***/
	Cognitive_book copy_place(int choice);

	/*__________функция меню для поиска__________*/
	Cognitive_book menu_for_poisk();
};

//меню изменения параметров
Queue<Cognitive_book> menu_correct(Queue<Cognitive_book> T,
	int size, int pos);