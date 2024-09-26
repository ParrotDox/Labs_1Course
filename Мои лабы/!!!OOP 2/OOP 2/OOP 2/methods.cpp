#include <iostream>
#include "methods.h"
using namespace std;

salary::salary()
{
	cout << "Base constructor\n";
	this->name = "No_info";
	this->salary_scale = 0.0;
	this->prize = 0;
};
salary::salary(string n, double ss, int p)
{
	cout << "Constructor with values\n";
	this->name = n;
	this->salary_scale = ss;
	this->prize = p;
};
salary::salary(const salary& obj)
{
	cout << "Copy constructor\n";
	this->name = obj.name;
	this->salary_scale = obj.salary_scale;
	this->prize = obj.prize;
};
salary::~salary()
{
	cout << "Destructor\n";
}
void salary::setAll()
{
	cin.clear();
	cout << "Name: ";
	getline(cin,this->name);
	cout << "Scale of salary: ";
	cin >> this->salary_scale;
	cout << "Prize: ";
	cin >> this->prize;
}
void salary::setName()
{
	cout << "Enter name: ";
	cin >>this->name;
}
void salary::setSalaryScale()
{
	cout << "Enter scale of salary: ";
	cin >> this->salary_scale;
}
void salary::setPrize()
{
	cout << "Enter prize: ";
	cin >> this->prize;
}
void salary::getAll()
{
	cout << "Info:\n"
		<< "Name: " << this->name << '\n'
		<< "Scale of Salary: " << this->salary_scale << '\n'
		<< "Prize: " << this->prize << '\n';
}
void salary::getName()
{
	cout << "Name: " << this->name << '\n';
}
void salary::getSalaryScale()
{
	cout << "Scale of Salary: " << this->salary_scale << '\n';
}
void salary::getPrize()
{
	cout << "Prize: " << this->prize << '\n';
}