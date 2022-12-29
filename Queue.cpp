#pragma once
#include "Queue.h"

/*__________������� ���a������ �������� �������(� �����)__________*/
template <class T>
void Queue<T>::push_back(T information)
{
	part_queue<T>* buff = new part_queue<T>; //��������� ������
	buff->_information = information;
	_size++;

	if (!_head or !_tail)
	{
		_head = _tail = buff;
		buff->_last = nullptr;           //��������� ��������� �� ���������� �������
		buff->_next = nullptr;           //��������� ��������� �� ��������� �������
	}
	else
	{
		buff->_next = nullptr;            //��������� ��������� �� ��������� �������
		buff->_last = _tail;              //�������� �� ���������� �������
		_tail->_next = buff;              //�������� �� ���������
		_tail = buff;                     //����� �����
	}
}

/*__________������� ���a������ �������� �������(� ������)__________*/
template <class T>
void Queue<T>::push_front(T information)
{
	part_queue<T>* buff = new part_queue<T>; //��������� ������
	buff->_information = information;
	_size++;

	if (!_head or !_tail)
	{
		_head = _tail = buff;
		buff->_last = nullptr;           //��������� ��������� �� ���������� �������
		buff->_next = nullptr;           //��������� ��������� �� ��������� �������
	}
	else
	{
		buff->_next = _head;              //��������� �� ���������
		buff->_last = nullptr;            //��������� ��������� �� ���������� �������
		_head->_last = buff;              //�������� �� ���������
		_head = buff;                     //����� �����
	}
}

/*__________������� �������� � ������__________*/
template <class T>
void Queue<T>::pop_back()
{
	try
	{
		if (!_head or !_tail)
		{
			throw Container_error(6, "������� �����", 
				"�������� �������� ��������� ������ ��������");
		}
		else
		{
			_size--;
			if (_tail->_last == nullptr)
			{
				delete _tail;               //�������
				_tail = _head = nullptr;    //���������
			}
			else
			{
				part_queue<T>* buff = _tail;
				_tail = _tail->_last;       //����� �����
				_tail->_next = nullptr;     //���������
				delete buff;                //�������
			}
		}
	}
	catch (Container_error obj)
	{
		obj.show_e();
	}
}

/*__________������� �������� � ������ c ���������__________*/
template <class T>
T Queue<T>::pop_back_ret()
{
	T ret;
	try
	{
		if (!_head or !_tail)
		{
			throw Container_error(6, "������� �����", 
				"�������� �������� ��������� ������ ��������");
		}
		else
		{
			_size--;
			if (_tail->_last == nullptr)
			{
				ret = _tail->_information;
				delete _tail;               //�������
				_tail = _head = nullptr;    //���������
			}
			else
			{
				part_queue<T>* buff = _tail;
				_tail = _tail->_last;       //����� �����
				_tail->_next = nullptr;     //���������
				ret = buff->_information;
				delete buff;                //�������
			}
		}
	}
	catch (Container_error obj)
	{
		obj.show_e();
	}

	return ret;
}

/*__________������� �������� � ������__________*/
template <class T>
void Queue<T>::pop_front()
{
	try
	{
		if (!_head or !_tail)
		{
			throw Container_error(6, "������� �����", 
				"�������� �������� ��������� ������ ��������");
		}
		else
		{
			_size--;
			if (_tail->_last == nullptr)
			{
				delete _tail;               //�������
				_tail = _head = nullptr;    //���������
			}
			else
			{
				part_queue<T>* buff = _head;
				_head = _head->_next;       //����� ������
				_head->_last = nullptr;     //���������
				delete buff;                //�������
			}
		}
	}
	catch (Container_error obj)
	{
		obj.show_e();
	}
}

/*__________������ ������� �������__________*/
template <class T>
void Queue<T>::clear()
{
	while (_head or _tail)this->pop_back();
}

/*__________�����__________*/
template <class T>
void Queue<T>::show(size_t choice)
{
	try
	{
		if (!_head or !_tail)
		{
			throw Container_error(6, "������� �����", 
				"�������� �������� ��������� ������ ��������");
		}
		else
		{
			part_queue<T>* point;
			if (!choice)point = _head;                        //����������� �� ������
			else point = _tail;                               //����������� �� ������
			do
			{
				cout << point->_information;
				if (!choice)point = point->_next;              //����������� �� ������
				else point = point->_last;                     //����������� �� ������
			} while (point);
		}
	}
	catch (Container_error obj)
	{
		obj.show_e();
	}
}

/*__________��������� ���������� ��������� � �������__________*/
template <class T>
int Queue<T>::size()
{
	return _size;
}

/*__________��������� ������� �� ����__________*/
template <class T>
int Queue<T>::get_pos_by_id(int id)
{
	int i = 0;
	for (part_queue<T>* point = _head; point; point = point->_next)
	{
		if (point->_information.check_id(id))
			return i;
			i++;
	}
	return -1;
}

/*__________��������� ������� ���������� ������� � �������__________*/
template <class T>
T Queue<T>::get_example_zero()
{
	T obj{};
	return obj;
}

/*__________���������� ��������� []__________*/
template <class T>
T& Queue<T>::operator[](size_t pos)
{
	try
	{
		if (pos >= _size or pos < 0)
			throw Container_error(7, "����� �� ������� ����������", 
				"�������� �� ������ ������� ������ �������(��������� ������ ������)");
		part_queue<T>* point = _head;
		while (pos and point->_next)
		{
			point = point->_next;
			pos--;
		}
		return point->_information;
	}
	catch (Container_error obj)
	{
		obj.show_e();
		T* ret = new T;
		return *ret;
	}
}

/*__________���������� ��������� ������������__________*/
template <class T>
Queue<T> Queue<T>::operator=(const Queue<T>& buff)
{
	if (this != &buff)
	{
		this->clear();
		part_queue<T>* point = buff._head;
		for (size_t i = 0; i < buff._size; ++i, point = point->_next)
			this->push_back(point->_information);
	}
	return *this;
}

/*__________������� �������� ���������� ����__________*/
template <class T>
bool Queue<T>::find_id(int id)
{
	part_queue<T>* point = _head;
	for (size_t i = 0; i < _size; ++i, point = point->_next)
	{
		if (point->_information.check_id(id))
			return true;
	}
	return false;
}

/*__________�������� ����� �� �������__________*/
template <class T>
bool Queue<T>::empty()
{
	if (_size)
		return false;
	else 
		return true;
}

/*__________������� ���a������ �������� �� �������__________*/
template <class T>
void Queue<T>::push_any(T information, size_t index)
{
	try
	{
		if (index > _size or index < 0)
			throw Container_error(7, "����� �� ������� ����������", 
			"�������� �� ������ ������� ������ �������");
		else
		{
			if (!_size or _size == index)
			{
				this->push_back(information);
			}
			else
				if (index == 0)
				{
					this->push_front(information);
				}
				else
				{
					part_queue<T>* buff = new part_queue<T>; //��������� ������
					buff->_information = information;
					_size++;
					part_queue<T>* point = _head;
					while (index--)point = point->_next;
					point->_last->_next = buff;
					buff->_last = point->_last;
					buff->_next = point;
					point->_last = buff;
				}
		}
	}
	catch (Container_error obj)
	{
		obj.show_e();
	}
}

/*__________������� �������� �������� �� �������__________*/
template <class T>
void Queue<T>::pop_any(size_t index)
{
	try
	{
		if (index >= _size or index < 0)
			throw Container_error(7, "����� �� ������� ����������", 
				"�������� �� ������ ������� ������ �������");
		else
		{
			if (!_size)
			{
				throw Container_error(6, "������� �����", 
					"�������� �������� ��������� ������ ��������");
			}
			else
				if (_size - 1 == index)
				{
					this->pop_back();
				}
				else
					if (index == 0)
					{
						this->pop_front();
					}
					else
					{
						_size--;
						part_queue<T>* point = _head;
						while (index--)point = point->_next;
						point->_last->_next = point->_next;
						point->_next->_last = point->_last;
						delete point;
					}
		}
	}
	catch (Container_error obj)
	{
		obj.show_e();
	}
}

/*__________����� ������ ������� �� �����__________*/
template <class T>
void Queue<T>::readQueueFromfile(const char* name)
{
	Binary_file<T> fil1(name);
	T read;
	this->clear();
	fil1.OpenFileIn();
	fil1.remote();
	while (1)
	{
		fil1.ReadFromFile(read);
		if (fil1.isEndFile())break;
		this->push_front(read);
	}
	fil1.CloseFile();
}

/*__________����� ������ ������� � ����__________*/
template <class T>
void Queue<T>::writeQueueInfile(const char* name)
{
	Binary_file<T> fil1(name);
	T read;
	fil1.OpenFileOut();
	fil1.remote();
	while (!this->empty())
	{
		read = this->pop_back_ret();
		fil1.WriteInFile(read);
	}
	fil1.CloseFile();
}

/*__________������������� __________*/
template <typename T>
typename Queue<T>::Iter Queue<T>::Iter::operator++(int)
{
	part_queue<T>* buff = _current;
	if (!_current)
	{
		_current = _head;
		return nullptr;
	}
	else
	{
		_current = _current->_next;
		return buff;
	}
}

/*__________��������� __________*/
template <typename T>
typename Queue<T>::Iter Queue<T>::Iter::operator++()
{
	if (!_current)
	{
		_current = _head;
		return _current;
	}
	else
	{
		_current = _current->_next;
		return _current;
	}
}

/*__________������������� __________*/
template <typename T>
typename Queue<T>::Iter Queue<T>::Iter::operator--(int)
{
	part_queue<T>* buff = _current;
	if (!(_current->_last))
	{
		while (_current->_next)_current = _current->_next;
		return _head;
	}
	else
	{
		_current = _current->_last;
		return buff;
	}
}

/*__________��������� __________*/
template <typename T>
typename Queue<T>::Iter Queue<T>::Iter::operator--()
{
	if (!(_current->_last))
	{
		while (_current->_next)_current = _current->_next;
		return _current;
	}
	else
	{
		_current = _current->_last;
		return _current;
	}
}

/*__________���������������__________*/
template <typename T>
T& Queue<T>::Iter::operator*()
{
	if (!_current)
		return _head->_information;
	else
		return _current->_information;
}

/*__________�������� �� �����__________*/
template <typename T>
bool Queue<T>::Iter::operator!=(const typename Queue<T>::Iter& it)
{
	if (this->_current != it._current)
		return true;
	else
		return false;
}

/*__________�������� �� �����__________*/
template <typename T>
bool Queue<T>::Iter::operator==(const typename Queue<T>::Iter& it)
{
	if (this->_current != it._current)
		return false;
	else
		return true;
}

/*__________�������� ��������__________*/
template <typename T>
typename Queue<T>::Iter Queue<T>::Iter::operator+(int col)
{
	for (int i = 0; i < col; ++i)
	{
		if (!_current)
			_current = _head;
		else
			_current = _current->_next;
	}
	return _current;
}

/*__________�������� ���������__________*/
template <typename T>
typename Queue<T>::Iter Queue<T>::Iter::operator-(int col)
{
	for (int i = 0; i < col; ++i)
	{
		if (!(_current->_last))
			while (_current->_next)_current = _current->_next;
		else
			_current = _current->_last;
	}
	return _current;
}

/*__________�������� ��������__________*/
template <typename T>
void Queue<T>::Iter::operator+=(int col)
{
	for (int i = 0; i < col; ++i)
	{
		if (!_current)
			_current = _head;
		else
			_current = _current->_next;
	}
}

/*__________�������� ���������__________*/
template <typename T>
void Queue<T>::Iter::operator-=(int col)
{
	for (int i = 0; i < col; ++i)
	{
		if (!(_current->_last))
			while (_current->_next)_current = _current->_next;
		else
			_current = _current->_last;
	}
}

/*__________�������� ��������� ����������__________*/
template <typename T>
int Queue<T>::Iter::operator-(typename Queue<T>::Iter& it)
{
	//���������� ������� ����� �����������
	int pos = 0;
	part_queue<T>* buff = _current;
	if (_current == it._current)
		return pos;
	else
	{
		//������ �� ������� ������� �� �������
		while (buff)
		{
			if (buff == it._current)
				return pos;
			buff = buff->_next;
			pos++;
		};
		pos = 0;
		buff = it._current;
		//������ �� ������� ������� �� �������
		while (buff)
		{
			if (buff == _current)
				return pos;
			buff = buff->_next;
			pos++;
		};
		return -1;
	}
}