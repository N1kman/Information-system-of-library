#include "Active_Lit.h"

/***���������� ��������� �����***/
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

/***���������� ��������� ������������***/
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

/***��������� ���� ��������***/
date& Active_Lit::get_date_ret()
{
    return _ret;
}

/***��������� ���� ��������***/
void Active_Lit::set_date_ret(date ret)
{
    _ret = ret;
}

/***��������� ���� ���������***/
date& Active_Lit::get_date_issuance()
{
    return _issuance;
}

/***��������� ���� ���������***/
void Active_Lit::set_date_issuance(date issuance)
{
    _issuance = issuance;
}

/***��������� �������***/
int& Active_Lit::get_status()
{
    return _status;
}

/***��������� �������***/
void Active_Lit::set_status(int status)
{
    _status = status;
}

/***��������� ���� �����***/
int& Active_Lit::get_id_lit()
{
    return _id_lit;
}

/***��������� ���� �����***/
void Active_Lit::set_id_lit(int id_lit)
{
    _id_lit = id_lit;
}

/***��������� ���� ������������***/
int& Active_Lit::get_id_user()
{
    return _id_user;
}

/***��������� ���� ������������***/
void Active_Lit::set_id_user(int id_user)
{
    _id_user = id_user;
}

/***���������� ������***/
std::ostream& operator<<(std::ostream& out, const Active_Lit& T)
{
	cout << "-----------------------------------------"
		<< "------------------------------------------"
		<< endl;
    out << "|" << setw(12) << get_title_by_id(T._id_lit) << "|"
        << setw(14) << get_second_name_by_id(T._id_lit) << "|";

	out << setw(10) << T._id_lit << "|";

    if (T._status == 0)
        out << setw(14) << "��������";
    if (T._status == 1)
        out << setw(14) << "������������";
    if (T._status == 2)
        out << setw(14) << "��������";
    if (T._status == 3)
        out << setw(14) << "������";
    if (T._status == 4)
        out << setw(14) << "����������";

    out << " " << "|" << T._issuance
        << "  " << "|" << T._ret << "   |" 
        << endl << setfill(' ');
	cout << "-----------------------------------------"
		<< "------------------------------------------"
		<< endl;
    return out;
}

/***����� �������***/
void Active_Lit::table()
{
	cout << "-----------------------------------------------------------------------------------"
		<< endl;
	cout << "|��������    |������� ������|���� �����|������         |���� ������ |���� ��������|"
		<< endl;
	cout << "-----------------------------------------------------------------------------------"
		<< endl;
}

/*__________���������� ������ � ��������� �����__________*/
std::fstream& operator<<(std::fstream& out, Active_Lit& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T),
        sizeof(Active_Lit));
    return out;
}

/*__________���������� ������ �� ��������� �����__________*/
std::fstream& operator>>(std::fstream& is, Active_Lit& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T),
        sizeof(Active_Lit));
    return is;
}

/***�������� ����***/
bool Active_Lit::check_id(int id)
{
	if (_id_lit == id)return true;
	else return false;
}

/*__________��������� �������� �� ����__________*/
char* get_title_by_id(int ID)
{
	//��������� � ������������
	Queue<Audio> audio;

	//��������� � �������������� �����������
	Queue<Fiction_book> fiction_book;

	//��������� � ����������� �����������
	Queue<Technical_book> technical_book;

	//��������� � �������������� �����������
	Queue<Cognitive_book> cognitive_book;

	//*������ �� ������ ���� ����� ����*//
	audio.readQueueFromfile(file3);
	fiction_book.readQueueFromfile(file4);
	technical_book.readQueueFromfile(file5);
	cognitive_book.readQueueFromfile(file6);

	int flag = 0;                     //���� ��������� �����
	char* str = new char[length_12];  //����� ��� ��������

	//*�����*//
	for (int i = 0; i < audio.size() && !flag; i++)
	{
		if (audio[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, audio[i].get_title());
		}
	}

	//*�����*//
	for (int i = 0; i < fiction_book.size() && !flag; i++)
	{
		if (fiction_book[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, fiction_book[i].get_title());
		}
	}

	//*�����*//
	for (int i = 0; i < technical_book.size() && !flag; i++)
	{
		if (technical_book[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, technical_book[i].get_title());
		}
	}

	//*�����*//
	for (int i = 0; i < cognitive_book.size() && !flag; i++)
	{
		if (cognitive_book[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, cognitive_book[i].get_title());
		}
	}

	//*������ � ����� ���� ����� ����*//
	audio.writeQueueInfile(file3);
	fiction_book.writeQueueInfile(file4);
	technical_book.writeQueueInfile(file5);
	cognitive_book.writeQueueInfile(file6);

	return str;
}

/*__________��������� ������� �� ����__________*/
char* get_second_name_by_id(int ID)
{
	//��������� � ������������
	Queue<Audio> audio;

	//��������� � �������������� �����������
	Queue<Fiction_book> fiction_book;

	//��������� � ����������� �����������
	Queue<Technical_book> technical_book;

	//��������� � �������������� �����������
	Queue<Cognitive_book> cognitive_book;

	//*������ �� ������ ���� ����� ����*//
	audio.readQueueFromfile(file3);
	fiction_book.readQueueFromfile(file4);
	technical_book.readQueueFromfile(file5);
	cognitive_book.readQueueFromfile(file6);

	int flag = 0;                     //���� ��������� �����
	char* str = new char[length_12];  //����� ��� ��������

	//*�����*//
	for (int i = 0; i < audio.size() && !flag; i++)
	{
		if (audio[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, audio[i].get_second_name());
		}
	}

	//*�����*//
	for (int i = 0; i < fiction_book.size() && !flag; i++)
	{
		if (fiction_book[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, fiction_book[i].get_second_name());
		}
	}

	//*�����*//
	for (int i = 0; i < technical_book.size() && !flag; i++)
	{
		if (technical_book[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, technical_book[i].get_second_name());
		}
	}

	//*�����*//
	for (int i = 0; i < cognitive_book.size() && !flag; i++)
	{
		if (cognitive_book[i].get_id() == ID)
		{
			flag = 1;
			strcpy_s(str, length_12, cognitive_book[i].get_second_name());
		}
	}

	//*������ � ����� ���� ����� ����*//
	audio.writeQueueInfile(file3);
	fiction_book.writeQueueInfile(file4);
	technical_book.writeQueueInfile(file5);
	cognitive_book.writeQueueInfile(file6);

	return str;
}

/*__________��������� ���������� ��������� ����� �� ����__________*/
int get_no_active_lit(int ID)
{
	//��������� � ������������
	Queue<Audio> audio;

	//��������� � �������������� �����������
	Queue<Fiction_book> fiction_book;

	//��������� � ����������� �����������
	Queue<Technical_book> technical_book;

	//��������� � �������������� �����������
	Queue<Cognitive_book> cognitive_book;

	//*������ �� ������ ���� ����� ����*//
	audio.readQueueFromfile(file3);
	fiction_book.readQueueFromfile(file4);
	technical_book.readQueueFromfile(file5);
	cognitive_book.readQueueFromfile(file6);

	int* buff = new int(1); //����� ��� ���������� �����

	//*�����*//
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

	//*�����*//
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

	//*�����*//
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

	//*�����*//
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

	//*������ � ����� ���� ����� ����*//
	audio.writeQueueInfile(file3);
	fiction_book.writeQueueInfile(file4);
	technical_book.writeQueueInfile(file5);
	cognitive_book.writeQueueInfile(file6);

	return *buff;
}

/*__________����� ���������� ���������� �������� �����__________*/
void add_no_active_lit(int ID,int buff)
{
	//��������� � ������������
	Queue<Audio> audio;

	//��������� � �������������� �����������
	Queue<Fiction_book> fiction_book;

	//��������� � ����������� �����������
	Queue<Technical_book> technical_book;

	//��������� � �������������� �����������
	Queue<Cognitive_book> cognitive_book;

	//*������ �� ������ ���� ����� ����*//
	audio.readQueueFromfile(file3);
	fiction_book.readQueueFromfile(file4);
	technical_book.readQueueFromfile(file5);
	cognitive_book.readQueueFromfile(file6);

	int* buff1 = new int(1);

	//*����� � ���������� ��������*//
	for (int i = 0; i < audio.size(); i++)
	{
		if (audio[i].get_id() == ID)
		{
			*buff1 += buff;
		}
	}

	//*����� � ���������� ��������*//
	for (int i = 0; i < fiction_book.size(); i++)
	{
		if (fiction_book[i].get_id() == ID)
		{
			fiction_book[i].get_no_active() += buff;
		}
	}

	//*����� � ���������� ��������*//
	for (int i = 0; i < technical_book.size(); i++)
	{
		if (technical_book[i].get_id() == ID)
		{
			technical_book[i].get_no_active() += buff;
		}
	}

	//*����� � ���������� ��������*//
	for (int i = 0; i < cognitive_book.size(); i++)
	{
		if (cognitive_book[i].get_id() == ID)
		{
			cognitive_book[i].get_no_active() += buff;
		}
	}

	//*������ � ����� ���� ����� ����*//
	audio.writeQueueInfile(file3);
	fiction_book.writeQueueInfile(file4);
	technical_book.writeQueueInfile(file5);
	cognitive_book.writeQueueInfile(file6);
}