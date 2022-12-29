#pragma once
#include "standart.h"
#include "Book.h"
#include "Queue.cpp"

/***КЛАСС ХУДОЖЕСТВЕННЫХ КНИГ***/
class Fiction_book : public Book
{
private:

	char _genre[length_12];     //жанр

public:

	/***КОНСТРУКТОР С/БЕЗ ПАРАМЕТРОВ***/
	Fiction_book(int id = -1, const char* name = "",
		const char* second_name = "",
		const char* title = "", int copies = -1,
		int no_active = -1, const char* genre = "") :
		Book(id, name, second_name, 
			title, copies, no_active)
	{
		strcpy_s(_genre, genre);
	}

	/***ДЕСТРУКТОР***/
	virtual ~Fiction_book() {}

	/***КОНСТРУКТОР КОПИРОВАНИЯ***/
	Fiction_book(const Fiction_book& T) :
		Book(dynamic_cast<const Book&>(T))
	{
		strcpy_s(_genre, T._genre);
	}

	/***ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ***/
	Fiction_book operator=(const Fiction_book& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
	bool operator==(const Fiction_book& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА БОЛЬШЕ***/
	bool operator>(const Fiction_book& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА МЕНЬШЕ***/
	bool operator<(const Fiction_book& T);

	/***ПОЛУЧЕНИЕ ТЕМЫ КНИГИ***/
	char* get_genre();

	/***УСТАНОВКА ТЕМЫ КНИГИ***/
	void set_genre(const char* topic);

	/***ПЕРЕГРУЗКА ВЫВОДА***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Fiction_book& T);

	/***ПЕРЕГРУЗКА ВВОДА***/
	friend std::istream& operator>>(std::istream& in, 
		Fiction_book& T);

	/*__________перегрузка вывода в бинарного файла__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		Fiction_book& T);

	/*__________перегрузка чтения из бинарного файла__________*/
	friend std::fstream& operator>>(std::fstream& is, 
		Fiction_book& T);

	/***ВЫВОД ТАБЛИЦЫ***/
	virtual void table();

	/***МЕНЮ СОРТИРОВКИ***/
	int menu_sort();

	/***Создание нового объекта с выбранным полем***/
	Fiction_book copy_place(int choice);

	/*__________функция меню для поиска__________*/
	Fiction_book menu_for_poisk();
};

//меню изменения параметров
Queue<Fiction_book> menu_correct(Queue<Fiction_book> T, 
	int size, int pos);