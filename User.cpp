#include "User.h"

/***ÏÅĞÅÃĞÓÇÊÀ ÎÏÅĞÀÒÎĞÀ ÑĞÀÂÍÅÍÈß***/
bool User::operator>(const User& T)
{
    if (strcmp(_second_name, T._second_name) <= 0)
        return false;
    return true;
}

/***ÄÅÑÒĞÓÊÒÎĞ***/
User::~User() {}

/***ÏÎËÓ×ÅÍÈÅ ÀÉÄÈ ÏÎËÜÇÎÂÀÒÅËß***/
int& User::get_id()
{
    return _id;
}

/***ÓÑÒÀÍÎÂÊÀ ÀÉÄÈ ÏÎËÜÇÎÂÀÒÅËß***/
void User::set_id(int id)
{
    _id = id;
}

/***ÏÎËÓ×ÅÍÈÅ ÏÀĞÎËß ÏÎËÜÇÎÂÀÒÅËß***/
char* User::get_password()
{
    return &(_password[0]);
}

/***ÓÑÒÀÍÎÂÊÀ ÏÀĞÎËß ÏÎËÜÇÎÂÀÒÅËß***/
void User::set_password(const char* password)
{
    strcpy_s(_password, password);
}

/***ÏÎËÓ×ÅÍÈÅ ÈÌÅÍÈ ÏÎËÜÇÎÂÀÒÅËß***/
char* User::get_name()
{
    return &(_name[0]);
}

/***ÓÑÒÀÍÎÂÊÀ ÈÌÅÍÈ ÏÎËÜÇÎÂÀÒÅËß***/
void User::set_name(const char* name)
{
    strcpy_s(_name, name);
}

/***ÏÎËÓ×ÅÍÈÅ ÔÀÌÈËÈÈ ÏÎËÜÇÎÂÀÒÅËß***/
char* User::get_second_name()
{
    return &(_second_name[0]);
}

/***ÓÑÒÀÍÎÂÊÀ ÔÀÌÈËÈÈ ÏÎËÜÇÎÂÀÒÅËß***/
void User::set_second_name(const char* second_name)
{
    strcpy_s(_second_name, second_name);
}

/***ÏÅĞÅÃĞÓÇÊÀ ÂÛÂÎÄÀ***/
std::ostream& operator<<(std::ostream& out, const User& T)
{
    out << "|" << setw(10) << left << T._id << " " << "|" << setw(8)
        << T._password << " " << "|" << setw(12) << T._name
        << " " << "|" << setw(12) << T._second_name << " " << "|" << right;
    return out;
}

/***ÏÅĞÅÃĞÓÇÊÀ ÂÂÎÄÀ***/
std::istream& operator>>(std::istream& in, User& T)
{
    cout << "Ââåäèòå èìÿ:(íà ğóññêîì ÿçûêå)" << endl;
    input_rus(in, T._name);
    cout << "Ââåäèòå ôàìèëèş(íà ğóññêîì ÿçûêå):" << endl;
    input_rus(in, T._second_name);
    cout << "Ââåäèòå ïàğîëü(8 ñèìâîëîâ):" << endl;
    input_password(in, T._password);

    return in;
}

/***ÂÛÂÎÄ ÒÀÁËÈÖÛ***/
void User::table()
{
    cout << "|Àéäè(÷èò.) |Ïàğîëü   |Èìÿ          |Ôàìèëèÿ      |";
}

/*__________ïåğåãğóçêà âûâîäà â áèíàğíîãî ôàéëà__________*/
std::fstream& operator<<(std::fstream& out, User& T)
{
    static_cast<fstream&>(out).write(reinterpret_cast<const char*>(&T),
        sizeof(User));
    return out;
}

/*__________ïåğåãğóçêà ÷òåíèÿ èç áèíàğíîãî ôàéëà__________*/
std::fstream& operator>>(std::fstream& is, User& T)
{
    static_cast<fstream&>(is).read(reinterpret_cast<char*>(&T), 
        sizeof(User));
    return is;
}

/***ÏĞÎÂÅĞÊÀ ÀÉÄÈ***/
bool User::check_id(int id)
{
    if (_id == id)return true;
    else return false;
}
