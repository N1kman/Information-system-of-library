#include "Fiction_book.h"

/***���������� ��������� ������������***/
Fiction_book Fiction_book::operator=(const Fiction_book& T)
{
    if (this != &T)
    {
       _id = T._id;
        strcpy_s(_name, T._name);
        strcpy_s(_second_name, T._second_name);
        strcpy_s(_title, T._title);
        _copies = T._copies;
        _no_active = T._no_active;
        strcpy_s(_genre, T._genre);
    }
    return *this;
}

/***���������� ��������� �����***/
bool Fiction_book::operator==(const Fiction_book& T)
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

    if (T._genre[0])
    {
        if (strcmp(_genre, T._genre))
            return false;
    }
    return true;
}

/***���������� ��������� ������***/
bool Fiction_book::operator>(const Fiction_book& T)
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

    if (T._genre[0])
    {
        if (strcmp(_genre, T._genre) <= 0)
            return false;
    }
    return true;
}

/***���������� ��������� ������***/
bool Fiction_book::operator<(const Fiction_book& T)
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

    if (T._genre[0])
    {
        if (strcmp(_genre, T._genre) >= 0)
            return false;
    }
    return true;
}

/***��������� ���� �����***/
char* Fiction_book::get_genre()
{
    return &(_genre[0]);
}

/***��������� ���� �����***/
void Fiction_book::set_genre(const char* genre)
{
    strcpy_s(_genre, genre);
}

/***���������� ������***/
std::ostream& operator<<(std::ostream& out, 
    const Fiction_book& T)
{
    for (int i = 0; i < 88; i++)
        cout << "-";
    cout << endl;
    out << dynamic_cast<const Book&>(T);
    out << left << setw(12)
        << T._genre << "|" << endl;
    for (int i = 0; i < 88; i++)
        cout << "-";
    cout << endl;
    return out;
}

/***���������� �����***/
std::istream& operator>>(std::istream& in, Fiction_book& T)
{
    cin >> dynamic_cast<Book&>(T);
    cout << "������� ����(�� ������� �����):" << endl;
    input_rus(in, T._genre);
    return in;
}

/***����� �������***/
void Fiction_book::table()
{
    for (int i = 0; i < 88; i++)
        cout << "-";
    cout << endl;
    Book::table();
    cout << "����        |" << endl;
    for (int i = 0; i < 88; i++)
        cout << "-";
    cout << endl;
}

/*__________���������� ������ � ��������� �����__________*/
std::fstream& operator<<(std::fstream& out, Fiction_book& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T), 
        sizeof(Fiction_book));
    return out;
}

/*__________���������� ������ �� ��������� �����__________*/
std::fstream& operator>>(std::fstream& is, Fiction_book& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T), 
        sizeof(Fiction_book));
    return is;
}

/***���� ����������***/
int Fiction_book::menu_sort()
{
    cout << "1 - ���������� �� �����." << endl;
    cout << "2 - ���������� �� �������." << endl;
    cout << "3 - ���������� �� ���������." << endl;
    cout << "4 - ���������� �� ���������� ����." << endl;
    cout << "5 - ���������� �� ���������� ��������� ����." << endl;
    cout << "6 - ���������� �� �����." << endl;
    return input_int(cin, 1, 6);
}

/***�������� ������ ������� � ��������� �����***/
Fiction_book Fiction_book::copy_place(int choice)
{
    Fiction_book obj;
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

        obj.set_genre(_genre);
        break;

    }
    return obj;
}

//���� ��������� ����������
Queue<Fiction_book> menu_correct(Queue<Fiction_book> T,
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
        choice = input_int(cin, 0, 5);

        switch (choice)
        {
        case 1:

            system("CLS");
            cout << "������� ��� ������(�� ������� �����):" << endl;
            input_rus(cin, T[pos].get_name());
            system("cls");
            setColor(2);
            cout << "��� ��������!" << endl;
            setColor(6);
            break;

        case 2:

            system("CLS");
            cout << "������� ������� ������(�� ������� �����):" << endl;
            input_rus(cin, T[pos].get_second_name());
            system("cls");
            setColor(2);
            cout << "������� ��������!" << endl;
            setColor(6);
            break;

        case 3:

            system("CLS");
            cout << "������� �������� �����(�� ������� �����):" << endl;
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
            cout << "������� ���� �����(�� ������� �����):" << endl;
            input_rus(cin, T[pos].get_genre());
            system("cls");
            setColor(2);
            cout << "���� �������!" << endl;
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
Fiction_book Fiction_book::menu_for_poisk()
{
    Fiction_book mas;

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
        setColor(2);
        cout << ">> 0 - ������ �����.                                   " << endl;
        setColor(6);
        choice = input_int(cin, 0, 5);
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
                input_rus(cin, mas.get_genre());
                system("cls");
                setColor(2);
                cout << "���� ����������!" << endl;
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