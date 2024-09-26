#include <iostream>
#include "methods.h"
using namespace std;

void arithmetic_progression::setPrivate()
{
	double f;
	int s;
	do
	{
		cout << "Enter a0:";
		cin >> f;
		cout << "Enter r:";
		cin >> s;
	} while (f == 0 || s < 0);
	this->first = f;
	this->second = s;
}

double arithmetic_progression::getPrivate()
{
	if(this->first == 0 && this->second == 0)
	{
		cout << "Initializate the values\n";
		return 0;
	}
	else
	{
		cout << "a0: " << this->first << "\nr: " << this->second << '\n';
	}
}

void arithmetic_progression::element(int j)
{
	if(arithmetic_progression::getPrivate() == 0)
	{
		cout << "Can't do that. Init the values";
	}
	else
	{
		cout << "Using formula An = a0 * r^j\n";
		cout << "Result: " << this->first * pow(this->second, j) << '\n';
	}
}