#include "Cognitive_book.h"

/***���������� ��������� ������������***/
Cognitive_book Cognitive_book::operator=(const Cognitive_book& T)
{
    if (this != &T)
    {
        _id = T._id;
        strcpy_s(_name, T._name);
        strcpy_s(_second_name, T._second_name);
        strcpy_s(_title, T._title);
        _copies = T._copies;
        _no_active = T._no_active;
        strcpy_s(_topic, T._topic);
        _sum_of_search = T._sum_of_search;
    }
    return *this;
}

/***���������� ��������� �����***/
bool Cognitive_book::operator==(const Cognitive_book& T)
{
    if (T._title[0])
    {
        if (strcmp(_title, T._title))
            return false;
    }

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

    if (T._copies != -1)
    {
        if (_copies != T._copies)
            return false;
    }

    if (T._no_active != -1)
    {
        if (_no_active != T._no_active)
            return false;
    }

    if (T._topic[0])
    {
        if (strcmp(_topic, T._topic))
            return false;
    }

    if (T._sum_of_search != -1)
    {
        if (_sum_of_search != T._sum_of_search)
            return false;
    }
    return true;
}

/***���������� ��������� ������***/
bool Cognitive_book::operator>(const Cognitive_book& T)
{
    if (T._title[0])
    {
        if (strcmp(_title, T._title) <= 0)
            return false;
    }

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

    if (T._copies != -1)
    {
        if (_copies <= T._copies)
            return false;
    }

    if (T._no_active != -1)
    {
        if (_no_active <= T._no_active)
            return false;
    }

    if (T._topic[0])
    {
        if (strcmp(_topic, T._topic) <= 0)
            return false;
    }

    if (T._sum_of_search != -1)
    {
        if (_sum_of_search <= T._sum_of_search)
            return false;
    }
    return true;
}

/***���������� ��������� ������***/
bool Cognitive_book::operator<(const Cognitive_book& T)
{
    if (T._title[0])
    {
        if (strcmp(_title, T._title) >= 0)
            return false;
    }

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

    if (T._copies != -1)
    {
        if (_copies >= T._copies)
            return false;
    }

    if (T._no_active != -1)
    {
        if (_no_active >= T._no_active)
            return false;
    }

    if (T._topic[0])
    {
        if (strcmp(_topic, T._topic) >= 0)
            return false;
    }

    if (T._sum_of_search != -1)
    {
        if (_sum_of_search >= T._sum_of_search)
            return false;
    }
    return true;
}

/***��������� ����� ������������***/
int& Cognitive_book::get_sum_of_search()
{
    return _sum_of_search;
}

/***��������� ����� ������������***/
void Cognitive_book::set_sum_of_search(int sum_of_search)
{
    _sum_of_search = sum_of_search;
}

/***���������� �����***/
std::istream& operator>>(std::istream& in, 
    Cognitive_book& T)
{
    in >> dynamic_cast<Scientific_book&>(T);
    cout << "������� ������ ������������(�� ������� �����):" << endl;
    T._sum_of_search = input_int(in, 1, 9999999);

    return in;
}

/***���������� ������***/
std::ostream& operator<<(std::ostream& out, 
    const Cognitive_book& T)
{
    for (int i = 0; i < 105; i++)
        cout << "-";
    cout << endl;
    out << dynamic_cast<const Scientific_book&>(T);
    out << left << setw(16)
        << T._sum_of_search << "|" << endl;
    for (int i = 0; i < 105; i++)
        cout << "-";
    cout << endl;
    return out;
}

/***����� �������***/
void Cognitive_book::table()
{
    for (int i = 0; i < 105; i++)
        cout << "-";
    cout << endl;
    Scientific_book::table();
    cout << "������(���.���.)|" << endl;
    for (int i = 0; i < 105; i++)
        cout << "-";
    cout << endl;
}

/*__________���������� ������ � ��������� �����__________*/
std::fstream& operator<<(std::fstream& out, Cognitive_book& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T), 
        sizeof(Cognitive_book));
    return out;
}

/*__________���������� ������ �� ��������� �����__________*/
std::fstream& operator>>(std::fstream& is, Cognitive_book& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T), 
        sizeof(Cognitive_book));
    return is;
}

/***���� ����������***/
int Cognitive_book::menu_sort()
{
    cout << "1 - ���������� �� �����." << endl;
    cout << "2 - ���������� �� �������." << endl;
    cout << "3 - ���������� �� ���������." << endl;
    cout << "4 - ���������� �� ���������� ����." << endl;
    cout << "5 - ���������� �� ���������� ��������� ����." << endl;
    cout << "6 - ���������� �� ����." << endl;
    cout << "7 - ���������� �� ����� ������������." << endl;
    return input_int(cin, 1, 7);
}

/***�������� ������ ������� � ��������� �����***/
Cognitive_book Cognitive_book::copy_place(int choice)
{
    Cognitive_book obj;
    switch (choice)
    {
    case 1:

        obj.set_name(_name);
        break;

    case 2:

        obj.set_second_name(_second_name);
        break;

    case 3:

        obj.set_title(_title);
        break;

    case 4:

        obj.set_copies(_copies);
        break;

    case 5:

        obj.set_no_active(_no_active);
        break;

    case 6:

        obj.set_topic(_topic);
        break;

    case 7:

        obj.set_sum_of_search(_sum_of_search);
        break;

    }
    return obj;
}

//���� ��������� ����������
Queue<Cognitive_book> menu_correct(Queue<Cognitive_book> T, 
    int size, int pos)
{
    for (int choice = 1; choice;)
    {
        cout << "0 - �����." << endl;
        cout << "1 - �������� ���" << endl;
        cout << "2 - �������� �������." << endl;
        cout << "3 - �������� ��������." << endl;
        cout << "4 - �������� ���������� �����." << endl;
        cout << "5 - �������� ����." << endl;
        cout << "6 - �������� ����������� �������� �� ������������." << endl;
        choice = input_int(cin, 0, 6);
        switch (choice)
        {
        case 1:

            system("CLS");
            cout << "������� ��� ������:" << endl;
            input_rus(cin, T[pos].get_name());
            system("cls");
            setColor(2);
            cout << "��� ��������!" << endl;
            setColor(6);
            break;

        case 2:

            system("CLS");
            cout << "������� ������� ������:" << endl;
            input_rus(cin, T[pos].get_second_name());
            system("cls");
            setColor(2);
            cout << "������� ��������!" << endl;
            setColor(6);
            break;

        case 3:

            system("CLS");
            cout << "������� �������� �����:" << endl;
            input_rus(cin, T[pos].get_title());
            system("cls");
            setColor(2);
            cout << "�������� ��������!" << endl;
            setColor(6);
            break;

        case 4:

            system("CLS");
            cout << "������� ���������� �����:" << endl;
            T[pos].set_copies(input_int(cin, 1, 30));
            system("cls");
            setColor(2);
            cout << "���������� ����� ��������!" << endl;
            setColor(6);
            break;

        case 5:

            system("CLS");
            cout << "������� ���� �����:" << endl;
            input_rus(cin, T[pos].get_topic());
            system("cls");
            setColor(2);
            cout << "���� ��������!" << endl;
            setColor(6);
            break;

        case 6:

            system("CLS");
            cout << "������� ����������� �������� �� ������������:" << endl;
            T[pos].set_sum_of_search(input_int(cin, 1, 999999));
            system("cls");
            setColor(2);
            cout << "����������� �������� ��������!" << endl;
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
Cognitive_book Cognitive_book::menu_for_poisk()
{
    Cognitive_book mas;

    for (int choice = 1; choice;)
    {
        setColor(5);
        cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
        cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
        setColor(2);
        cout << "______#####______SEARCH___FICTION_BOOK_______#####_____" << endl;
        setColor(5);
        cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
        setColor(6);
        cout << ">> 1 - ������ ���.                                     " << endl;
        cout << ">> 2 - ������ �������.                                 " << endl;
        cout << ">> 3 - ������ �������� �����.                          " << endl;
        cout << ">> 4 - ������ ���������� �����.                        " << endl;
        cout << ">> 5 - ������ ����.                                    " << endl;
        cout << ">> 6 - ������ ������ ������������.                     " << endl;
        setColor(2);
        cout << ">> 0 - ������ �����.                                   " << endl;
        setColor(6);
        choice = input_int(cin, 0, 6);
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
                cout << "������� �������� �����(�� ������� �����):" << endl;
                input_rus(cin, mas.get_title());
                system("cls");
                setColor(2);
                cout << "�������� �����������!" << endl;
                setColor(6);
                break;

            case 4:

                system("cls");
                cout << "������� ���������� �����:" << endl;
                mas.set_copies(input_int(cin, 1, 99999));
                system("cls");
                setColor(2);
                cout << "���������� ����� �����������!" << endl;
                setColor(6);
                break;

            case 5:

                system("cls");
                cout << "������� ���� �����(�� ������� �����):" << endl;
                input_rus(cin, mas.get_topic());
                system("cls");
                setColor(2);
                cout << "���� �����������!" << endl;
                setColor(6);
                break;

            case 6:

                system("cls");
                cout << "������� ������ ������������:" << endl;
                mas.set_sum_of_search(input_int(cin, 1, 999999));
                system("cls");
                setColor(2);
                cout << "������ ������������ ����������!" << endl;
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
