#include "Admin.h"

/***���������� ��������� ������������***/
Admin Admin::operator=(const Admin& T)
{
    if (this != &T)
    {
        this->_id = T._id;
        strcpy_s(this->_password, T._password);
        strcpy_s(this->_name, T._name);
        strcpy_s(this->_second_name, T._second_name);
        this->_time_of_work = T._time_of_work;
    }
    return *this;
}

/***���������� ��������� �����***/
bool Admin::operator==(const Admin& T)
{
    if (T._name[0])
    {
        if (strcmp(_name, T._name))
            return false;
    }

    if (T._second_name[0])
    {
        if (strcmp(_second_name, T._second_name))
            return false;
    }

    if (T._time_of_work.day)
    {
        if (!(_time_of_work == T._time_of_work))
            return false;
    }

    return true;
}

/***���������� ��������� ������***/
bool Admin::operator>(const Admin& T)
{
    if (T._name[0])
    {
        if (strcmp(_name, T._name) <= 0)
            return false;
    }

    if (T._second_name[0])
    {
        if (strcmp(_second_name, T._second_name) <= 0)
            return false;
    }

    if (T._time_of_work.day)
    {
        if (_time_of_work > T._time_of_work)
            return false;
    }

    return true;
}

/***���������� ��������� ������***/
bool Admin::operator<(const Admin& T)
{
    if (T._name[0])
    {
        if (strcmp(_name, T._name) >= 0)
            return false;
    }

    if (T._second_name[0])
    {
        if (strcmp(_second_name, T._second_name) >= 0)
            return false;
    }

    if (T._time_of_work.day)
    {
        if (_time_of_work < T._time_of_work)
            return false;
    }

    return true;
}

/***��������� ���� �����***/
void Admin::set_time_of_work(date time_of_work)
{
    _time_of_work = time_of_work;
}

/***��������� ���� �����***/
date& Admin::get_time_of_work()
{
    return _time_of_work;
}

/***���������� ������***/
std::ostream& operator<<(std::ostream& out, const Admin& T)
{
    for (int i = 0; i < 63; i++)
        cout << "-";
    cout << endl;
    out << dynamic_cast<const User&>(T);
    out << setfill('0')
        << T._time_of_work << " " << "|" 
        << endl << setfill(' ');
    for (int i = 0; i < 63; i++)
        cout << "-";
    cout << endl;
    return out;
}

/***����� �������***/
void Admin::table()
{
    for (int i = 0; i < 63; i++)
        cout << "-";
    cout << endl;
    User::table();
    cout << "���� ����� |" << endl;
    for (int i = 0; i < 63; i++)
        cout << "-";
    cout << endl;
}

/*__________���������� ������ � ��������� �����__________*/
std::fstream& operator<<(std::fstream& out, Admin& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T),
        sizeof(Admin));
    return out;
}

/*__________���������� ������ �� ��������� �����__________*/
std::fstream& operator>>(std::fstream& is, Admin& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T), 
        sizeof(Admin));
    return is;
}

/***���� ����������***/
int Admin::menu_sort()
{
    cout << "1 - ���������� �� �����." << endl;
    cout << "2 - ���������� �� �������." << endl;
    cout << "3 - ���������� �� ���� ���������� �����." << endl;
    return input_int(cin, 1, 3);
}

/***�������� ������ ������� � ��������� �����***/
Admin Admin::copy_place(int choice)
{
    Admin obj;
    switch (choice)
    {
    case 1:
        obj.set_name(_name);
        break;

    case 2:
        obj.set_second_name(_second_name);
        break;

    case 3:
        obj.set_time_of_work(_time_of_work);
        break;

    }
    return obj;
}

//���� ��������� ����������
Queue<Admin> menu_correct(Queue<Admin> T, int size, int pos)
{
    for (int choice = 1; choice;)
    {
        cout << "0 - �����." << endl;
        cout << "1 - �������� ���" << endl;
        cout << "2 - �������� �������." << endl;
        cout << "3 - �������� ������." << endl;
        choice = input_int(cin, 0, 3);

        switch (choice)
        {
        case 1:
            system("CLS");
            cout << "������� ���(�� ������� �����):" << endl;
            input_rus(cin, T[pos].get_name());
            system("cls");
            setColor(2);
            cout << "��� ��������!" << endl;
            setColor(6);
            break;

        case 2:
            system("CLS");
            cout << "������� �������(�� ������� �����):" << endl;
            input_rus(cin, T[pos].get_second_name());
            system("cls");
            setColor(2);
            cout << "������� ��������!" << endl;
            setColor(6);
            break;

        case 3:
            system("CLS");
            cout << "������� ������(8 ��������):" << endl;
            input_password(cin, T[pos].get_password());
            system("cls");
            setColor(2);
            cout << "������ �������!" << endl;
            setColor(6);
            break;

        default:
            system("CLS");
            break;
        }
    }
    return T;
}

/*__________������� ���� ��� ������__________*/
Admin Admin::menu_for_poisk()
{
    Admin mas;

    for (int choice = 1; choice;)
    {
        setColor(5);
        cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
        cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
        setColor(2);
        cout << "_______#####_________SEARCH___ADMIN________#####_______" << endl;
        setColor(5);
        cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
        setColor(11);
        cout << ">> 1 - ������ ���.                                     " << endl;
        cout << ">> 2 - ������ �������.                                 " << endl;
        cout << ">> 3 - ������ ���� ���������� �����.                   " << endl;
        setColor(2);
        cout << ">> 0 - ������ �����.                                   " << endl;
        setColor(6);
        choice = input_int(cin, 0, 3);
        try
        {
            switch (choice)
            {
            case 0:
                system("cls");
                break;

            case 1:
                system("cls");
                cout << "������� ���(�� ������� �����):" << endl;
                input_rus(cin, mas.get_name());
                system("cls");
                setColor(2);
                cout << "��� �����������!" << endl;
                setColor(6);
                break;

            case 2:
                system("cls");
                cout << "������� �������(�� ������� �����):" << endl;
                input_rus(cin, mas.get_second_name());
                system("cls");
                setColor(2);
                cout << "������� �����������!" << endl;
                setColor(6);
                break;

            case 3:
                system("cls");
                cin >> mas.get_time_of_work();
                system("cls");
                setColor(2);
                cout << "���� ���������� ����� �����������!" << endl;
                setColor(6);
                break;

            default:
                system("cls");
                throw Container_error(8, "������ ������ ����", 
                    "��������� ����� 0-6");
                break;
            }
        }
        catch (Container_error obj)
        {
            obj.show_e();
        }
    }
    return mas;
}