#include "Binary_file.h"

/*__________�������� ��������� �����__________*/
template<class T>
void Binary_file<T>::OpenFileIn()
{
	try
	{
		_file_stream.open(_file_name, ios::in | ios::binary);
		//�������� �� ������������� �����
		if (!_file_stream.good())
		{
			_file_stream.close();
			_file_stream.open(_file_name, ios::out | ios::binary | ios::trunc);
			_file_stream.close();
			_file_stream.open(_file_name, ios::in | ios::binary);
			throw File_error(14, "���� �� ������",
				"��������� ����������� �����. ��� ������ ����� ����");
		}
		//�������� �� �������� �����
		if (!_file_stream.is_open())
		{
			throw File_error(15, "���� �� ������",
				"��������� ����������� �����");
		}
	}
	catch (File_error er)
	{
		er.show_e();
	}
}

/*__________�������� ��������� �����__________*/
template<class T>
void Binary_file<T>::OpenFileOut()
{
	try
	{
		_file_stream.open(_file_name, ios::out | ios::binary | ios::trunc);
		//�������� �� �������� �����
		if (!_file_stream.is_open())
			throw File_error(15, "���� �� ������",
				"��������� ����������� �����");
	}
	catch (File_error er)
	{
		er.show_e();
	}
}

/*__________�������� ��������� �����__________*/
template<class T>
void Binary_file<T>::CloseFile()
{
	try
	{
		_file_stream.close();
		//�������� �� �������� �����
		if (_file_stream.is_open())
			throw File_error(15, "���� �� ������",
				"��������� ����������� �����");
	}
	catch (File_error er)
	{
		er.show_e();
		exit(1);
	}
}

/*__________�������� �� ����� �����__________*/
template<class T>
bool Binary_file<T>::isEndFile()
{
	return _file_stream.eof();
}

/*__________������������ �� ������ �����__________*/
template<class T>
void Binary_file<T>::remote()
{
	_file_stream.seekg(0, ios::beg);
}

/*__________������ �� �����__________*/
template<class T>
void Binary_file<T>::ReadFromFile(T& obj)
{
	_file_stream >> obj;
}

/*__________������ � ����__________*/
template<class T>
void Binary_file<T>::WriteInFile(T& obj)
{
	_file_stream << obj;
}
