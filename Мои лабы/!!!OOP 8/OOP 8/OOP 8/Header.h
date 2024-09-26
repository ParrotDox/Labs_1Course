#pragma once
#include <iostream>
#include <string>
#include "event.h"
using namespace std;
class object
{
public:
	object() {};
	~object() {};
	virtual void show() = 0;
	virtual void input() = 0;
	virtual string get_name() = 0;
};
class print : public object	//Печатное издание
{
protected:
	string name;
	string author;
public:
	//Конструкторы и деструкторы
	print();
	~print();
	//Сетеры
	void set_name();
	void set_author();
	//Гетеры
	string get_name();
	string get_author();
	//Вывод
	void show();
	//Ввод
	void input();
};
print::print()
{
	name = "None";
	author = "None";
}
print::~print() {};
void print::set_name()
{
	cout << "\nName: "; cin >> name;
}
void print::set_author()
{
	cout << "\nAuthor: "; cin >> author;
}
string print::get_name()
{
	return name;
}
string print::get_author()
{
	return author;
}
void print::show()
{
	cout << "\nName: " << name;
	cout << "\nAuthor: " << author;
}
void print::input()
{
	cout << "\nName: "; cin >> name;
	cout << "Author: "; cin >> author;
}

class magazine : public print
{
protected:
	int pages;
public:
	//Конструкторы и деструкторы
	magazine();
	~magazine();
	//Гетеры
	int get_pages();
	//Сетеры
	void set_pages();
	//Вывод
	void show();
	//Ввод
	void input();
};
magazine::magazine()
{
	name = "None";
	author = "None";
	pages = 0;
}
magazine::~magazine() {};
int magazine::get_pages()
{
	return pages;
}
void magazine::set_pages()
{
	cout << "\nPages: "; cin >> pages;
}
void magazine::show()
{
	cout << "\nName: " << name;
	cout << "\nAuthor: " << author;
	cout << "\nPages: " << pages;
}
void magazine::input()
{
	cout << "\nName: "; cin >> name;
	cout << "Author: "; cin >> author;
	cout << "Pages: "; cin >> pages;
}

class vec
{
protected:
	object** ptr_masptr;
	int cur;
public:
	//Конструкторы и деструкторы
	vec();
	~vec();
	//Гетеры
	string get_name();
	//Методы
	void add();
	void del();
	void show();
	//Перегрузка операторов
	object* operator [] (int i);
};
vec::vec()
{
	cur = 0;
}
vec::~vec() {}
string vec :: get_name()
{
	return ptr_masptr[cur - 1]->get_name();
}
void vec :: add()
{
	object* obj_ptr;
	int request;
	cout << "\n1-print; 2-magazine: ";
	cin >> request;
	if(request == 1)
	{
		print* new_print = new print;
		new_print->input(); //Ввод инф.
		obj_ptr = new_print;
		++cur;
		ptr_masptr[cur-1] = obj_ptr;
	}
	else
	{
		magazine* new_magazine = new magazine;
		new_magazine->input();
		obj_ptr = new_magazine;
		++cur;
		ptr_masptr[cur-1] = obj_ptr;
	}
}
void vec :: del()
{
	if(cur == 0)
	{
		cout << "\nEmpty";
	}
	else
	{
		object* obj_ptr_to_del;
		obj_ptr_to_del = ptr_masptr[cur - 1];
		delete obj_ptr_to_del;
		obj_ptr_to_del = nullptr;
		--cur;
	}
}
void vec :: show()
{
	if(cur == 0)
	{
		cout << "\nEmpty";
	}
	else
	{
		for(int i=0; i < cur; ++i)
		{
			ptr_masptr[i]->show();
		}
	}
}
object* vec :: operator [] (int index)
{
	if (cur == 0)
	{
		cout << "\nEmpty";
	}
	else
	{
		if (index <= cur - 1 && index > -1)
			return ptr_masptr[index];
	}
}

//Диалог
class dialog : public vec
{
protected:
	int currentState;
public:
	//Конструкторы и деструкторы
	dialog();
	~dialog();
	//Методы
	virtual void getEvent(TEvent& event);
	virtual int execute();
	virtual void handleEvent(TEvent& event);
	virtual void clearEvent(TEvent& event);
	virtual int valid();
	virtual void endExec();
};
dialog::dialog()
{
	currentState = 0;
}
dialog::~dialog() {};
void dialog::getEvent(TEvent& event)
{
	string options = "m+-szq";
	cout << "\nm - создать группу";
	cout << "\n+ -добавить элемент";
	cout << "\n- -удалить элемент";
	cout << "\n? -вывести информацию об элементах группы";
	cout << "\nq - выход";
	string request;
	cout << "\nRequest: "; cin >> request;
	char code = request[0];
	if(options.find(code) >= 0)
	{
		event.type = evMessage; //Есть совпадение
		switch(code)
		{
		case('m'): event.cmcode = cmMake; break;
		case('+'): event.cmcode = cmAdd; break;
		case('-'): event.cmcode = cmDel; break;
		case('?'): event.cmcode = cmShow; break;
		case('q'): event.cmcode = cmQuit; break;
		}
	}
	else
	{
		event.type = evNothing;
	}
}
int dialog::execute()
{
	TEvent event;	//Создается событие
	do
	{
		currentState = 0;	//Программа работает, пока это поле = 0
		getEvent(event);	//Запрашиваем действие от пользователя
		handleEvent(event);	//Обрабатываем запрос пользователя исходя из входных данных
	} while (!valid());	//Пока valid == 0, .exe работает
	return currentState;	//Иначе выходим с кодом 1
}
int dialog::valid()
{
	if(currentState == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void dialog::clearEvent(TEvent& event)
{
	event.type = evNothing;
}
void dialog::endExec()
{
	currentState = 1;
}
void dialog::handleEvent(TEvent& event)
{
	if(event.type == evMessage)
	{
		switch(event.cmcode)
		{
		case(cmMake):
		{
			ptr_masptr = new object*;
			cur = 0;
			clearEvent(event);
			cout << "\nGroup created";
			break;
		}
		case(cmAdd):
		{
			add();
			clearEvent(event);
			break;
		}
		case(cmDel):
		{
			del();
			clearEvent(event);
			break;
		}
		case(cmShow):
		{
			show();
			clearEvent(event);
			break;
		}
		case(cmQuit):
		{
			endExec();
			break;
		}
		}
	}
}