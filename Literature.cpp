#include "Literature.h"

/***ÄÅÑÒĞÓÊÒÎĞ***/
Literature::~Literature() {}

/***ÏĞÎÂÅĞÊÀ ÀÉÄÈ***/
bool Literature::check_id(int id)
{
    if (_id == id)return true;
    else return false;
}

/***ÏÎËÓ×ÅÍÈÅ ÀÉÄÈ ÊÍÈÃÈ***/
int& Literature::get_id()
{
    return _id;
}

/***ÓÑÒÀÍÎÂÊÀ ÀÉÄÈ ÊÍÈÃÈ***/
void Literature::set_id(int id)
{
    _id = id;
}

/***ÏÎËÓ×ÅÍÈÅ ÈÌÅÍÈ ÀÂÒÎĞÀ ÊÍÈÃÈ***/
char* Literature::get_name()
{
    return &(_name[0]);
}

/***ÓÑÒÀÍÎÂÊÀ ÈÌÅÍÈ ÀÂÒÎĞÀ ÊÍÈÃÈ***/
void Literature::set_name(const char* name)
{
    strcpy_s(_name, name);
}

/***ÏÎËÓ×ÅÍÈÅ ÔÀÌÈËÈÈ ÀÂÒÎĞÀ ÊÍÈÃÈ***/
char* Literature::get_second_name()
{
    return &(_second_name[0]);
}

/***ÓÑÒÀÍÎÂÊÀ ÔÀÌÈËÈÈ ÀÂÒÎĞÀ ÊÍÈÃÈ***/
void Literature::set_second_name(const char* second_name)
{
    strcpy_s(_second_name, second_name);
}

/***ÏÎËÓ×ÅÍÈÅ ÍÀÇÂÀÍÈß ÊÍÈÃÈ***/
char* Literature::get_title()
{
    return &(_title[0]);
}

/***ÓÑÒÀÍÎÂÊÀ ÍÀÇÂÀÍÈß ÊÍÈÃÈ***/
void Literature::set_title(const char* title)
{
    strcpy_s(_title, title);
}

/***ÏÅĞÅÃĞÓÇÊÀ ÎÏÅĞÀÒÎĞÀ ÑĞÀÂÍÅÍÈß***/
bool Literature::operator>(const Literature& T)
{
    if (strcmp(_second_name, T._second_name) <= 0)
        return false;
    return true;
}

/***ÏÅĞÅÃĞÓÇÊÀ ÂÛÂÎÄÀ***/
std::ostream& operator<<(std::ostream& out, const Literature& T)
{
    out << "|" << setw(10) << left << T._id 
        << "  " << "|" << setw(12)
        << T._title << " " << "|" << setw(12) << T._name
        << " " << "|" << setw(12) 
        << T._second_name << "  |" << right;
    return out;
}

/***ÏÅĞÅÃĞÓÇÊÀ ÂÂÎÄÀ***/
std::istream& operator>>(std::istream& in, Literature& T)
{
    cout << "Ââåäèòå èìÿ àâòîğà(íà ğóññêîì ÿçûêå):" << endl;
    input_rus(in, T._name);
    cout << "Ââåäèòå ôàìèëèş àâòîğà(íà ğóññêîì ÿçûêå):" << endl;
    input_rus(in, T._second_name);
    cout << "Ââåäèòå çàãîëîâîê(íà ğóññêîì ÿçûêå):" << endl;
    input_rus(in, T._title);

    return in;
}

/***ÂÛÂÎÄ ÒÀÁËÈÖÛ***/
void Literature::table()
{
    cout << "|Àéäè(êíèãè) |Çàãîëîâîê    |Èìÿ àâòîğà   |Ôàìèëèÿ àâòîğà|";
}