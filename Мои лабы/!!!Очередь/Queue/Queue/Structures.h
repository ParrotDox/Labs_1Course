#pragma once
using namespace std;
enum methods
{
	QUIT = 0,
	AddN = 1,
	PopN = 2,
	PRINT = 3,
	ChKey = 4 
};
struct Node
{
	Node* ptrToPrev;
	Node* ptrToNext;
	int data;
};

struct Queue
{
	Node* ptrToHead;
	Node* ptrToTail;
	const int size = 5;
	int nodeCounter = 0;
};

int getData()
{
	int data;
	cout << "Enter data: ";
	cin >> data;
	return data;
}

void addNode(Queue& queue)
{
	if(queue.nodeCounter == queue.size)
	{
		cout << "Queue is full\n";
	}
	else
	{
		if (queue.nodeCounter == 0)
		{
			Node* newNode = new Node;
			queue.ptrToHead = newNode;
			queue.ptrToTail = newNode;
			newNode->ptrToPrev = nullptr;
			newNode->ptrToNext = nullptr;
			newNode->data = getData();
			++queue.nodeCounter;
		}
		else
		{
			Node* newNode = new Node;
			Node* tempPtr = queue.ptrToHead;
			queue.ptrToHead = newNode;
			newNode->ptrToNext = tempPtr;
			newNode->ptrToPrev = nullptr;
			newNode->data = getData();
			++queue.nodeCounter;
		}
	}
}

void popNode(Queue& queue)
{
	if(queue.nodeCounter == 0)
	{
		cout << "Queue is empty\n";
	}
	else
	{
		Node* currentNode = queue.ptrToHead;
		if(queue.nodeCounter == 1)
		{
			queue.ptrToHead = nullptr;
			queue.ptrToTail = nullptr;
			delete currentNode;
			--queue.nodeCounter;
		}
		else
		{
			for (int i = 1; i < queue.nodeCounter; ++i)
			{
				currentNode = currentNode->ptrToNext;
			}
			Node* tempNode = currentNode->ptrToPrev;
			queue.ptrToTail = tempNode;
			delete currentNode;
			--queue.nodeCounter;
			
		}
	}
}

void printQueue(Queue& queue)
{
	if(queue.nodeCounter == 0)
	{
		cout << "List is empty\n";
	}
	else
	{
		Node* currentNode = queue.ptrToHead;
		if(queue.nodeCounter == 1)
		{
			cout << "Queue contains only one Node\n";
			cout << "[Node]\n"
				<< "Data: " << currentNode->data << '\n'
				<< "Own: " << currentNode << '\n'
				<< "Previous: " << currentNode->ptrToPrev << '\n'
				<< "Next: " << currentNode->ptrToNext << '\n';
		}
		else
		{
			for (int i = 1; i <= queue.nodeCounter; ++i)
			{
				cout << "[Node " << i << "]\n"
					<< "Data: " << currentNode->data << '\n'
					<< "Own: " << currentNode << '\n'
					<< "Previous: " << currentNode->ptrToPrev << '\n'
					<< "Next: " << currentNode->ptrToNext << '\n';
				currentNode = currentNode->ptrToNext;
			}
		}
	}
}

void checkKey(Queue& queue)
{
	if (queue.nodeCounter == 0)
	{
		cout << "List is empty\n";
	}
	else
	{
		int request;
		cout << "Required key: ";
		cin >> request;
		Node* currentNode = queue.ptrToHead;
		if (queue.nodeCounter == 1 && request == currentNode->data)
		{
			cout << "[Node]\n"
				<< "Data: " << currentNode->data << '\n'
				<< "Own: " << currentNode << '\n'
				<< "Previous: " << currentNode->ptrToPrev << '\n'
				<< "Next: " << currentNode->ptrToNext << '\n';
		}
		else
		{
			for (int i = 1; i <= queue.nodeCounter; ++i)
			{
				if (request == currentNode->data)
				{
					cout << "[Node " << i << "]\n"
						<< "Data: " << currentNode->data << '\n'
						<< "Own: " << currentNode << '\n'
						<< "Previous: " << currentNode->ptrToPrev << '\n'
						<< "Next: " << currentNode->ptrToNext << '\n';
				}
				currentNode = currentNode->ptrToNext;
			}
		}
	}
}