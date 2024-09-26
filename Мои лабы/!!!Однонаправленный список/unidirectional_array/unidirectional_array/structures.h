#pragma once
using namespace std;

enum states
{
	QUIT = -1,
	ADDHEAD = 1,
	ADDTOPOSITION = 2,
	ADDMULTITOPOSITION = 3,
	DELHEAD = 4,
	DELBYPOSITION = 5,
	PRINT = 6,
	CHECKKEY = 7
};

struct Node
{
	int data;
	Node* ptrToNextNode;
};

struct List
{
	Node* listHead = nullptr;
	int nodeCounter = 0;
};

void addHeadNode(List& list, const int data)
{
	Node* ptrToNewNode = new Node;
	ptrToNewNode->data = data;
	Node* ptrToHeadNode = list.listHead;
	ptrToNewNode->ptrToNextNode = ptrToHeadNode;
	list.listHead = ptrToNewNode;
	++list.nodeCounter;
	cout << "\n**New HeadNode was added**\n\n";
	cout << "Current adress:" << ptrToNewNode << '\n';
	cout << "Data:" << ptrToNewNode->data << '\n';
	cout << "Next adress:" << ptrToNewNode->ptrToNextNode << "\n\n";
}

void addNodeToPosition(List& list, int position, int data)
{
	Node* currentNode = list.listHead;
	if (list.nodeCounter > 1) //Если нод больше 1, то идем к нужному месту вставки при помощи цикла
	{
		int counter = 1; //Номер эл.,на котором находимся
		Node* ptrToNewNode = new Node;

		for (int i = 1; i < position; ++i) //Идем по указателям с помощью цикла
		{
			currentNode = currentNode->ptrToNextNode;
		}
		Node* tempToNewNode = currentNode->ptrToNextNode;  //Запоминаем указатель ДО-ноды в ПОСЛЕ-ноду
		currentNode->ptrToNextNode = ptrToNewNode; //ДО-ноду перезначиваем на новую ноду
		ptrToNewNode->data = data;
		ptrToNewNode->ptrToNextNode = tempToNewNode;  //ЭТА-нода указывает на ПОСЛЕ-ноду
		cout << "\n**New Node was inserted**\n\n";
		cout << "Current adress:" << ptrToNewNode << '\n';
		cout << "Data:" << ptrToNewNode->data << '\n';
		cout << "Next adress:" << ptrToNewNode->ptrToNextNode << "\n\n";
		++list.nodeCounter;
	}
	else
	{
		if (list.nodeCounter == 0)  //Если нод вообще нет
		{
			cout << "\n**Cin operation**\n\n";
			cout << "There are no Nodes in the list\n";
			addHeadNode(list, data);
		}
		else  //Если есть только голова
		{
			cout << "\n**Cin operation**\n\n";
			cout << "There is only one Node in the list\n";
			cout << "Inserting Node to the first position\n";
			Node* ptrToNewNode = new Node;
			currentNode->ptrToNextNode = ptrToNewNode; //Переуказываем головную ноду на новую ноду
			ptrToNewNode->ptrToNextNode = nullptr;
			ptrToNewNode->data = data;
			cout << "**New Node was inserted**\n\n";
			cout << "Current adress:" << ptrToNewNode << '\n';
			cout << "Data:" << ptrToNewNode->data << '\n';
			cout << "Next adress:" << ptrToNewNode->ptrToNextNode << "\n\n";
			++list.nodeCounter;
		}
	}
}

void delHeadNode(List& list)
{
	cout << "\n**DeleteHeadNode operation**\n";
	Node* ptrToHeadNode = list.listHead;  //Указатель на голову
	Node* ptrFromHeadToNextNode = ptrToHeadNode->ptrToNextNode;  //Указатель на след.ноду после головы
	list.listHead = ptrFromHeadToNextNode; //Перекидываем головной указатель с 1 ноды в списке на 2
	cout << "\nNode with adress " << ptrToHeadNode << " was deleted\n\n";
	delete ptrToHeadNode;  //Удаляем мусор
	--list.nodeCounter;
}

void delNodeByPosition(List& list, int position)
{
	Node* currentNode = list.listHead;
	if (list.nodeCounter > 1) //Если нод больше 1, то идем к нужному месту удаления при помощи цикла
	{
		int counter = 1; //Номер эл., на котором находимся
		if (position != 0)
		{
			if (position == 1)  //Если хотим удалить голову по позиции
			{
				delHeadNode(list);
				--list.nodeCounter;
			}
			else
			{
				for (int i = 1; i < position - 1; ++i) //Идем по указателям с помощью цикла и останавливаемся на ДО-ноде
				{
					currentNode = currentNode->ptrToNextNode;
				}
				Node* nodeTodelete = currentNode->ptrToNextNode; //Эта-Нода для удаления
				Node* tempAdress = nodeTodelete->ptrToNextNode; //После-нода, запоминаем ее адрес
				delete nodeTodelete;  //Удаляем эту-ноду
				currentNode->ptrToNextNode = tempAdress;  //Задаем ДО-ноде указатель на После-ноду
				--list.nodeCounter;
			}
		}
		else
		{
			cout << "Unavailable to delete\n";
		}
	}
	else
	{
		if (list.nodeCounter == 0)  //Если нод вообще нет
		{
			cout << "\n**DeleteByPosition operation**\n\n";
			cout << "There are no Nodes in the list\n";
		}
		else  //Если есть только голова
		{
			cout << "\n**DeleteByPosition operation**\n\n";
			cout << "There is only one Node in the list\n";
			cout << "Deleting HeadNode\n";
			delHeadNode(list);
			--list.nodeCounter;
		}
	}
}

void printList(List& list)
{
	if(list.listHead == nullptr)
	{
		cout << "List is empty\n";
	}
	else
	{
		Node* currentNode = list.listHead;
		int counter = 1;  //Счетчик для вывода номера ноды
		cout << "\n**Cout the list**\n\n";
		while(counter-1 != list.nodeCounter)
		{
			cout << "[Node]: " << counter << '\n' << "Adress: " << currentNode << '\n'
				<< "Data: " << currentNode->data << '\n' << "Ptr to next: " << currentNode->ptrToNextNode
				<< "\n\n";
			++counter;
			currentNode = currentNode->ptrToNextNode;
		}
	}
}

void checkKey(List& list, const int request)
{
	Node* currentNode = list.listHead;
	int counter = 1;
	cout << "\n**checkKey**\n\n";
	for(int i = 0; i < list.nodeCounter; ++i)
	{
		if(currentNode->data == request)
		{
			cout << "[Node]: " << counter << '\n' << "Adress: " << currentNode << '\n'
				<< "Data: " << currentNode->data << '\n' << "Ptr to next: " << currentNode->ptrToNextNode
				<< "\n\n";
		}
		++counter;
		currentNode = currentNode->ptrToNextNode;
	}
}

