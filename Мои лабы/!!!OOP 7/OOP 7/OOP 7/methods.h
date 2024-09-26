#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node;

template <class T>
class list
{
	friend class Node<T>;
public:
	list<T>();
	~list<T>();
	void pushFront(T data);
	void pushBack(T data);
	void deleteHead();
	void deleteTail();
	void clear();
	void print();
	int getNodeCTR();
	void printByKey(T data);
	T operator [] (int index);
protected:
	Node<T>* headPTR;
	int nodeCTR;
};

template <class T>
class Node
{
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
list<T> :: list()
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
	}
	else
	{
		Node<T>* curNode = headPTR;
		for (int i = 0; i < nodeCTR - 1; ++i)
		{
			curNode = curNode->nodeNextPTR;
		}
		curNode->nodeNextPTR = newNode;
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
		headPTR = nullptr;
		--nodeCTR;
	}
	else
	{
		Node<T>* curNode = headPTR;
		for (int i = 0; i < nodeCTR - 1; ++i)
		{
			curNode = curNode->nodeNextPTR;
		}
		delete curNode;
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
void list<T> :: print()
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
	if (index < 0 || index > nodeCTR - 1)
	{
		cout << "Out of range\n";
	}
	else
	{
		Node<T>* curNode = headPTR;
		for (int i = 0; i < index; ++i)
		{
			curNode = curNode->nodeNextPTR;
		}
		return curNode->data;
	}
}

//Node methods
template <class T>
Node<T> :: Node()
{
	nodeNextPTR = nullptr;
};

template <class T>
Node<T> :: ~Node() {}