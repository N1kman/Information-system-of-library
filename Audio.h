#pragma once
#include "standart.h"
#include "Literature.h"
#include "Queue.cpp"

/***КЛАСС АУДИОКНИГИ***/
class Audio : public Literature
{
private:

	int _time;       //приблизительное время книги в минутах 

public:

	/***КОНСТРУКТОР С/БЕЗ ПАРАМЕТРОВ***/
	Audio(int id = -1, const char* name = "",
		const char* second_name = "",
		const char* title = "", int time = -1) :
		Literature(id, name, second_name, title)
	{
		this->_time = time;
	}

	/***ДЕСТРУКТОР***/
	virtual ~Audio() {};

	/***КОНСТРУКТОР КОПИРОВАНИЯ***/
	Audio(const Audio& T) :
		Literature(dynamic_cast<const Literature&>(T))
	{
		this->_time = T._time;
	}

	/***ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ***/
	Audio operator=(const Audio& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
	bool operator==(const Audio& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА БОЛЬШЕ***/
	bool operator>(const Audio& T);

	/***ПЕРЕГРУЗКА ОПЕРАТОРА МЕНЬШЕ***/
	bool operator<(const Audio& T);

	/***ПОЛУЧЕНИЕ ДЛИТЕЛЬНОСТИ КНИГИ***/
	int& get_time();

	/***УСТАНОВКА ДЛИТЕЛЬНОСТИ КНИГИ***/
	void set_time(int time);

	/***ПЕРЕГРУЗКА ВЫВОДА***/
	friend std::ostream& operator<<(std::ostream& out, 
		const  Audio& T);

	/***ПЕРЕГРУЗКА ВВОДА***/
	friend std::istream& operator>>(std::istream& in, Audio& T);

	/*__________перегрузка вывода в бинарного файла__________*/
	friend std::fstream& operator<<(std::fstream& out, Audio& T);

	/*__________перегрузка чтения из бинарного файла__________*/
	friend std::fstream& operator>>(std::fstream& is, Audio& T);

	/***ВЫВОД ТАБЛИЦЫ***/
	virtual void table();

	/***МЕНЮ СОРТИРОВКИ***/
	int menu_sort();

	/***Создание нового объекта с выбранным полем***/
	Audio copy_place(int choice);

	/*__________функция меню для поиска__________*/
	Audio menu_for_poisk();
};

//меню изменения параметров
Queue<Audio> menu_correct(Queue<Audio> T, int size, int pos);