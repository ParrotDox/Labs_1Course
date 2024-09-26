#pragma once
#include <iostream>
#include <string>
using namespace std;

class person
{
protected:
	string name;
	int age;
public:
	person();
	person(string C, int D);
	person(person& obj);
	~person();
	void virtual getAll();
	void setName(string N);
	void setAge(int A);
	void virtual setAll(string N, int A);
	person& operator = (person& obj);
	friend istream& operator >> (istream& in, person& obj);
	friend ostream& operator << (ostream& out, person& obj);
};

class student : public person
{
private:
	string subject;
	int mark;
public:
	student();
	student(string A, int B);
	student(string A, int B, string C, int D);
	student(student& obj);
	~student();
	void getAll();
	void setSubject(string S);
	void setMark(int M);
	void setAll(string S, int M, string N, int A);
	student& operator = (student& obj);
	friend istream& operator >> (istream& in, student& obj);
	friend ostream& operator << (ostream& out, student& obj);
	void checkMark()
	{
		if(this->mark > 2)
		{
			cout << "Mark: " << this->mark << '\n';
			cout << "Mark is satisfactory\n";
		}
		else
		{
			cout << "Mark: " << this->mark << '\n';
			cout << "Mark isn't satisfactory\n";
		}
	}
};