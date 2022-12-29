#include "Member.h"

/***ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ***/
Member Member::operator=(const Member& T)
{
    if (this != &T)
    {
        this->_id = T._id;
        strcpy_s(this->_password, T._password);
        strcpy_s(this->_name, T._name);
        strcpy_s(this->_second_name, T._second_name);
        this->_status = T._status;
    }
    return *this;
}

/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
bool Member::operator==(const Member& T)
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

    if (T._status != -1)
    {
        if (_status != T._status)
            return false;
    }

    return true;
}

/***ПЕРЕГРУЗКА ОПЕРАТОРА БОЛЬШЕ***/
bool Member::operator>(const Member& T)
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

    if (T._status != -1)
    {
        if (_status <= T._status)
            return false;
    }

    return true;
}

/***ПЕРЕГРУЗКА ОПЕРАТОРА МЕНЬШЕ***/
bool Member::operator<(const Member& T)
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

    if (T._status != -1)
    {
        if (_status >= T._status)
            return false;
    }

    return true;
}

/***ПОЛУЧЕНИЕ СТАТУСА***/
int& Member::get_status()
{
    return _status;
}

/***УСТАНОВКА СТАТУСА***/
void Member::set_status(int status)
{
    _status = status;
}

/***ПЕРЕГРУЗКА ВЫВОДА***/
std::ostream& operator<<(std::ostream& out, const Member& T)
{
    for (int i = 0; i < 58; i++)
        cout << "-";
    cout << endl;
    out << dynamic_cast<const User&>(T);
    out << setw(6) << T._status << "|" << endl;
    for (int i = 0; i < 58; i++)
        cout << "-";
    cout << endl;
    return out;
}

/***ПЕРЕГРУЗКА ВВОДА***/
std::istream& operator>>(std::istream& in, Member& T)
{
    in >> dynamic_cast<User&>(T);
    T.set_status(0);
    return in;
}

/*__________перегрузка вывода в бинарного файла__________*/
std::fstream& operator<<(std::fstream& out, Member& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T),
        sizeof(Member));
    return out;
}

/*__________перегрузка чтения из бинарного файла__________*/
std::fstream& operator>>(std::fstream& is, Member& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T),
        sizeof(Member));
    return is;
}

/***ВЫВОД ТАБЛИЦЫ***/
void Member::table()
{
    for (int i = 0; i < 58; i++)
        cout << "-";
    cout << endl;
    User::table();
    cout << "Статус|" << endl;
    for (int i = 0; i < 58; i++)
        cout << "-";
    cout << endl;
}

/***МЕНЮ СОРТИРОВКИ***/
int Member::menu_sort()
{
    cout << "1 - сортировка по имени." << endl;
    cout << "2 - сортировка по фамилии." << endl;
    cout << "3 - сортировка по статусу." << endl;
    return input_int(cin, 1, 3);
}

/***Создание нового объекта с выбранным полем***/
Member Member::copy_place(int choice)
{
    Member obj;
    switch (choice)
    {
    case 1:

        obj.set_name(_name);
        break;

    case 2:

        obj.set_second_name(_second_name);
        break;

    case 3:

        obj.set_status(_status);
        break;

    }
    return obj;
}

//меню изменения параметров
Queue<Member> menu_correct(Queue<Member> T, 
    int size, int pos)
{
    for (int choice = 1; choice;)
    {
        cout << "0 - выход." << endl;
        cout << "1 - изменить имя" << endl;
        cout << "2 - изменить фамилию." << endl;
        cout << "3 - изменить пароль." << endl;
        cout << "4 - изменить статус." << endl;
        choice = input_int(cin, 0, 4);

        switch (choice)
        {
        case 1:

            system("cls");
            cout << "Введите имя(на русском языке):" << endl;
            input_rus(cin, T[pos].get_name());
            system("cls");
            setColor(2);
            cout << "Имя изменено!" << endl;
            setColor(6);
            break;

        case 2:

            system("cls");
            cout << "Введите фамилию(на русском языке):" << endl;
            input_rus(cin, T[pos].get_second_name());
            system("cls");
            setColor(2);
            cout << "Фамилия изменена!" << endl;
            setColor(6);
            break;

        case 3:

            system("cls");
            cout << "Введите пароль(8 символов):" << endl;
            input_password(cin, T[pos].get_password());
            system("cls");
            setColor(2);
            cout << "Пароль изменен!" << endl;
            setColor(6);
            break;

        case 4:

            system("cls");
            cout << "Введите статус(0 - обычный режим, 1 - заблокировать):" << endl;
            T[pos].set_status(input_int(cin, 0, 1));
            system("cls");
            setColor(2);
            cout << "Cтатус изменен!" << endl;
            setColor(6);
            break;

        default:

            system("CLS");
            break;
        }
    }
    return T;
}

/*__________функция меню для поиска__________*/
Member Member::menu_for_poisk()
{
    Member mas;

    for (int choice = 1; choice;)
    {
        setColor(5);
        cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
        cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
        setColor(2);
        cout << "_______#####________SEARCH___MEMBER________#####_______" << endl;
        setColor(5);
        cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
        setColor(6);
        cout << ">> 1 - ввести имя.                                     " << endl;
        cout << ">> 2 - ввести фамилию.                                 " << endl;
        cout << ">> 3 - ввести статус.                   " << endl;
        setColor(2);
        cout << ">> 0 - начать поиск.                                   " << endl;
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
                cout << "Введите имя(на русском языке):" << endl;
                input_rus(cin, mas.get_name());
                system("cls");
                setColor(2);
                cout << "Имя установлено!" << endl;
                setColor(6);
                break;

            case 2:

                system("cls");
                cout << "Введите фамилию(на русском языке):" << endl;
                input_rus(cin, mas.get_second_name());
                system("cls");
                setColor(2);
                cout << "Фамилия установлена!" << endl;
                setColor(6);
                break;

            case 3:

                system("cls");
                cout << "Введите статус(0 - обычный режим, 1 - блокировка):" << endl;
                mas.set_status(input_int(cin, 0, 1));
                system("cls");
                setColor(2);
                cout << "Статус установлен!" << endl;
                setColor(6);
                break;

            default:

                system("cls");
                throw Container_error(8, "Ошибка выбора меню", 
                    "Доступные опции 0-6");
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