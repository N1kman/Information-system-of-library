#include "Literature.h"

/***����������***/
Literature::~Literature() {}

/***�������� ����***/
bool Literature::check_id(int id)
{
    if (_id == id)return true;
    else return false;
}

/***��������� ���� �����***/
int& Literature::get_id()
{
    return _id;
}

/***��������� ���� �����***/
void Literature::set_id(int id)
{
    _id = id;
}

/***��������� ����� ������ �����***/
char* Literature::get_name()
{
    return &(_name[0]);
}

/***��������� ����� ������ �����***/
void Literature::set_name(const char* name)
{
    strcpy_s(_name, name);
}

/***��������� ������� ������ �����***/
char* Literature::get_second_name()
{
    return &(_second_name[0]);
}

/***��������� ������� ������ �����***/
void Literature::set_second_name(const char* second_name)
{
    strcpy_s(_second_name, second_name);
}

/***��������� �������� �����***/
char* Literature::get_title()
{
    return &(_title[0]);
}

/***��������� �������� �����***/
void Literature::set_title(const char* title)
{
    strcpy_s(_title, title);
}

/***���������� ��������� ���������***/
bool Literature::operator>(const Literature& T)
{
    if (strcmp(_second_name, T._second_name) <= 0)
        return false;
    return true;
}

/***���������� ������***/
std::ostream& operator<<(std::ostream& out, const Literature& T)
{
    out << "|" << setw(10) << left << T._id 
        << "  " << "|" << setw(12)
        << T._title << " " << "|" << setw(12) << T._name
        << " " << "|" << setw(12) 
        << T._second_name << "  |" << right;
    return out;
}

/***���������� �����***/
std::istream& operator>>(std::istream& in, Literature& T)
{
    cout << "������� ��� ������(�� ������� �����):" << endl;
    input_rus(in, T._name);
    cout << "������� ������� ������(�� ������� �����):" << endl;
    input_rus(in, T._second_name);
    cout << "������� ���������(�� ������� �����):" << endl;
    input_rus(in, T._title);

    return in;
}

/***����� �������***/
void Literature::table()
{
    cout << "|����(�����) |���������    |��� ������   |������� ������|";
}