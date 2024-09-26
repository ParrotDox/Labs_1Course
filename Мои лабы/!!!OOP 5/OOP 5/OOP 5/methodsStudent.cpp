#include <iostream>
#include "methods.h"
using namespace std;

student :: student() : person() 
{
	cout << "Base STUDENT constructor\n";
	this->subject = "No subject";
	this->mark = 0;
}
student :: student(string subject, int mark) : person()
{
	cout << "STUDENT constructor with 2 values\n";
	this->subject = subject;
	this->mark = mark;
}
student :: student(string subject, int mark, string name, int age) : person(name, age)
{
	cout << "STUDENT constructor with 4 values\n";
	this->subject = subject;
	this->mark = mark;
}
student :: student(student& obj) : person(obj)
{
	cout << "Copy STUDENT constructor\n";
	this->subject = obj.subject;
	this->mark = obj.mark;
}
student :: ~student() {};
void student :: getAll()
{
	person::getAll();
	cout << "Subject: " << this->subject << '\n';
	cout << "Mark: " << this->mark << '\n';
}
void student :: setSubject(string subject)
{
	this->subject = subject;
}
void student :: setMark(int mark)
{
	this->mark = mark;
}
void student :: setAll(string subject, int mark, string name, int age)
{
	person::setAll(name, age);
	this->subject = subject;
	this->mark = mark;
}
student& student :: operator = (student& obj)
{
	this->name = obj.name;
	this->age = obj.age;
	this->subject = obj.subject;
	this->mark = obj.mark;
	return *this;
}