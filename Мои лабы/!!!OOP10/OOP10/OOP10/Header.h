#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Pair
{
protected:
	int first;
	double second;
public:
	Pair();
	Pair(int,double);
	~Pair();
	void operator ++ ();
	void operator + (int value);
	void operator + (double value);
	void operator -- ();
	int getSum();
	friend istream& operator >> (istream& in, Pair& obj);
	friend ostream& operator << (ostream& out, Pair& obj);
};
Pair::Pair()
{
	first = 0;
	second = 0;
}
Pair::Pair(int first,double second)
{
	this->first = first;
	this->second = second;
}
Pair::~Pair() {};
void Pair::operator++()
{
	++first;
	++second;
}
void Pair::operator+(int value)
{
	first += value;
}
void Pair::operator+(double value)
{
	second += value;
}
void Pair::operator--()
{
	if(first > second)
	{
		first -= second;
	}
	else
	{
		second -= first;
	}
}
int  Pair::getSum()
{
	return first + second;
}

istream& operator >> (istream& in,Pair& obj)
{
	cout << "First: ";  in >> obj.first;
	cout << "Second: ";  in >> obj.second;
	return in;
}
ostream& operator << (ostream& out, Pair& obj)
{
	out << obj.first << " : " << obj.second;
	out << endl;
	return out;
}