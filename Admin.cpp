#include "Admin.h"

/***ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ***/
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

/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
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

/***ПЕРЕГРУЗКА ОПЕРАТОРА БОЛЬШЕ***/
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

/***ПЕРЕГРУЗКА ОПЕРАТОРА МЕНЬШЕ***/
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

/***УСТАНОВКА ДАТЫ ВХОДА***/
void Admin::set_time_of_work(date time_of_work)
{
    _time_of_work = time_of_work;
}

/***ПОЛУЧЕНИЕ ДАТЫ ВХОДА***/
date& Admin::get_time_of_work()
{
    return _time_of_work;
}

/***ПЕРЕГРУЗКА ВЫВОДА***/
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

/***ВЫВОД ТАБЛИЦЫ***/
void Admin::table()
{
    for (int i = 0; i < 63; i++)
        cout << "-";
    cout << endl;
    User::table();
    cout << "Дата входа |" << endl;
    for (int i = 0; i < 63; i++)
        cout << "-";
    cout << endl;
}

/*__________перегрузка вывода в бинарного файла__________*/
std::fstream& operator<<(std::fstream& out, Admin& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T),
        sizeof(Admin));
    return out;
}

/*__________перегрузка чтения из бинарного файла__________*/
std::fstream& operator>>(std::fstream& is, Admin& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T), 
        sizeof(Admin));
    return is;
}

/***МЕНЮ СОРТИРОВКИ***/
int Admin::menu_sort()
{
    cout << "1 - сортировка по имени." << endl;
    cout << "2 - сортировка по фамилии." << endl;
    cout << "3 - сортировка по дате последнего входа." << endl;
    return input_int(cin, 1, 3);
}

/***Создание нового объекта с выбранным полем***/
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

//меню изменения параметров
Queue<Admin> menu_correct(Queue<Admin> T, int size, int pos)
{
    for (int choice = 1; choice;)
    {
        cout << "0 - выход." << endl;
        cout << "1 - изменить имя" << endl;
        cout << "2 - изменить фамилию." << endl;
        cout << "3 - изменить пароль." << endl;
        choice = input_int(cin, 0, 3);

        switch (choice)
        {
        case 1:
            system("CLS");
            cout << "Введите имя(на русском языке):" << endl;
            input_rus(cin, T[pos].get_name());
            system("cls");
            setColor(2);
            cout << "Имя изменено!" << endl;
            setColor(6);
            break;

        case 2:
            system("CLS");
            cout << "Введите фамилию(на русском языке):" << endl;
            input_rus(cin, T[pos].get_second_name());
            system("cls");
            setColor(2);
            cout << "Фамилия изменена!" << endl;
            setColor(6);
            break;

        case 3:
            system("CLS");
            cout << "Введите пароль(8 символов):" << endl;
            input_password(cin, T[pos].get_password());
            system("cls");
            setColor(2);
            cout << "Пароль изменен!" << endl;
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
        cout << ">> 1 - ввести имя.                                     " << endl;
        cout << ">> 2 - ввести фамилию.                                 " << endl;
        cout << ">> 3 - ввести дату последнего входа.                   " << endl;
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
                cin >> mas.get_time_of_work();
                system("cls");
                setColor(2);
                cout << "Дата последнего входа установлена!" << endl;
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