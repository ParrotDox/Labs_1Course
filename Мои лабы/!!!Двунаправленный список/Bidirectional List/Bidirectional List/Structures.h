#pragma once
using namespace std;

enum methods
{
	QUIT = 0,
	AddHN = 1,
	AddTN = 2,
	AddNbyP = 3,
	DelHN = 4,
	DelTN = 5,
	DelNbyP = 6,
	PRINT = 7,
	ChKey = 8
};

struct Node
{
	Node* ptrToPrev;
	Node* ptrToNext;
	int data;
};
struct List
{
	Node* ptrToHead = nullptr;
	Node* ptrToTail = nullptr;
	int nodeCounter = 0;
};

int getData()
{
	int data;
	cout << "Enter data: ";
	cin >> data;
	return data;
}

void addHeadNode(List& list)
{
	Node* currentNode = new Node;
	int data = getData();

	if(list.nodeCounter == 0)
	{
		list.ptrToHead = currentNode;
		list.ptrToTail = currentNode;
		currentNode->ptrToNext = nullptr;
		currentNode->ptrToPrev = nullptr;
		currentNode->data = data;
		++list.nodeCounter;
	}
	else
	{
		Node* tempPtr = list.ptrToHead;
		list.ptrToHead = currentNode;
		currentNode->ptrToNext = tempPtr;
		currentNode->ptrToPrev = nullptr;
		currentNode->data = data;
		tempPtr->ptrToPrev = currentNode;
		++list.nodeCounter;
	}
}

void addTailNode(List& list)
{
	Node* currentNode = new Node;
	int data = getData();

	if (list.nodeCounter == 0)
	{
		list.ptrToHead = currentNode;
		list.ptrToTail = currentNode;
		currentNode->ptrToNext = nullptr;
		currentNode->ptrToPrev = nullptr;
		currentNode->data = data;
		++list.nodeCounter;
	}
	else
	{
		Node* tempPtr = list.ptrToTail;
		list.ptrToTail = currentNode;
		currentNode->ptrToPrev = tempPtr;
		currentNode->ptrToNext = nullptr;
		currentNode->data = data;
		tempPtr->ptrToNext = currentNode;
		++list.nodeCounter;
	}
}

void addNodeByPosition(List& list)
{
	Node* currentNode = list.ptrToHead;
	if (list.nodeCounter == 0)
	{
		cout << "Auto add: no Nodes in the list\n";
		addHeadNode(list);
	}
	else
	{
		if (list.nodeCounter != 0)
		{
			int request = -1;
			do
			{
				cout << "Nodes in the list: " << list.nodeCounter << '\n';
				cout << "Required position: ";
				cin >> request;
			} while (request < 1 || request > list.nodeCounter);
			if (request == list.nodeCounter) { addTailNode(list); }
			else
			{
				for (int i = 1; i < request; ++i)
				{
					currentNode = currentNode->ptrToNext;
				}
				int data = getData();
				Node* tempForward = currentNode->ptrToNext;
				Node* newNode = new Node;
				currentNode->ptrToNext = newNode;
				tempForward->ptrToPrev = newNode;
				newNode->ptrToPrev = currentNode;
				newNode->ptrToNext = tempForward;
				newNode->data = data;
				++list.nodeCounter;
			}

		}
	}
}

void deleteHeadNode(List& list)
{
	Node* currentNode = list.ptrToHead;
	if(list.nodeCounter == 0)
	{
		cout << "No Nodes in the list\n";
	}
	else
	{
		if (list.nodeCounter == 1)
		{
			delete currentNode;
			list.ptrToHead = nullptr;
			list.ptrToTail = nullptr;
			--list.nodeCounter;
		}
		else
		{
			if (list.nodeCounter > 1)
			{
				Node* tempPtr = currentNode->ptrToNext;
				list.ptrToHead = tempPtr;
				tempPtr->ptrToPrev = nullptr;
				delete currentNode;
				--list.nodeCounter;
			}
		}
	}
}

void deleteTailNode(List& list)
{
	Node* currentNode = list.ptrToTail;
	if (list.nodeCounter == 0)
	{
		cout << "No Nodes in the list\n";
	}
	else
	{
		if (list.nodeCounter == 1)
		{
			delete currentNode;
			list.ptrToHead = nullptr;
			list.ptrToTail = nullptr;
			--list.nodeCounter;
		}
		else
		{
			if (list.nodeCounter > 1)
			{
				Node* tempPtr = currentNode->ptrToPrev;
				list.ptrToTail = tempPtr;
				tempPtr->ptrToNext = nullptr;
				delete currentNode;
				--list.nodeCounter;
			}
		}
	}
}

void deleteNodeByPosition(List& list)
{
	Node* currentNode = list.ptrToHead;
	if(list.nodeCounter == 0)
	{
		cout << "No Nodes in the list\n";
	}
	else
	{
		if (list.nodeCounter == 1)
		{
			cout << "Auto Delete: only one Node in the list\n";
			delete currentNode;
			list.ptrToHead = nullptr;
			list.ptrToTail = nullptr;
			--list.nodeCounter;
		}
		else
		{
			if (list.nodeCounter > 1)
			{
				int request = -1;
				do
				{
					cout << "Nodes in the list: " << list.nodeCounter << '\n';
					cout << "Required position: ";
					cin >> request;
				} while (request < 1 || request > list.nodeCounter);
				if (request == 1) { deleteHeadNode(list); }
				if (request == list.nodeCounter) { deleteTailNode(list); }
				if (request != 1 && request != list.nodeCounter)
				{
					for (int i = 1; i < request; ++i)
					{
						currentNode = currentNode->ptrToNext;
					}
					Node* tempBack = currentNode->ptrToPrev;
					Node* tempForward = currentNode->ptrToNext;
					tempBack->ptrToNext = tempForward;
					tempForward->ptrToPrev = tempBack;
					delete currentNode;
					--list.nodeCounter;
				}
			}
		}
	}
}

void printList(List& list)
{
	if (list.nodeCounter != 0)
	{
		Node* currentNode = list.ptrToHead;
		int counter = 1;
		for (int i = 1; i <= list.nodeCounter; ++i)
		{
			cout << "[Node " << counter << ']' << '\n';
			cout << "Data: " << currentNode->data << '\n';
			cout << "Own: " << currentNode << '\n';
			cout << "Previous: " << currentNode->ptrToPrev << '\n';
			cout << "Next: " << currentNode->ptrToNext << '\n';
			currentNode = currentNode->ptrToNext;
			++counter;
		}
	}
	else cout << "List is empty\n";
}

void checkKey(List& list)
{
	Node* currentNode = list.ptrToHead;
	int counter = 1;
	int request;
	if (list.nodeCounter != 0)
	{
		cout << "Required key: ";
		cin >> request;
		bool flag = false;
		for (int i = 1; i <= list.nodeCounter; ++i)
		{
			if (request == currentNode->data)
			{
				flag = true;
				cout << "[Node " << counter << ']' << '\n';
				cout << "Data: " << currentNode->data << '\n';
				cout << "Own: " << currentNode << '\n';
				cout << "Previous: " << currentNode->ptrToPrev << '\n';
				cout << "Next: " << currentNode->ptrToNext << '\n';
			}
			currentNode = currentNode->ptrToNext;
			++counter;
		}
		if (flag == false) cout << "No coincidences have found\n";
	}
	else cout << "List is empty\n";
}