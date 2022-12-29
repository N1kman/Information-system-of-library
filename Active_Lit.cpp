#include "Active_Lit.h"

/***ПЕРЕГРУЗКА ОПЕРАТОРА РАВНО***/
bool Active_Lit::operator==(const Active_Lit& T)
{
    if (T._id_user != -1)
    {
        if (_id_user != T._id_user)
            return false;
    }

    if (T._id_lit != -1)
    {
        if (_id_lit != T._id_lit)
            return false;
    }

    if (T._status != -1)
    {
        if (_status != T._status)
            return false;
    }

    if (T._ret.day)
    {
        if (!(_ret == T._ret))
            return false;
    }

    if (T._issuance.day)
    {
        if (!(_issuance == T._issuance))
            return false;
    }

    return true;
}

/***ПЕРЕГРУЗКА ОПЕРАТОРА ПРИСВАИВАНИЯ***/
Active_Lit Active_Lit::operator=(const Active_Lit& T)
{
    if (this != &T)
    {
        _id_user = T._id_user;
        _id_lit = T._id_lit;
        _status = T._status;
        _issuance = T._issuance;
        _ret = T._ret;
    }
    return *this;
}

/***ПОЛУЧЕНИЕ ДАТЫ ВОЗВРАТА***/
date& Active_Lit::get_date_ret()
{
    return _ret;
}

/***УСТАНОВКА ДАТЫ ВОЗВРАТА***/
void Active_Lit::set_date_ret(date ret)
{
    _ret = ret;
}

/***ПОЛУЧЕНИЕ ДАТЫ ПОЛУЧЕНИЯ***/
date& Active_Lit::get_date_issuance()
{
    return _issuance;
}

/***УСТАНОВКА ДАТЫ ПОЛУЧЕНИЯ***/
void Active_Lit::set_date_issuance(date issuance)
{
    _issuance = issuance;
}

/***ПОЛУЧЕНИЕ СТАТУСА***/
int& Active_Lit::get_status()
{
    return _status;
}

/***УСТАНОВКА СТАТУСА***/
void Active_Lit::set_status(int status)
{
    _status = status;
}

/***ПОЛУЧЕНИЕ АЙДИ КНИГИ***/
int& Active_Lit::get_id_lit()
{
    return _id_lit;
}

/***УСТАНОВКА АЙДИ КНИГИ***/
void Active_Lit::set_id_lit(int id_lit)
{
    _id_lit = id_lit;
}

/***ПОЛУЧЕНИЕ АЙДИ ПОЛЬЗОВАТЕЛЯ***/
int& Active_Lit::get_id_user()
{
    return _id_user;
}

/***УСТАНОВКА АЙДИ ПОЛЬЗОВАТЕЛЯ***/
void Active_Lit::set_id_user(int id_user)
{
    _id_user = id_user;
}

/***ПЕРЕГРУЗКА ВЫВОДА***/
std::ostream& operator<<(std::ostream& out, const Active_Lit& T)
{
	cout << "-----------------------------------------"
		<< "------------------------------------------"
		<< endl;
    out << "|" << setw(12) << get_title_by_id(T._id_lit) << "|"
        << setw(14) << get_second_name_by_id(T._id_lit) << "|";

	out << setw(10) << T._id_lit << "|";

    if (T._status == 0)
        out << setw(14) << "Выдается";
    if (T._status == 1)
        out << setw(14) << "Возвращается";
    if (T._status == 2)
        out << setw(14) << "Отменено";
    if (T._status == 3)
        out << setw(14) << "Выдана";
    if (T._status == 4)
        out << setw(14) << "Возвращена";

    out << " " << "|" << T._issuance
        << "  " << "|" << T._ret << "   |" 
        << endl << setfill(' ');
	cout << "-----------------------------------------"
		<< "------------------------------------------"
		<< endl;
    return out;
}

/***ВЫВОД ТАБЛИЦЫ***/
void Active_Lit::table()
{
	cout << "-----------------------------------------------------------------------------------"
		<< endl;
	cout << "|Название    |Фамилия автора|Айди книги|Статус         |Дата взятия |Дата возврата|"
		<< endl;
	cout << "-----------------------------------------------------------------------------------"
		<< endl;
}

/*__________перегрузка вывода в бинарного файла__________*/
std::fstream& operator<<(std::fstream& out, Active_Lit& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T),
        sizeof(Active_Lit));
    return out;
}

/*__________перегрузка чтения из бинарного файла__________*/
std::fstream& operator>>(std::fstream& is, Active_Lit& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T),
        sizeof(Active_Lit));
    return is;
}

/***ПРОВЕРКА АЙДИ***/
bool Active_Lit::check_id(int id)
{
	if (_id_lit == id)return true;
	else return false;
}

/*__________получение названия по айди__________*/
char* get_title_by_id(int ID)
{
	//контейнер с айдиокнигами
	Queue<Audio> audio;

	//контейнер с художественной литературой
	Queue<Fiction_book> fiction_book;

	//контейнер с технической литературой
	Queue<Technical_book> technical_book;

	//контейнер с познавательной литературой
	Queue<Cognitive_book> cognitive_book;

	//*чтение из файлов всех типов книг*//
	audio.readQueueFromfile(file3);
	fiction_book.readQueueFromfile(file4);
	technical_book.readQueueFromfile(file5);
	cognitive_book.readQueueFromfile(file6);

	int flag = 0;                     //флаг найденной книги
	char* str = new char[length_12];  //буфер для названия

	//*ПОИСК*//
	for (int i = 0; i < audio.size() && !flag; i++)
	{
		if (audio[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, audio[i].get_title());
		}
	}

	//*ПОИСК*//
	for (int i = 0; i < fiction_book.size() && !flag; i++)
	{
		if (fiction_book[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, fiction_book[i].get_title());
		}
	}

	//*ПОИСК*//
	for (int i = 0; i < technical_book.size() && !flag; i++)
	{
		if (technical_book[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, technical_book[i].get_title());
		}
	}

	//*ПОИСК*//
	for (int i = 0; i < cognitive_book.size() && !flag; i++)
	{
		if (cognitive_book[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, cognitive_book[i].get_title());
		}
	}

	//*запись в файлы всех типов книг*//
	audio.writeQueueInfile(file3);
	fiction_book.writeQueueInfile(file4);
	technical_book.writeQueueInfile(file5);
	cognitive_book.writeQueueInfile(file6);

	return str;
}

/*__________получение фамилии по айди__________*/
char* get_second_name_by_id(int ID)
{
	//контейнер с айдиокнигами
	Queue<Audio> audio;

	//контейнер с художественной литературой
	Queue<Fiction_book> fiction_book;

	//контейнер с технической литературой
	Queue<Technical_book> technical_book;

	//контейнер с познавательной литературой
	Queue<Cognitive_book> cognitive_book;

	//*чтение из файлов всех типов книг*//
	audio.readQueueFromfile(file3);
	fiction_book.readQueueFromfile(file4);
	technical_book.readQueueFromfile(file5);
	cognitive_book.readQueueFromfile(file6);

	int flag = 0;                     //флаг найденной книги
	char* str = new char[length_12];  //буфер для названия

	//*ПОИСК*//
	for (int i = 0; i < audio.size() && !flag; i++)
	{
		if (audio[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, audio[i].get_second_name());
		}
	}

	//*ПОИСК*//
	for (int i = 0; i < fiction_book.size() && !flag; i++)
	{
		if (fiction_book[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, fiction_book[i].get_second_name());
		}
	}

	//*ПОИСК*//
	for (int i = 0; i < technical_book.size() && !flag; i++)
	{
		if (technical_book[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, technical_book[i].get_second_name());
		}
	}

	//*ПОИСК*//
	for (int i = 0; i < cognitive_book.size() && !flag; i++)
	{
		if (cognitive_book[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, cognitive_book[i].get_second_name());
		}
	}

	//*запись в файлы всех типов книг*//
	audio.writeQueueInfile(file3);
	fiction_book.writeQueueInfile(file4);
	technical_book.writeQueueInfile(file5);
	cognitive_book.writeQueueInfile(file6);

	return str;
}

/*__________получение количество свободных копий по айди__________*/
int get_no_active_lit(int ID)
{
	//контейнер с айдиокнигами
	Queue<Audio> audio;

	//контейнер с художественной литературой
	Queue<Fiction_book> fiction_book;

	//контейнер с технической литературой
	Queue<Technical_book> technical_book;

	//контейнер с познавательной литературой
	Queue<Cognitive_book> cognitive_book;

	//*чтение из файлов всех типов книг*//
	audio.readQueueFromfile(file3);
	fiction_book.readQueueFromfile(file4);
	technical_book.readQueueFromfile(file5);
	cognitive_book.readQueueFromfile(file6);

	int* buff = new int(1); //буфер для количества копий

	//*ПОИСК*//
	for (int i = 0; i < audio.size(); i++)
	{
		if (audio[i].get_id() == ID)
		{
			audio.writeQueueInfile(file3);
			fiction_book.writeQueueInfile(file4);
			technical_book.writeQueueInfile(file5);
			cognitive_book.writeQueueInfile(file6);
			return *buff;
		}
	}

	//*ПОИСК*//
	for (int i = 0; i < fiction_book.size(); i++)
	{
		if (fiction_book[i].get_id() == ID)
		{
			int abc = fiction_book[i].get_no_active();
			audio.writeQueueInfile(file3);
			fiction_book.writeQueueInfile(file4);
			technical_book.writeQueueInfile(file5);
			cognitive_book.writeQueueInfile(file6);
			return abc;
		}
	}

	//*ПОИСК*//
	for (int i = 0; i < technical_book.size(); i++)
	{
		if (technical_book[i].get_id() == ID)
		{
			int abc = technical_book[i].get_no_active();
			audio.writeQueueInfile(file3);
			fiction_book.writeQueueInfile(file4);
			technical_book.writeQueueInfile(file5);
			cognitive_book.writeQueueInfile(file6);
			return abc;
		}
	}

	//*ПОИСК*//
	for (int i = 0; i < cognitive_book.size(); i++)
	{
		if (cognitive_book[i].get_id() == ID)
		{
			int abc = cognitive_book[i].get_no_active();
			audio.writeQueueInfile(file3);
			fiction_book.writeQueueInfile(file4);
			technical_book.writeQueueInfile(file5);
			cognitive_book.writeQueueInfile(file6);
			return abc;
		}
	}

	//*запись в файлы всех типов книг*//
	audio.writeQueueInfile(file3);
	fiction_book.writeQueueInfile(file4);
	technical_book.writeQueueInfile(file5);
	cognitive_book.writeQueueInfile(file6);

	return *buff;
}

/*__________метод добавления количества активных копий__________*/
void add_no_active_lit(int ID,int buff)
{
	//контейнер с айдиокнигами
	Queue<Audio> audio;

	//контейнер с художественной литературой
	Queue<Fiction_book> fiction_book;

	//контейнер с технической литературой
	Queue<Technical_book> technical_book;

	//контейнер с познавательной литературой
	Queue<Cognitive_book> cognitive_book;

	//*чтение из файлов всех типов книг*//
	audio.readQueueFromfile(file3);
	fiction_book.readQueueFromfile(file4);
	technical_book.readQueueFromfile(file5);
	cognitive_book.readQueueFromfile(file6);

	int* buff1 = new int(1);

	//*ПОИСК И ДОБАВЛЕНИЕ ЗНАЧЕНИЯ*//
	for (int i = 0; i < audio.size(); i++)
	{
		if (audio[i].get_id() == ID)
		{
			*buff1 += buff;
		}
	}

	//*ПОИСК И ДОБАВЛЕНИЕ ЗНАЧЕНИЯ*//
	for (int i = 0; i < fiction_book.size(); i++)
	{
		if (fiction_book[i].get_id() == ID)
		{
			fiction_book[i].get_no_active() += buff;
		}
	}

	//*ПОИСК И ДОБАВЛЕНИЕ ЗНАЧЕНИЯ*//
	for (int i = 0; i < technical_book.size(); i++)
	{
		if (technical_book[i].get_id() == ID)
		{
			technical_book[i].get_no_active() += buff;
		}
	}

	//*ПОИСК И ДОБАВЛЕНИЕ ЗНАЧЕНИЯ*//
	for (int i = 0; i < cognitive_book.size(); i++)
	{
		if (cognitive_book[i].get_id() == ID)
		{
			cognitive_book[i].get_no_active() += buff;
		}
	}

	//*запись в файлы всех типов книг*//
	audio.writeQueueInfile(file3);
	fiction_book.writeQueueInfile(file4);
	technical_book.writeQueueInfile(file5);
	cognitive_book.writeQueueInfile(file6);
}