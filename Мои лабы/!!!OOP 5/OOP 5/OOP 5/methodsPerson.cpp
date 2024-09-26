#include <iostream>
#include "methods.h"
using namespace std;

person :: person()
{
	cout << "Base PERSON constructor\n";
	this->name = "No Name";
	this->age = 0;
}
person :: person(string name, int age)
{
	cout << "PERSON constructor with values\n";
	this->name = name;
	this->age = age;
}
person :: person(person& obj)
{
	cout << "copy PERSON constructor\n";
	this->name = obj.name;
	this->age = obj.age;
}
person :: ~person() {};
void person :: getAll()
{
	cout << "Name: " << this->name << '\n';
	cout << "Age: " << this->age << '\n';
}
void person::setName(string name)
{
	this->name = name;
}
void person :: setAge(int age)
{
	this->age = age;
}
void person :: setAll(string name, int age)
{
	this->name = name;
	this->age = age;
}
person& person :: operator = (person& obj)
{
	this->name = obj.name;
	this->age = obj.age;
	return *this;
}