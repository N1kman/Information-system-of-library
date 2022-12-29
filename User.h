#pragma once
#include "Input_error.h"
#include "File_error.h"
#include "Container_error.h"
#include "standart.h"
#include "Algos.cpp"

/***йкюяя онкэгнбюрекъ***/
class User
{
protected:

	int _id;                          //ЮИДХ  
	char _password[password_length];  //ОЮПНКЭ
	char _name[length_12];            //ХЛЪ
	char _second_name[length_12];     //ТЮЛХКХЪ

public:

	/***йнмярпсйрнп я/аег оюпюлерпнб***/
	User(int id = -1, const char* password = "", 
		const char* name = "",
		const char* second_name = "") :_id(id)
	{
		if (_id == -1)_id = rand() % (rand() % 10000);
		strcpy_s(this->_password, password);
		strcpy_s(this->_name, name);
		strcpy_s(this->_second_name, second_name);
	}

	/***деярпсйрнп***/
	virtual  ~User() = 0;

	/***йнмярпсйрнп йнохпнбюмхъ***/
	User(const User& T)
	{
		_id = T._id;
		strcpy_s(_password, T._password);
		strcpy_s(_name, T._name);
		strcpy_s(_second_name, T._second_name);
	}

	/***оепецпсгйю ноепюрнпю япюбмемхъ***/
	bool operator>(const User& T);

	/***онксвемхе юидх онкэгнбюрекъ***/
	int& get_id();

	/***сярюмнбйю юидх онкэгнбюрекъ***/
	void set_id(int id);

	/***онксвемхе оюпнкъ онкэгнбюрекъ***/
	char* get_password();

	/***сярюмнбйю оюпнкъ онкэгнбюрекъ***/
	void set_password(const char* password);

	/***онксвемхе хлемх онкэгнбюрекъ***/
	char* get_name();

	/***сярюмнбйю хлемх онкэгнбюрекъ***/
	void set_name(const char* name);

	/***онксвемхе тюлхкхх онкэгнбюрекъ***/
	char* get_second_name();

	/***сярюмнбйю тюлхкхх онкэгнбюрекъ***/
	void set_second_name(const char* second_name);

	/***оепецпсгйю бшбндю***/
	friend std::ostream& operator<<(std::ostream& out, 
		const User& T);

	/***оепецпсгйю ббндю***/
	friend std::istream& operator>>(std::istream& in, 
		User& T);

	/*__________ОЕПЕЦПСГЙЮ БШБНДЮ Б АХМЮПМНЦН ТЮИКЮ__________*/
	friend std::fstream& operator<<(std::fstream& out, 
		User& T);

	/*__________ОЕПЕЦПСГЙЮ ВРЕМХЪ ХГ АХМЮПМНЦН ТЮИКЮ__________*/
	friend std::fstream& operator>>(std::fstream& is,
		User& T);

	/***бшбнд рюакхжш***/
	virtual void table();

	/***опнбепйю юидх***/
	bool check_id(int id);
};