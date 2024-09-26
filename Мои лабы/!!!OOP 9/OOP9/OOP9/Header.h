#pragma once
#include <iostream>
using namespace std;

//итератор
//класс ошибок
template <class T>
class Node;
template <class T>
class iter;

template <class T>
class list
{
	friend class iter<T>;
	friend class Node<T>;
public:
	list<T>();
	~list<T>();
	void pushFront(T data);
	void pushBack(T data);
	void deleteHead();
	void deleteTail();
	Node<T>* getHead() { return headPTR };
	Node<T>* getTail() { return tailPTR };
	void clear();
	void print();
	int getNodeCTR();
	void printByKey(T data);
	T operator [] (int index);
	void except(int& index);
protected:
	Node<T>* headPTR;
	int nodeCTR;
	Node<T>* tailPTR;
};

template <class T>
class Node
{
	friend class iter<T>;
	friend class list<T>;
public:
	Node<T>();
	~Node<T>();
protected:
	T data;
	Node<T>* nodeNextPTR;
};


//list methods
template <class T>
list<T> ::list()
{
	headPTR = nullptr;
	nodeCTR = 0;
}

template <class T>
list<T> :: ~list()
{
	if (this->headPTR != nullptr)
	{
		delete headPTR;
		headPTR = nullptr;
	}
}

template <class T>
void list<T> ::pushFront(T data)
{
	Node<T>* newNode = new Node<T>;
	if (nodeCTR == 0)
	{
		headPTR = newNode;
		tailPTR = newNode;
	}
	else
	{
		Node<T>* temp = headPTR;
		headPTR = newNode;
		newNode->nodeNextPTR = temp;
	}
	newNode->data = data;
	++nodeCTR;
}

template <class T>
void list<T> ::pushBack(T data)
{
	Node<T>* newNode = new Node<T>;
	if (nodeCTR == 0)
	{
		headPTR = newNode;
		tailPTR = newNode;
	}
	else
	{
		tailPTR->nodeNextPTR = newNode;
		tailPTR = newNode;
	}
	newNode->data = data;
	++nodeCTR;
}

template <class T>
void list<T> ::deleteHead()
{
	if (nodeCTR == 0)
	{
		cout << "List is empty\n";
	}
	else
	{
		Node<T>* temp = headPTR->nodeNextPTR;
		delete headPTR;
		headPTR = temp;
		--nodeCTR;
	}
}

template <class T>
void list<T> ::deleteTail()
{
	if (nodeCTR == 0)
	{
		cout << "List is empty\n";
	}
	if (nodeCTR == 1)
	{
		delete headPTR;
		tailPTR = nullptr;
		headPTR = nullptr;
		--nodeCTR;
	}
	else
	{
		Node<T>* curNode = headPTR;
		for (int i = 0; i < nodeCTR - 2; ++i)
		{
			curNode = curNode->nodeNextPTR;
		}
		Node<T>* temp = curNode->nodeNextPTR;
		curNode->nodeNextPTR = nullptr;
		tailPTR = curNode;
		delete temp;
		--nodeCTR;
	}
}

template <class T>
void list<T> ::clear()
{
	if (nodeCTR == 0)
	{
		cout << "List is empty\n";
	}
	else
	{
		Node<T>* temp = headPTR->nodeNextPTR;
		while (temp != nullptr)
		{
			delete headPTR;
			--nodeCTR;
			headPTR = temp;
			temp = headPTR->nodeNextPTR;
		}
		delete headPTR;
		--nodeCTR;
		headPTR = temp;
	}
}

template <class T>
void list<T> ::print()
{
	if (nodeCTR == 0)
	{
		cout << "List is empty\n";
	}
	else
	{
		Node<T>* curNode = headPTR;
		for (int i = 1; i <= nodeCTR; ++i)
		{
			cout << i << ".\n"
				<< "Current: " << curNode << '\n'
				<< "Next: " << curNode->nodeNextPTR << '\n'
				<< "Data: " << curNode->data << '\n';
			curNode = curNode->nodeNextPTR;
		}
	}
}

template <class T>
int list<T> ::getNodeCTR()
{
	return nodeCTR;
}

template <class T>
void list<T> ::printByKey(T data)
{
	Node<T>* curNode = headPTR;
	if (nodeCTR == 0)
	{
		cout << "List is empty\n";
	}
	else
	{
		for (int i = 0; i < nodeCTR; ++i)
		{
			if (data == curNode->data)
			{
				cout << i << ".\n"
					<< "Current: " << curNode << '\n'
					<< "Next: " << curNode->nodeNextPTR << '\n'
					<< "Data: " << curNode->data << '\n';
			}
			curNode = curNode->nodeNextPTR;
		}
	}
}

template <class T>
T list<T> :: operator [] (int index)
{
	try
	{
		except(index);
	}
	catch(error& a)
	{
		a.what();
		return 0;
	}
	Node<T>* curNode = headPTR;
	for (int i = 0; i < index; ++i)
	{
		curNode = curNode->nodeNextPTR;
	}
	return curNode->data;
}
template <class T>
void list<T>::except(int& index)
{
	if(index < 0 || index > nodeCTR - 1)
	{
		throw error_size();
	}
}

//Node methods
template <class T>
Node<T> ::Node()
{
	nodeNextPTR = nullptr;
};

template <class T>
Node<T> :: ~Node() {}

//т.к. список односвязный, то итератор может перемещаться только вперед
//Будет перегрузка только инкремента (++)
template <class T>
class iter
{
private:
	Node<T>* headNode;
	Node<T>* curNode;
public:
	iter<T>(list<T>&);
	~iter<T>();
	void except();
	//Проход на следующий узел
	void operator ++ ();
	//Получает значение ячейки, на которую указывает итератор
	T getValue();
	//Изменяет значение ячейки, на которую указывает итератор
	void changeValue();
	//Ставит указатель итератора на голову
	void resetPosition();
};

template <class T>
iter<T>::iter(list<T>& list_obj)
{
	headNode = list_obj.headPTR;
	curNode = list_obj.headPTR;
}
template <class T>
iter<T>::~iter() {};
template <class T>
void iter<T>::except()
{
	if(curNode->nodeNextPTR == nullptr)
	{
		throw error_iterrange();
	}
}
template <class T>
void iter<T>::operator++ ()
{
	bool flag = false;
	try
	{
		except();
	}
	catch(error& a)
	{
		flag = true;
		a.what();
	}
	if(flag == false){ curNode = curNode->nodeNextPTR; }
}
template <class T>
T iter<T>::getValue()
{
	return curNode->data;
}
template <class T>
void iter<T>::changeValue()
{
	//Тут будет код try, возможно ошибка с несовпадением типов данных
	T newData;
	cin >> newData;
	curNode->data = newData;
}
template <class T>
void iter<T>::resetPosition()
{
	curNode = headNode;
}

class error
{
protected:
	int code;
	string message;
public:
	virtual void what() = 0;
};
class error_size : public error
{
public:
	error_size()
	{
		code = 1;
		message = "\nindex is out the range of the list. Error ";
	}
	void what()
	{
		cout << endl << message << code;
	}
};
class error_iterrange : public error
{
public:
	error_iterrange()
	{
		code = 2;
		message = "\nIterator can't go further due to his position is at the end. Error ";
	}
	void what()
	{
		cout << endl << message << code;
	}
};