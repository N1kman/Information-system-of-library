#include "Fiction_book.h"

/***ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ***/
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

/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
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

/***ПЕРЕГРУЗКА ОПЕРАТОРА БОЛЬШЕ***/
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

/***ПЕРЕГРУЗКА ОПЕРАТОРА МЕНЬШЕ***/
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

/***ПОЛУЧЕНИЕ ТЕМЫ КНИГИ***/
char* Fiction_book::get_genre()
{
    return &(_genre[0]);
}

/***УСТАНОВКА ТЕМЫ КНИГИ***/
void Fiction_book::set_genre(const char* genre)
{
    strcpy_s(_genre, genre);
}

/***ПЕРЕГРУЗКА ВЫВОДА***/
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

/***ПЕРЕГРУЗКА ВВОДА***/
std::istream& operator>>(std::istream& in, Fiction_book& T)
{
    cin >> dynamic_cast<Book&>(T);
    cout << "Введите жанр(на русском языке):" << endl;
    input_rus(in, T._genre);
    return in;
}

/***ВЫВОД ТАБЛИЦЫ***/
void Fiction_book::table()
{
    for (int i = 0; i < 88; i++)
        cout << "-";
    cout << endl;
    Book::table();
    cout << "Жанр        |" << endl;
    for (int i = 0; i < 88; i++)
        cout << "-";
    cout << endl;
}

/*__________перегрузка вывода в бинарного файла__________*/
std::fstream& operator<<(std::fstream& out, Fiction_book& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T), 
        sizeof(Fiction_book));
    return out;
}

/*__________перегрузка чтения из бинарного файла__________*/
std::fstream& operator>>(std::fstream& is, Fiction_book& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T), 
        sizeof(Fiction_book));
    return is;
}

/***МЕНЮ СОРТИРОВКИ***/
int Fiction_book::menu_sort()
{
    cout << "1 - сортировка по имени." << endl;
    cout << "2 - сортировка по фамилии." << endl;
    cout << "3 - сортировка по заголовку." << endl;
    cout << "4 - сортировка по количеству книг." << endl;
    cout << "5 - сортировка по количеству свободных книг." << endl;
    cout << "6 - сортировка по жанру." << endl;
    return input_int(cin, 1, 6);
}

/***Создание нового объекта с выбранным полем***/
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

//меню изменения параметров
Queue<Fiction_book> menu_correct(Queue<Fiction_book> T,
    int size, int pos)
{
    for (int choice = 1; choice;)
    {
        cout << "0 - выход." << endl;
        cout << "1 - изменить имя" << endl;
        cout << "2 - изменить фамилию." << endl;
        cout << "3 - изменить название." << endl;
        cout << "4 - изменить количество копий." << endl;
        cout << "5 - изменить жанр." << endl;
        choice = input_int(cin, 0, 5);

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
            cout << "Введите количество копий:" << endl;
            T[pos].set_copies(input_int(cin, 1, 30));
            system("cls");
            setColor(2);
            cout << "Количество копий изменено!" << endl;
            setColor(6);
            break;

        case 5:

            system("CLS");
            cout << "Введите жанр книги(на русском языке):" << endl;
            input_rus(cin, T[pos].get_genre());
            system("cls");
            setColor(2);
            cout << "Жанр изменен!" << endl;
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
        cout << ">> 1 - ввести имя.                                     " << endl;
        cout << ">> 2 - ввести фамилию.                                 " << endl;
        cout << ">> 3 - ввести название книги.                          " << endl;
        cout << ">> 4 - ввести количество копий.                        " << endl;
        cout << ">> 5 - ввести жанр.                                    " << endl;
        setColor(2);
        cout << ">> 0 - начать поиск.                                   " << endl;
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
                cout << "Введите жанр книги(на русском языке):" << endl;
                input_rus(cin, mas.get_genre());
                system("cls");
                setColor(2);
                cout << "Жанр установлен!" << endl;
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