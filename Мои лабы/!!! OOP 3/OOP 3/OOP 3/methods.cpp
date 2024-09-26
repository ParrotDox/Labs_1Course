#include <iostream>
#include "methods.h"
using namespace std;

Pair::Pair() 
{
	cout << "Base constructor\n";
	this->first = 0;
	this->second = 0;
};
Pair::Pair(int f, double s)
{
	cout << "Constructor with values\n";
	this->first = f;
	this->second = s;
}
Pair::Pair(Pair& obj)
{
	cout << "Copy constructor\n";
	this->first = obj.first;
	this->second = obj.second;
}
void Pair::setAll()
{
	cout << "First: ";
	cin >> this->first;
	cout << "Second: ";
	cin >> this->second;
}
void Pair::getAll()
{
	cout << this->first << " : " << this->second << '\n';
}
Pair& Pair::operator=(Pair& obj)
{
	this->first = obj.first;
	this->second = obj.second;
	return *this;
}
Pair& Pair::operator + (const int& C)
{
	this->first += C;
	return *this;
}
Pair& Pair::operator + (const double& C)
{
	this->second += C;
	return *this;
}
Pair& Pair::operator - (Pair& obj)
{
	this->first -= obj.first;
	this->second -= obj.second;
	return *this;
}
istream& operator >> (istream& in, Pair& obj) 
{
	cout << "First: "; in >> obj.first;
	cout << "Second: "; in >> obj.second;
	return in;
};
ostream& operator << (ostream& out, const Pair& obj)
{
	return (out << obj.first << " : " << obj.second << '\n');
}