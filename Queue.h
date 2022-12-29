#include "Input_error.h"
#include "File_error.h"
#include "Container_error.h"
#include "Standart.h"
#include "Binary_file.cpp"

/*__________��������� ��� ������ �������__________*/
template <class T>
struct part_queue
{
	T _information{};                   //����������
	part_queue<T>* _last = nullptr;     //��������� �� ���������� �������
	part_queue<T>* _next = nullptr;     //����a���� �� ��������� �������
};

/*__________����� ��������������� �������__________*/
template <class T>
class Queue
{
private:

	size_t _size = 0;                    //���������� ��������� � �������
	part_queue<T>* _head = nullptr;      //��������� �� ������
	part_queue<T>* _tail = nullptr;      //����a���� �� �����

public:

	/*__________����� ���������__________*/
	class Iter
	{

	private:

		part_queue<T>* _current;
		part_queue<T>* _head;

	public:

		/*__________����������� � ����������__________*/
		Iter(part_queue<T>* current) :_current(current)
		{
			if (current)
				while (current->_last)current = current->_last;
			_head = current;
		}

		/*__________����������__________*/
		~Iter() {}

		/*__________�������������__________*/
		Iter operator++(int);

		/*__________���������__________*/
		Iter operator++();

		/*__________�������������__________*/
		Iter operator--(int);

		/*__________���������__________*/
		Iter operator--();

		/*__________���������������__________*/
		T& operator*();

		/*__________�������� �� �����__________*/
		bool operator!=(const Iter& it);

		/*__________�������� �� �����__________*/
		bool operator==(const Iter& it);

		/*__________�������� ��������__________*/
		Iter operator+(int col);

		/*__________�������� ���������__________*/
		Iter operator-(int col);

		/*__________�������� ��������__________*/
		void operator+=(int col);

		/*__________�������� ���������__________*/
		void operator-=(int col);

		/*__________�������� ��������� ����������__________*/
		int operator-(Iter& it);

	};

	Iter begin()
	{
		return _head;
	}

	Iter end()
	{
		return _tail->_next;
	}

	/*__________����������� � ����������__________*/
	Queue<T>(T info) :_size(1)
	{
		part_queue<T>* buff = new part_queue<T>; //��������� ������
		buff->_information = info;
		_head = _tail = buff;
		buff->_last = nullptr;        //��������� ��������� �� ���������� �������
		buff->_next = nullptr;        //��������� ��������� �� ��������� �������
	}

	/*__________����������� �� ���������__________*/
	Queue<T>() : _head(nullptr), _tail(nullptr), _size(0) {}

	/*__________����������__________*/
	~Queue<T>()
	{
		this->clear();
	}

	/*__________����������� �����������__________*/
	Queue<T>(const Queue<T>& buff)
	{
		part_queue<T>* point = buff._head;
		for (size_t i = 0; i < buff._size; ++i, point = point->_next)
			this->push_back(point->_information);
	}

	/*__________���������� ��������� ������������__________*/
	Queue<T> operator=(const Queue<T>&);

	/*__________���������� ��������� []__________*/
	T& operator[](size_t pos);          

	/*__________������� ���a������ �������� �������(� ������)__________*/
	void push_front(T information);	    

	/*__________������� ���a������ �������� �������(� �����)__________*/
	void push_back(T information);      

	/*__________������� �������� � ������__________*/
	void pop_front();               	

	/*__________������� �������� � ������__________*/
	void pop_back();                    

	/*__________������� �������� � ������ c ���������__________*/
	T pop_back_ret();	                

	/*__________������� ���a������ �������� �� �������__________*/
	void push_any(T, size_t);           

	/*__________������� �������� �������� �� �������__________*/
	void pop_any(size_t);               

	/*__________������ ������� �������__________*/
	void clear();	                    

	/*__________��������� ���������� ��������� � �������__________*/
	int size();	                        

	/*__________�������� ����� �� �������__________*/
	bool empty();	                    

	/*__________��������� ������� ���������� ������� � �������__________*/
	T get_example_zero();               

	/*__________�����__________*/
	void show(size_t choice);           

	/*__________������� �������� ���������� ����__________*/
	bool find_id(int id);

	/*__________��������� ������� �� ����__________*/
	int get_pos_by_id(int id);

	/*__________����� ������ ������� � ����__________*/
	void writeQueueInfile(const char* name);

	/*__________����� ������ ������� �� �����__________*/
	void readQueueFromfile(const char* name);
};

