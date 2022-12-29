#pragma once
#include "Queue.cpp"

/*__________����� ���������__________*/
template <class T>
class Algos
{
public:

	/*__________����� ������__________*/
	typename Queue<T>::Iter poisk(typename Queue<T>::Iter,
		typename Queue<T>::Iter, T);

	/*__________����� ����������__________*/
	void sort(typename Queue<T>::Iter begin, 
		typename Queue<T>::Iter end, 
		bool (*func)(T& ob1, T& ob2), int);

	/*__________����� ������ ������������ ��������__________*/
	typename Queue<T>::Iter FindMin(typename Queue<T>::Iter begin, 
		typename Queue<T>::Iter end, 
		bool (*func)(T& ob1, T& ob2), int);

	/*__________����� ������������__________*/
	void swap(typename Queue<T>::Iter iter1, 
		typename Queue<T>::Iter iter2);
};

