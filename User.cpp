#include "User.h"

/***���������� ��������� ���������***/
bool User::operator>(const User& T)
{
    if (strcmp(_second_name, T._second_name) <= 0)
        return false;
    return true;
}

/***����������***/
User::~User() {}

/***��������� ���� ������������***/
int& User::get_id()
{
    return _id;
}

/***��������� ���� ������������***/
void User::set_id(int id)
{
    _id = id;
}

/***��������� ������ ������������***/
char* User::get_password()
{
    return &(_password[0]);
}

/***��������� ������ ������������***/
void User::set_password(const char* password)
{
    strcpy_s(_password, password);
}

/***��������� ����� ������������***/
char* User::get_name()
{
    return &(_name[0]);
}

/***��������� ����� ������������***/
void User::set_name(const char* name)
{
    strcpy_s(_name, name);
}

/***��������� ������� ������������***/
char* User::get_second_name()
{
    return &(_second_name[0]);
}

/***��������� ������� ������������***/
void User::set_second_name(const char* second_name)
{
    strcpy_s(_second_name, second_name);
}

/***���������� ������***/
std::ostream& operator<<(std::ostream& out, const User& T)
{
    out << "|" << setw(10) << left << T._id << " " << "|" << setw(8)
        << T._password << " " << "|" << setw(12) << T._name
        << " " << "|" << setw(12) << T._second_name << " " << "|" << right;
    return out;
}

/***���������� �����***/
std::istream& operator>>(std::istream& in, User& T)
{
    cout << "������� ���:(�� ������� �����)" << endl;
    input_rus(in, T._name);
    cout << "������� �������(�� ������� �����):" << endl;
    input_rus(in, T._second_name);
    cout << "������� ������(8 ��������):" << endl;
    input_password(in, T._password);

    return in;
}

/***����� �������***/
void User::table()
{
    cout << "|����(���.) |������   |���          |�������      |";
}

/*__________���������� ������ � ��������� �����__________*/
std::fstream& operator<<(std::fstream& out, User& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T),
        sizeof(User));
    return out;
}

/*__________���������� ������ �� ��������� �����__________*/
std::fstream& operator>>(std::fstream& is, User& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T), 
        sizeof(User));
    return is;
}

/***�������� ����***/
bool User::check_id(int id)
{
    if (_id == id)return true;
    else return false;
}
