#include "Methods.h"

node::node(char keyValue, int dataValue)
{
	key = keyValue;
	data = dataValue;
}
node::~node()
{
	cout << "\nNode Destructor";
	nextPTR = nullptr;
	delete this;
}
node* node::getNextPTR()
{
	return nextPTR;
}
char node::getKey()
{
	return key;
}
int node::getData()
{
	return data;
}
void node::setNextPTR(node* adress)
{
	nextPTR = adress;
}

bucket::bucket() {};
bucket::~bucket()
{
	cout << "\nbucket Destructor";
	cout << "\nAdress:" << this;
	if(collision == 0)
	{
		delete this;
	}
	else
	{
		node* prevPTR = head;
		node* curPTR = head->getNextPTR();
		while (curPTR != nullptr)
		{
			prevPTR->~node();
			prevPTR = curPTR;
			curPTR = curPTR->getNextPTR();
		}
		prevPTR->~node();
		prevPTR = nullptr;
		curPTR = nullptr;
		head = nullptr;
		delete this;
	}
}
node* bucket::getHead()
{
	return head;
}
void bucket::setHead(node* adress)
{
	head = adress;
}
void bucket::print()
{
	if(collision == 0)
	{
		cout << "\nEmpty";
		return;
	}
	//Обычный проход по каждой ноде по адресу
	int ctr = 0;
	node* temp = head;
	while(temp != nullptr)
	{
		cout << "\n[Node: " << ctr << ']';
		cout << "\nKey: " << temp->getKey();
		cout << "\nData: " << temp->getData();
		temp = temp->getNextPTR();
		++ctr;
	}
}

hash_table::hash_table(const int hashValue)
{
	hash = hashValue;
	mas = new bucket*[hash];
	for(int i = 0; i < hash; ++i)
	{
		mas[i] = new bucket();
	}
}
hash_table::~hash_table()
{
	cout << "\nhash_table Destructor";
	delete[] mas;
	bucket** mas = nullptr;
}
void hash_table::add(char keyValue, int dataValue)
{
	int index = int(keyValue) % hash;
	cout << "\nHash index: " << index;
	if(mas[index]->collision == hash-1)
	{
		node* temp = mas[index]->getHead();
		node* newNode = new node(keyValue, dataValue);
		while (temp->getNextPTR() != nullptr)
		{
			temp = temp->getNextPTR();
		}
		temp->setNextPTR(newNode);
		++(mas[index]->collision);
		cout << "\nToo much collisions!\nCreating new table...";
		reCreate();
		return;
	}
	node* newNode = new node(keyValue, dataValue);
	if(mas[index]->collision == 0)
	{
		mas[index]->setHead(newNode);
		++(mas[index]->collision);
		return;
	}
	if(mas[index]->collision == 1)
	{
		mas[index]->getHead()->setNextPTR(newNode);
		++(mas[index]->collision);
		return;
	}
	if(mas[index]->collision > 1)
	{
		node* temp = mas[index]->getHead();
		while(temp->getNextPTR() != nullptr)
		{
			temp = temp->getNextPTR();
		}
		temp->setNextPTR(newNode);
		++(mas[index]->collision);
		return;
	}
}
void hash_table::print()
{
	//Проход по бакетам по адресам массива
	for(int i = 0; i < hash; ++i)
	{
		cout << "\n\nBucket: " << i;
		mas[i]->print();
	}
}
void hash_table::reCreate()
{
	//Надо создать временные хранилища для копирования
	//Данных из старой таблицы в новую
	//Размеры новой таблицы будут в 2 раза больше старых, значение хэша тоже
	bucket** old_mas = mas;
	int old_hash = hash;
	hash = hash * 2;
	bucket** new_mas = new bucket* [this->hash];
	mas = new_mas;
	for (int i = 0; i < hash; ++i)
	{
		mas[i] = new bucket();
		if(i < old_hash)
		{
			mas[i]->collision = old_mas[i]->collision;
		}
	}
	node* temp;
	for(int i = 0; i < old_hash; ++i)
	{
		temp = old_mas[i]->getHead();
		while(temp!= nullptr)
		{
			add(temp->getKey(), temp->getData());
			temp = temp->getNextPTR();
		}
	}
	delete[] old_mas;
}