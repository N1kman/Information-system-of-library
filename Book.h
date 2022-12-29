#pragma once
#include "standart.h"
#include "Literature.h"

/***йкюяя ймхцх***/
class Book : public Literature
{
protected:

	int _copies;       //ЙНКХВЕЯРБН ЩЙГЕЛОКЪПНБ
	int _no_active;    //ЙНКХВЕЯРБН ЯБНАНДМШУ ЩЙГЕЛОКЪПНБ

public:

	/***йнмярпсйрнп я/аег оюпюлерпнб***/
	Book(int id = -1, const char* name = "",
		const char* second_name = "",
		const char* title = "", int copies = -1,
		int no_active = -1) :
		Literature(id, name, second_name, title)
	{
		_copies = copies;
		_no_active = no_active;
	}

	/***деярпсйрнп***/
	virtual ~Book() = 0;

	/***йнмярпсйрнп йнохпнбюмхъ***/
	Book(const Book& T):
		Literature(dynamic_cast<const Literature&>(T))
	{
		_copies = T._copies;
		_no_active = T._no_active;
	}

	/***онксвемхе йнкхвеярбю йнохи***/
	int& get_copies();

	/***сярюмнбйю йнкхвеярбю йноххи***/
	void set_copies(int copies);

	/***онксвемхе йнкхвеярбю йнохи днярсому ймхц***/
	int& get_no_active();

	/***сярюмнбйю йнкхвеярбю днярсомшу ймхц***/
	void set_no_active(int no_active);

	/***оепецпсгйю ббндю***/
	friend std::istream& operator>>(std::istream& in, Book& T);

	/***оепецпсгйю бшбндю***/
	friend std::ostream& operator<<(std::ostream& out, const Book& T);

	/***бшбнд рюакхжш***/
	virtual void table();

};

