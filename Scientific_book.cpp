#include "Scientific_book.h"

/***деярпсйрнп***/
Scientific_book::~Scientific_book() {}

/***онксвемхе релш ймхцх***/
char* Scientific_book::get_topic()
{
    return &(_topic[0]);
}

/***сярюмнбйю релш ймхцх***/
void Scientific_book::set_topic(const char* topic)
{
    strcpy_s(_topic, topic);
}

/***оепецпсгйю бшбндю***/
std::ostream& operator<<(std::ostream& out, const Scientific_book& T)
{
    out << dynamic_cast<const Book&>(T);
    out << left << setw(12) << T._topic << "|";
    return out;
}

/***оепецпсгйю ббндю***/
std::istream& operator>>(std::istream& in, Scientific_book& T)
{
    cin >> dynamic_cast<Book&>(T);
    cout << "бБЕДХРЕ РЕЛС(МЮ ПСЯЯЙНЛ ЪГШЙЕ):" << endl;
    input_rus(in, T._topic);

    return in;
}

/***бшбнд рюакхжш***/
void Scientific_book::table()
{
    Book::table();
    cout << "рЕЛЮ        |";
}