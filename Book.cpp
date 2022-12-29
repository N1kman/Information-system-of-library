#include "Book.h"

/***ÄÅÑÒÐÓÊÒÎÐ***/
Book::~Book() {}

/***ÏÎËÓ×ÅÍÈÅ ÊÎËÈ×ÅÑÒÂÀ ÊÎÏÈÉ***/
int& Book::get_copies()
{
    return _copies;
}

/***ÓÑÒÀÍÎÂÊÀ ÊÎËÈ×ÅÑÒÂÀ ÊÎÏÈÈÉ***/
void Book::set_copies(int copies)
{
    _copies = copies;
}

/***ÏÎËÓ×ÅÍÈÅ ÊÎËÈ×ÅÑÒÂÀ ÊÎÏÈÉ ÄÎÑÒÓÏÍÕ ÊÍÈÃ***/
int& Book::get_no_active()
{
    return _no_active;
}

/***ÓÑÒÀÍÎÂÊÀ ÊÎËÈ×ÅÑÒÂÀ ÄÎÑÒÓÏÍÛÕ ÊÍÈÃ***/
void Book::set_no_active(int no_active)
{
    _no_active = no_active;
}

/***ÏÅÐÅÃÐÓÇÊÀ ÂÂÎÄÀ***/
std::istream& operator>>(std::istream& in, Book& T)
{
    in >> dynamic_cast<Literature&>(T);
    int buff;
    cout << "Ââåäèòå êîëè÷åñòâî êîïèé:" << endl;
    buff = input_int(in, 1, 30);
    T._copies = buff;
    T._no_active = buff;

    return in;
}

/***ÏÅÐÅÃÐÓÇÊÀ ÂÛÂÎÄÀ***/
std::ostream& operator<<(std::ostream& out, const Book& T)
{
    out << dynamic_cast<const Literature&>(T);
    out << left << setw(6) << T._copies << " |"
        << setw(9) << T._no_active << "|" << right;
    return out;
}

/***ÂÛÂÎÄ ÒÀÁËÈÖÛ***/
void Book::table()
{
    Literature::table();
    cout << "Êîïèé  |Äîñòóïíûõ|";
}
