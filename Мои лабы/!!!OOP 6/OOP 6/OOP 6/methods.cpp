#include "methods.h"

//iter methods
iter::iter()
{
	cout << "Iter constructor. No values\n";
	this->elem = nullptr;
}
iter::~iter()
{
	cout << "Iter destructor\n";
	elem = nullptr;
}
void iter :: operator = (int* adress)
{
	this->elem = adress;
}
void iter :: operator ++ ()
{
	++elem;
}
void iter :: operator + (int n)  //Возможен выход за границы
{
	for(int i = 0; i < n; ++i)
	{
		++elem;
	}
}
void iter :: operator -- ()
{
	--elem;
}
int& iter :: operator * ()
{
	return *elem;
}
int iter :: get_elem()
{
	return *elem;
}

//list methods
list::list(int size)
{
	cout << "List constructor. Only size\n";
	this->size = size;
	this->data = new int[this->size];
	for(int i = 0; i < this->size; ++i)
	{
		int n;
		cin >> n;
		this->data[i] = n;
	}
	this->beg = &data[0];
	this->end = &data[this->size-1];
}
list::list(int size, int data)
{
	cout << "List constructor. Size and data values\n";
	this->size = size;
	this->data = new int[this->size];
	for(int i = 0; i < this->size; ++i)
	{
		this->data[i] = data;
	}
	this->beg = &this->data[0];
	this->end = &this->data[this->size-1];
}
list :: list(list& obj)
{
	cout << "List copy constructor\n";
	this->size = obj.size;
	this->data = new int[size];
	for(int i = 0; i < this->size; ++i)
	{
		this->data[i] = obj.data[i];
	}
	this->beg = &this->data[0];
	this->end = &this->data[this->size-1];
}
list :: ~list()
{
	cout << "List destructor\n";
	delete[] data;
	beg = nullptr;
	end = nullptr;
}
int* list :: first()
{
	return beg;
}
int* list :: last()
{
	return end;
}
list& list :: operator = (list& obj)
{
	if (this == &obj) { return *this; }
	if (this->data != nullptr) { delete[] this->data; }
	this->size = obj.size;
	this->data = new int[this->size];
	for(int i = 0; i < this->size; ++i)
	{
		this->data[i] = obj.data[i];
	}
	return *this;
}
int& list :: operator [] (int index)
{
	if (index < this->size) { return data[index]; }
	else { cout << "Index is unavailable\n"; }
}
list& list :: operator + (int k)
{
	for(int i = 0; i < this->size; ++i)
	{
		this->data[i] = this->data[i] + k;
	}
	return *this;
}
list& list :: operator * (list& obj)
{
	for(int i = 0; i < this->size || i < obj.size; ++i)
	{
		this->data[i] = this->data[i] * obj.data[i];
	}
	return *this;
}
int list :: operator () ()
{
	return size;
}
istream& operator >> (istream& in, list& obj)
{
	for(int i = 0; i < obj.size; ++i)
	{
		cout << "El." << i << " data: ";
		in >> obj.data[i];
	}
	return in;
}
ostream& operator << (ostream& out, list& obj)
{
	for (int i = 0; i < obj.size; ++i)
	{
		out << obj.data[i] << " ";
	}
	out << '\n';
	return out;
}
