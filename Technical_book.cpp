#include "Technical_book.h"

/***ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ***/
Technical_book Technical_book::operator=(const Technical_book& T)
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
        strcpy_s(_application_area, T._application_area);
    }
    return *this;
}

/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
bool Technical_book::operator==(const Technical_book& T)
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

    if (T._application_area[0])
    {
        if (strcmp(_application_area, T._application_area))
            return false;
    }
    return true;
}

/***ПЕРЕГРУЗКА ОПЕРАТОРА БОЛЬШЕ***/
bool Technical_book::operator>(const Technical_book& T)
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

    if (T._application_area[0])
    {
        if (strcmp(_application_area, T._application_area) <= 0)
            return false;
    }
    return true;
}

/***ПЕРЕГРУЗКА ОПЕРАТОРА МЕНЬШЕ***/
bool Technical_book::operator<(const Technical_book& T)
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

    if (T._application_area[0])
    {
        if (strcmp(_application_area, T._application_area) >= 0)
            return false;
    }
    return true;
}

/***ПОЛУЧЕНИЕ ОБЛАСТИ ПРИМЕНЕНИЯ***/
char* Technical_book::get_application_area()
{
    return &(_application_area[0]);
}

/***УСТАНОВКА ОБЛАСТИ ПРИМЕНЕНИЯ***/
void Technical_book::set_application_area(const char* application_area)
{
    strcpy_s(_application_area, application_area);
}

/***ПЕРЕГРУЗКА ВЫВОДА***/
std::ostream& operator<<(std::ostream& out, 
    const Technical_book& T)
{
    for (int i = 0; i < 107; i++)
        cout << "-";
    cout << endl;
    out << dynamic_cast<const Scientific_book&>(T);
    out << left << setw(18)
        << T._application_area << "|" << endl;
    for (int i = 0; i < 107; i++)
        cout << "-";
    cout << endl;
    return out;
}

/***ПЕРЕГРУЗКА ВВОДА***/
std::istream& operator>>(std::istream& in, 
    Technical_book& T)
{
    cin >> dynamic_cast<Scientific_book&>(T);
    cout << "Введите область применения(на русском языке):" << endl;
    input_rus(in, T._application_area);

    return in;
}

/***ВЫВОД ТАБЛИЦЫ***/
void Technical_book::table()
{
    for (int i = 0; i < 107; i++)
        cout << "-";
    cout << endl;
    Scientific_book::table();
    cout << "Область применения|" << endl;
    for (int i = 0; i < 107; i++)
        cout << "-";
    cout << endl;
}

/*__________перегрузка вывода в бинарного файла__________*/
std::fstream& operator<<(std::fstream& out, Technical_book& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T), 
        sizeof(Technical_book));
    return out;
}

/*__________перегрузка чтения из бинарного файла__________*/
std::fstream& operator>>(std::fstream& is, Technical_book& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T), 
        sizeof(Technical_book));
    return is;
}

/***МЕНЮ СОРТИРОВКИ***/
int Technical_book::menu_sort()
{
    cout << "1 - сортировка по имени." << endl;
    cout << "2 - сортировка по фамилии." << endl;
    cout << "3 - сортировка по заголовку." << endl;
    cout << "4 - сортировка по количеству книг." << endl;
    cout << "5 - сортировка по количеству свободных книг." << endl;
    cout << "6 - сортировка по теме." << endl;
    cout << "7 - сортировка по области применения." << endl;
    return input_int(cin, 1, 7);
}

/***Создание нового объекта с выбранным полем***/
Technical_book Technical_book::copy_place(int choice)
{
    Technical_book obj;
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

        obj.set_application_area(_application_area);
        break;

    }
    return obj;
}

//меню изменения параметров
Queue<Technical_book> menu_correct(Queue<Technical_book> T, 
    int size, int pos)
{
    for (int choice = 1; choice;)
    {
        cout << "0 - выход." << endl;
        cout << "1 - изменить имя" << endl;
        cout << "2 - изменить фамилию." << endl;
        cout << "3 - изменить название." << endl;
        cout << "4 - изменить количество копий." << endl;
        cout << "5 - изменить тему." << endl;
        cout << "6 - изменить область применения." << endl;
        choice = input_int(cin, 0, 6);

        switch (choice)
        {
        case 1:

            system("CLS");
            cout << "Введите имя автора:" << endl;
            input_rus(cin, T[pos].get_name());
            system("cls");
            setColor(2);
            cout << "Имя изменено!" << endl;
            setColor(6);
            break;

        case 2:

            system("CLS");
            cout << "Введите фамилию автора:" << endl;
            input_rus(cin, T[pos].get_second_name());
            system("cls");
            setColor(2);
            cout << "Фамилия изменена!" << endl;
            setColor(6);
            break;

        case 3:

            system("CLS");
            cout << "Введите название книги:" << endl;
            input_rus(cin, T[pos].get_title());
            system("cls");
            setColor(2);
            cout << "Название изменено!" << endl;
            setColor(6);
            break;

        case 4:

            system("CLS");
            cout << "Введите количество копий:" << endl;
            T[pos].set_copies(input_int(cin, 1, 30));
            system("cls");
            setColor(2);
            cout << "Количество копий изменено!" << endl;
            setColor(6);
            break;

        case 5:

            system("CLS");
            cout << "Введите тему книги:" << endl;
            input_rus(cin, T[pos].get_topic());
            system("cls");
            setColor(2);
            cout << "Тема изменена!" << endl;
            setColor(6);
            break;

        case 6:

            system("CLS");
            cout << "Введите область применения:" << endl;
            input_rus(cin, T[pos].get_application_area());
            system("cls");
            setColor(2);
            cout << "Область применения изменена!" << endl;
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
Technical_book Technical_book::menu_for_poisk()
{
    Technical_book mas;

    for (int choice = 1; choice;)
    {
        setColor(5);
        cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
        cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
        setColor(2);
        cout << "______#####_____SEARCH___Technical_BOOK______#####_____" << endl;
        setColor(5);
        cout << "+++++++++++++++++++++++++^^^^++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++++^^^^^^^^^^+++++++++++++++++++++++" << endl;
        setColor(6);
        cout << ">> 1 - ввести имя.                                     " << endl;
        cout << ">> 2 - ввести фамилию.                                 " << endl;
        cout << ">> 3 - ввести название книги.                          " << endl;
        cout << ">> 4 - ввести количество копий.                        " << endl;
        cout << ">> 5 - ввести тему.                                    " << endl;
        cout << ">> 6 - ввести область применения.                      " << endl;
        setColor(2);
        cout << ">> 0 - начать поиск.                                   " << endl;
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
                cout << "Введите количество копий:" << endl;
                mas.set_copies(input_int(cin, 1, 99999));
                system("cls");
                setColor(2);
                cout << "Количество копий установлено!" << endl;
                setColor(6);
                break;

            case 5:

                system("cls");
                cout << "Введите тему книги(на русском языке):" << endl;
                input_rus(cin, mas.get_topic());
                system("cls");
                setColor(2);
                cout << "Тема установлена!" << endl;
                setColor(6);
                break;

            case 6:

                system("cls");
                cout << "Введите область применения(на русском языке):" << endl;
                input_rus(cin, mas.get_application_area());
                system("cls");
                setColor(2);
                cout << "Область применения установлена!" << endl;
                setColor(6);
                break;

            default:

                system("cls");
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