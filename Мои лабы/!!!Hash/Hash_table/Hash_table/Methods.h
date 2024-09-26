#pragma once
#include <iostream>
#include <string>
using namespace std;

//Класс узел, будет содержаться в бакете
class node
{
private:
	char key;	
	int data;	
	node* nextPTR = nullptr;
public:
	node(char keyValue, int dataValue);
	~node();
	node* getNextPTR();
	char getKey();
	int getData();
	void setNextPTR(node* adress);
};
//Бакет(узел), имеет ключ, 
class bucket
{
public:
	int collision = 0;	//Кол-во коллизий (эл.в бакете)
private:
	node* head = nullptr;	//Указатель на 1 элемент бакета
public:
	bucket();
	~bucket();
	node* getHead();
	void setHead(node* adress);
	void print();
};
//В качестве хэш-таблицы будет выступать дин.массив указателей на бакеты
class hash_table
{
private:
	int hash;
	bucket** mas;
public:
	//Конструктор Деструктор
	hash_table(const int hashValue);	//Конструктор работает только, если задан размер хэш-таблицы!
	~hash_table();
	//Добавление эл. в хэш.таблицу
	void add(char keyValue, int dataValue);
	void print();
	void reCreate();
};
