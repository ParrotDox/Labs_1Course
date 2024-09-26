#pragma once
#include <iostream>
using namespace std;
class Pair
{
private:
	int first;
	double second;
public:
	Pair();
	Pair(int f, double s);
	Pair(Pair& obj);
	void setAll();
	void getAll();
	Pair& operator = (Pair& obj);
	Pair& operator - (Pair& obj);
	Pair& operator + (const int&);
	Pair& Pair::operator + (const double&);
	friend istream& operator>>(istream& in, Pair& obj);
	friend ostream& operator<<(ostream& out, const Pair& obj);
};