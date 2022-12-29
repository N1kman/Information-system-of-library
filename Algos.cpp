#pragma once
#include "Algos.h"

/*__________метод поиска__________*/
template <class T>
typename Queue<T>::Iter Algos<T>::poisk(typename Queue<T>::Iter begin, 
	typename Queue<T>::Iter end, T buff)
{
	//*цикл по контейнеру Queue<T>*//
	for (; begin != end; ++begin)
	{
		if (*begin == buff)
			return begin;
	}
	return begin;
}

/*__________метод сортировки__________*/
template <class T>
void Algos<T>::sort(typename Queue<T>::Iter begin, 
	typename Queue<T>::Iter end, 
	bool (*func)(T& ob1, T& ob2), int choice)
{
	//*цикл по контейнеру Queue<T>*//
	for (; begin != end; ++begin)
	{
		//*вызов метода поиска минимального элемента*//
		typename Queue<T>::Iter buff = FindMin(begin, end, func, choice);
		//*перестановка объектов содержащихся в итераторах*//
		swap(buff, begin);
	}
}

/*__________метод поиска минимального элемента__________*/
template <class T>
typename Queue<T>::Iter Algos<T>::FindMin(typename Queue<T>::Iter begin,
	typename Queue<T>::Iter end, bool (*func)(T& ob1, T& ob2), int choice)
{
	typename Queue<T>::Iter buff = begin++;
	//*цикл по контейнеру Queue<T>*//
	for (; begin != end; ++begin)
	{
		T obj = (*begin).copy_place(choice);
		//*вызов лямбда выражения*//
		if (func(*buff, obj))
			buff = begin;
	}
	return buff;
}

/*__________метод перестановки__________*/
template <class T>
void Algos<T>::swap(typename Queue<T>::Iter iter1, 
	typename Queue<T>::Iter iter2)
{
	T swap = *iter1;
	*iter1 = *iter2;
	*iter2 = swap;
}
