#pragma once
#include <iostream>
using namespace std;

class iter
{
	friend class list;
public:
	iter();
	void operator = (int*);
	void operator ++ ();	//Движение вперед на 1 ячейку
	void operator + (int n);
	void operator -- ();	//Движение назад на 1 ячейку
	int& operator * ();
	int get_elem();	//Получение ячейки итератора
	~iter();
private:
	int* elem;	//Указатель на эл.списка
};

class list
{
	friend class iter;
private:
	int size;
	int* data;
	int* beg;
	int* end;
public:
	//Конструкторы деструкторы
	list(int s);
	list(int s, int d);
	list(list& obj);
	~list();
	//Кастомные функции
	int* first();
	int* last();
	//Перегрузка
	list& operator = (list& obj);
	int& operator [] (int i);
	list& operator + (int k);
	list& operator * (list& obj);
	int operator () ();
	//Перегрузка потоков
	friend istream& operator >> (istream& in, list& obj);
	friend ostream& operator << (ostream& out, list& obj);
};