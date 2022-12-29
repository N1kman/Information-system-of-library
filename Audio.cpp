#include "Audio.h"

/***ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ***/
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

/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
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

/***ПЕРЕГРУЗКА ОПЕРАТОРА БОЛЬШЕ***/
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

/***ПЕРЕГРУЗКА ОПЕРАТОРА МЕНЬШЕ***/
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

/***ПОЛУЧЕНИЕ ДЛИТЕЛЬНОСТИ КНИГИ***/
int& Audio::get_time()
{
    return _time;
}

/***УСТАНОВКА ДЛИТЕЛЬНОСТИ КНИГИ***/
void Audio::set_time(int time)
{
    _time = time;
}

/***ПЕРЕГРУЗКА ВЫВОДА***/
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

/***ПЕРЕГРУЗКА ВВОДА***/
std::istream& operator>>(std::istream& in, Audio& T)
{
    in >> dynamic_cast<Literature&>(T);
    cout << "Введите длительность книги(в минутах):" 
        << endl;
    T._time = input_int(in, 1, 99999);
  
    return in;
}

/***ВЫВОД ТАБЛИЦЫ***/
void Audio::table()
{
    for (int i = 0; i < 75; i++)
        cout << "-";
    cout << endl;
    Literature::table();
    cout << "Длительность(мин)|" << endl;
    for (int i = 0; i < 75; i++)
        cout << "-";
    cout << endl;
}

/*__________перегрузка вывода в бинарного файла__________*/
std::fstream& operator<<(std::fstream& out, Audio& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T), 
        sizeof(Audio));
    return out;
}

/*__________перегрузка чтения из бинарного файла__________*/
std::fstream& operator>>(std::fstream& is, Audio& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T), 
        sizeof(Audio));
    return is;
}

/***МЕНЮ СОРТИРОВКИ***/
int Audio::menu_sort()
{
    cout << "1 - сортировка по имени." << endl;
    cout << "2 - сортировка по фамилии." << endl;
    cout << "3 - сортировка по заголовку." << endl;
    cout << "4 - сортировка по длительности." << endl;
    return input_int(cin, 1, 4);
}

/***Создание нового объекта с выбранным полем***/
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

//меню изменения параметров
Queue<Audio> menu_correct(Queue<Audio> T, int size,
    int pos)
{
    for (int choice = 1; choice;)
    {
        cout << "0 - выход." << endl;
        cout << "1 - изменить имя" << endl;
        cout << "2 - изменить фамилию." << endl;
        cout << "3 - изменить название." << endl;
        cout << "4 - изменить длительность." << endl;
        choice = input_int(cin, 0, 4);
        switch (choice)
        {
        case 1:

            system("CLS");
            cout << "Введите имя автора(на русском языке):" << endl;
            input_rus(cin, T[pos].get_name());
            system("cls");
            setColor(2);
            cout << "Имя изменено!" << endl;
            setColor(6);
            break;

        case 2:

            system("CLS");
            cout << "Введите фамилию автора(на русском языке):" << endl;
            input_rus(cin, T[pos].get_second_name());
            system("cls");
            setColor(2);
            cout << "Фамилия изменена!" << endl;
            setColor(6);
            break;

        case 3:

            system("CLS");
            cout << "Введите название книги(на русском языке):" << endl;
            input_rus(cin, T[pos].get_title());
            system("cls");
            setColor(2);
            cout << "Название изменено!" << endl;
            setColor(6);
            break;

        case 4:

            system("CLS");
            cout << "Введите длительность(в минутах):" << endl;
            T[pos].set_time(input_int(cin, 1, 99999));
            system("cls");
            setColor(2);
            cout << "Длительность изменена!" << endl;
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
        cout << ">> 1 - ввести имя.                                     " << endl;
        cout << ">> 2 - ввести фамилию.                                 " << endl;
        cout << ">> 3 - ввести название книги.                          " << endl;
        cout << ">> 4 - ввести длительность книги.                      " << endl;
        setColor(2);
        cout << ">> 0 - начать поиск.                                   " << endl;
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
                cout << "Введите название книги(на русском языке):" << endl;
                input_rus(cin, mas.get_title());
                system("cls");
                setColor(2);
                cout << "Название установлено!" << endl;
                setColor(6);
                break;

            case 4:

                system("cls");
                cout << "Введите длительность книги(в минутах):" << endl;
                mas.set_time(input_int(cin, 1, 99999));
                system("cls");
                setColor(2);
                cout << "Длительность установлена!" << endl;
                setColor(6);
                break;

            default:
                system("cls");
                throw Container_error(8, "Ошибка выбора меню", "Доступные опции 0-6");
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