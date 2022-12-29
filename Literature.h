#pragma once
#include "Input_error.h"
#include "File_error.h"
#include "Container_error.h"
#include "standart.h"
#include "Algos.cpp"

/***йкюяя кхрепюрспш***/
class Literature
{
protected:

	int _id;                        //ЮИДХ  
	char _name[length_12];          //ХЛЪ ЮБРНПЮ
	char _second_name[length_12];   //ТЮЛХКХЪ ЮБРНПЮ
	char _title[length_12];         //МЮГБЮМХЕ

public:

	/***йнмярпсйрнп я/аег оюпюлерпнб***/
	Literature(int id = -1, const char* name = "", 
		const char* second_name = "",
		const char* title = "") :_id(id)
	{
		if (_id == -1)
			_id = rand() % (rand() % 10000);
		strcpy_s(this->_name, name);
		strcpy_s(this->_second_name, second_name);
		strcpy_s(this->_title, title);
	}

	/***деярпсйрнп***/
	virtual ~Literature() = 0;

	/***йнмярпсйрнп йнохпнбюмхъ***/
	Literature(const Literature& T)
	{
		this->_id = T._id;
		strcpy_s(this->_name, T._name);
		strcpy_s(this->_second_name, T._second_name);
		strcpy_s(this->_title, T._title);
	}

	/***оепецпсгйю ноепюрнпю япюбмемхъ***/
	bool operator>(const Literature& T);

	/***опнбепйю юидх***/
	bool check_id(int id);

	/***онксвемхе юидх ймхцх***/
	int& get_id();

	/***сярюмнбйю юидх ймхцх***/
	void set_id(int id);

	/***онксвемхе хлемх юбрнпю ймхцх***/
	char* get_name();

	/***сярюмнбйю хлемх юбрнпю ймхцх***/
	void set_name(const char* name);

	/***онксвемхе тюлхкхх юбрнпю ймхцх***/
	char* get_second_name();

	/***сярюмнбйю тюлхкхх юбрнпю ймхцх***/
	void set_second_name(const char* second_name);

	/***онксвемхе мюгбюмхъ ймхцх***/
	char* get_title();

	/***сярюмнбйю мюгбюмхъ ймхцх***/
	void set_title(const char* title);

	/***оепецпсгйю бшбндю***/
	friend std::ostream& operator<<(std::ostream& out, 
		const Literature& T);

	/***оепецпсгйю ббндю***/
	friend std::istream& operator>>(std::istream& in, 
		Literature& T);

	/***бшбнд рюакхжш***/
	virtual void table();
};