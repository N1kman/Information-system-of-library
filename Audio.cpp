#include "Audio.h"

/***���������� ��������� ������������***/
Audio Audio::operator=(const Audio& T)
{
    if (this != &T)
    {
        this->_id = T._id;
        strcpy_s(this->_name, T._name);
        strcpy_s(this->_second_name, T._second_name);
        strcpy_s(this->_title, T._title);
        this->_time = T._time;
    }
    return *this;
}

/***���������� ��������� �����***/
bool Audio::operator==(const Audio& T)
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

    if (T._time != -1)
    {
        if (_time != T._time)
            return false;
    }

    return true;
}

/***���������� ��������� ������***/
bool Audio::operator>(const Audio& T)
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

    if (T._time != -1)
    {
        if (_time <= T._time)
            return false;
    }

    return true;
}

/***���������� ��������� ������***/
bool Audio::operator<(const Audio& T)
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

    if (T._time != -1)
    {
        if (_time >= T._time)
            return false;
    }

    return true;
}

/***��������� ������������ �����***/
int& Audio::get_time()
{
    return _time;
}

/***��������� ������������ �����***/
void Audio::set_time(int time)
{
    _time = time;
}

/***���������� ������***/
std::ostream& operator<<(std::ostream& out, const  Audio& T)
{
    for (int i = 0; i < 75; i++)
        cout << "-";
    cout << endl;
    out << dynamic_cast<const Literature&>(T);
    out << setw(17) << T._time << "|" << endl;
    for (int i = 0; i < 75; i++)
        cout << "-";
    cout << endl;
    return out;
}

/***���������� �����***/
std::istream& operator>>(std::istream& in, Audio& T)
{
    in >> dynamic_cast<Literature&>(T);
    cout << "������� ������������ �����(� �������):" 
        << endl;
    T._time = input_int(in, 1, 99999);
  
    return in;
}

/***����� �������***/
void Audio::table()
{
    for (int i = 0; i < 75; i++)
        cout << "-";
    cout << endl;
    Literature::table();
    cout << "������������(���)|" << endl;
    for (int i = 0; i < 75; i++)
        cout << "-";
    cout << endl;
}

/*__________���������� ������ � ��������� �����__________*/
std::fstream& operator<<(std::fstream& out, Audio& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T), 
        sizeof(Audio));
    return out;
}

/*__________���������� ������ �� ��������� �����__________*/
std::fstream& operator>>(std::fstream& is, Audio& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T), 
        sizeof(Audio));
    return is;
}

/***���� ����������***/
int Audio::menu_sort()
{
    cout << "1 - ���������� �� �����." << endl;
    cout << "2 - ���������� �� �������." << endl;
    cout << "3 - ���������� �� ���������." << endl;
    cout << "4 - ���������� �� ������������." << endl;
    return input_int(cin, 1, 4);
}

/***�������� ������ ������� � ��������� �����***/
Audio Audio::copy_place(int choice)
{
    Audio obj;
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

        obj.set_time(_time);
        break;
    }
    return obj;
}

//���� ��������� ����������
Queue<Audio> menu_correct(Queue<Audio> T, int size,
    int pos)
{
    for (int choice = 1; choice;)
    {
        cout << "0 - �����." << endl;
        cout << "1 - �������� ���" << endl;
        cout << "2 - �������� �������." << endl;
        cout << "3 - �������� ��������." << endl;
        cout << "4 - �������� ������������." << endl;
        choice = input_int(cin, 0, 4);
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
            cout << "������� ������������(� �������):" << endl;
            T[pos].set_time(input_int(cin, 1, 99999));
            system("cls");
            setColor(2);
            cout << "������������ ��������!" << endl;
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
Audio Audio::menu_for_poisk()
{
    Audio mas;

    for (int choice = 1; choice;)
    {
        setColor(5);
        cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
        cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
        setColor(2);
        cout << "_______#####_________SEARCH___AUDIO________#####_______" << endl;
        setColor(5);
        cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
        setColor(6);
        cout << ">> 1 - ������ ���.                                     " << endl;
        cout << ">> 2 - ������ �������.                                 " << endl;
        cout << ">> 3 - ������ �������� �����.                          " << endl;
        cout << ">> 4 - ������ ������������ �����.                      " << endl;
        setColor(2);
        cout << ">> 0 - ������ �����.                                   " << endl;
        setColor(6);
        choice = input_int(cin, 0, 4);
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
                cout << "������� ������������ �����(� �������):" << endl;
                mas.set_time(input_int(cin, 1, 99999));
                system("cls");
                setColor(2);
                cout << "������������ �����������!" << endl;
                setColor(6);
                break;

            default:
                system("cls");
                throw Container_error(8, "������ ������ ����", "��������� ����� 0-6");
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