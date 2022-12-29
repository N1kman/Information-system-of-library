#include "Book.h"

/***����������***/
Book::~Book() {}

/***��������� ���������� �����***/
int& Book::get_copies()
{
    return _copies;
}

/***��������� ���������� ������***/
void Book::set_copies(int copies)
{
    _copies = copies;
}

/***��������� ���������� ����� �������� ����***/
int& Book::get_no_active()
{
    return _no_active;
}

/***��������� ���������� ��������� ����***/
void Book::set_no_active(int no_active)
{
    _no_active = no_active;
}

/***���������� �����***/
std::istream& operator>>(std::istream& in, Book& T)
{
    in >> dynamic_cast<Literature&>(T);
    int buff;
    cout << "������� ���������� �����:" << endl;
    buff = input_int(in, 1, 30);
    T._copies = buff;
    T._no_active = buff;

    return in;
}

/***���������� ������***/
std::ostream& operator<<(std::ostream& out, const Book& T)
{
    out << dynamic_cast<const Literature&>(T);
    out << left << setw(6) << T._copies << " |"
        << setw(9) << T._no_active << "|" << right;
    return out;
}

/***����� �������***/
void Book::table()
{
    Literature::table();
    cout << "�����  |���������|";
}
