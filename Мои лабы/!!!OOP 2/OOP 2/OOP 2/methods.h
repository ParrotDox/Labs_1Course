#pragma once
#include <iostream>
#include <string>
using namespace std;

class salary
{
private:
	string name;	//ФИО
	double salary_scale;	//Оклад
	int prize;	//Премия
public:
	salary();	//Конструктор по умолчанию
	salary(string n, double ss, int p);	//Конструктор при передаваемых значениях
	salary(const salary& obj);	//Конструктор копирования
	~salary();	//Деструктор
	void setAll();
	void setName();
	void setSalaryScale();
	void setPrize();
	void getAll();
	void getName();
	void getSalaryScale();
	void getPrize();
};