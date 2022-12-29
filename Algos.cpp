#pragma once
#include "Algos.h"

/*__________����� ������__________*/
template <class T>
typename Queue<T>::Iter Algos<T>::poisk(typename Queue<T>::Iter begin, 
	typename Queue<T>::Iter end, T buff)
{
	//*���� �� ���������� Queue<T>*//
	for (; begin != end; ++begin)
	{
		if (*begin == buff)
			return begin;
	}
	return begin;
}

/*__________����� ����������__________*/
template <class T>
void Algos<T>::sort(typename Queue<T>::Iter begin, 
	typename Queue<T>::Iter end, 
	bool (*func)(T& ob1, T& ob2), int choice)
{
	//*���� �� ���������� Queue<T>*//
	for (; begin != end; ++begin)
	{
		//*����� ������ ������ ������������ ��������*//
		typename Queue<T>::Iter buff = FindMin(begin, end, func, choice);
		//*������������ �������� ������������ � ����������*//
		swap(buff, begin);
	}
}

/*__________����� ������ ������������ ��������__________*/
template <class T>
typename Queue<T>::Iter Algos<T>::FindMin(typename Queue<T>::Iter begin,
	typename Queue<T>::Iter end, bool (*func)(T& ob1, T& ob2), int choice)
{
	typename Queue<T>::Iter buff = begin++;
	//*���� �� ���������� Queue<T>*//
	for (; begin != end; ++begin)
	{
		T obj = (*begin).copy_place(choice);
		//*����� ������ ���������*//
		if (func(*buff, obj))
			buff = begin;
	}
	return buff;
}

/*__________����� ������������__________*/
template <class T>
void Algos<T>::swap(typename Queue<T>::Iter iter1, 
	typename Queue<T>::Iter iter2)
{
	T swap = *iter1;
	*iter1 = *iter2;
	*iter2 = swap;
}
