#pragma once
#include "standart.h"
#include "Book.h"

/***йкюяя мюсвмшу ймхц***/
class Scientific_book : public Book
{
protected:

	char _topic[length_12];     //РЕЛЮ

public:

	/***йнмярпсйрнп я/аег оюпюлерпнб***/
	Scientific_book(int id = -1, const char* name = "",
		const char* second_name = "",
		const char* title = "", int copies = -1,
		int no_active = -1, const char* topic = "") :
		Book(id, name, second_name, title, copies, no_active)
	{
		strcpy_s(_topic, topic);
	}

	/***деярпсйрнп***/
	virtual ~Scientific_book() = 0;

	/***йнмярпсйрнп йнохпнбюмхъ***/
	Scientific_book(const Scientific_book& T) :
		Book(dynamic_cast<const Book&>(T))
	{
		strcpy_s(_topic, T._topic);
	}

	/***онксвемхе релш ймхцх***/
	char* get_topic();

	/***сярюмнбйю релш ймхцх***/
	void set_topic(const char* topic);

	/***оепецпсгйю бшбндю***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Scientific_book& T);

	/***оепецпсгйю ббндю***/
	friend std::istream& operator>>(std::istream& in, 
		Scientific_book& T);

	/***бшбнд рюакхжш***/
	virtual void table();
};

