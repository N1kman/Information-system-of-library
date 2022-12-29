#include "Scientific_book.h"

/***����������***/
Scientific_book::~Scientific_book() {}

/***��������� ���� �����***/
char* Scientific_book::get_topic()
{
    return &(_topic[0]);
}

/***��������� ���� �����***/
void Scientific_book::set_topic(const char* topic)
{
    strcpy_s(_topic, topic);
}

/***���������� ������***/
std::ostream& operator<<(std::ostream& out, const Scientific_book& T)
{
    out << dynamic_cast<const Book&>(T);
    out << left << setw(12) << T._topic << "|";
    return out;
}

/***���������� �����***/
std::istream& operator>>(std::istream& in, Scientific_book& T)
{
    cin >> dynamic_cast<Book&>(T);
    cout << "������� ����(�� ������� �����):" << endl;
    input_rus(in, T._topic);

    return in;
}

/***����� �������***/
void Scientific_book::table()
{
    Book::table();
    cout << "����        |";
}