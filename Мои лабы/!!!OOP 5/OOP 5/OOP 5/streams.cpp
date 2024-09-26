#include <iostream>
#include "methods.h"
using namespace std;

istream& operator >> (istream& in, person& obj)
{
	cin.clear();
	cout << "Name: "; getline(in, obj.name);	//!!!
	cout << "Age: "; in >> obj.age;
	return in;
}
ostream& operator << (ostream& out, person& obj)
{
	out << "Name: " << obj.name << '\n';
	out << "Age: " << obj.age << '\n';
	return out;
}

istream& operator >> (istream& in, student& obj)
{
	cin.clear();
	cin.ignore();
	cout << "Name: "; getline(in, obj.name);	//!!!
	cout << "Age: "; in >> obj.age;
	cout << "Subject: "; in >> obj.subject;
	cout << "Mark: "; in >> obj.mark;
	return in;
}
ostream& operator << (ostream& out, student& obj)
{
	out << "Name: " << obj.name << '\n';
	out << "Age: " << obj.age << '\n';
	out << "Subject: " << obj.subject << '\n';
	out << "Mark: " << obj.mark << '\n';
	return out;
}