#pragma once
#include "standart.h"
#include "File_error.h"

/***класс бинарного файла***/
template<class T>
class Binary_file 
{
private:

	char _file_name[_length_80];  //имя файла
	fstream _file_stream;         //поток

public:

	/*__________конструктор__________*/
	Binary_file(const char* name) 
	{
		strcpy_s(_file_name, name);
	}

	/*__________деструктор__________*/
	~Binary_file()
	{
		_file_stream.close();
	}

	/*__________открытие бинарного файла__________*/
	void OpenFileIn();

	/*__________открытие бинарного файла__________*/
	void OpenFileOut();

	/*__________закрытие бинарного файла__________*/
	void CloseFile();

	/*__________проверка на конец файла__________*/
	bool isEndFile();

	/*__________установление на начало файла__________*/
	void remote();

	/*__________чтение из файла__________*/
	void ReadFromFile(T& obj);

	/*__________запись в файл__________*/
	void WriteInFile(T& obj);
};

