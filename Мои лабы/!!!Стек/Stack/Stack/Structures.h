#pragma once
using namespace std;

enum methods
{
	QUIT = 0,
	AddP = 1,
	DelP = 2,
	PRINT = 3,
	ChKey = 4
};

struct Plate
{
	int data;
	Plate* ptrToNext;
};

struct Stack
{
	Plate* ptrToHead;
	int plateCounter = 0;
	const int size = 5;
};

int getData()
{
	int data;
	cout << "Enter data: ";
	cin >> data;
	return data;
}

void addPlate(Stack& stack)
{
	if(stack.plateCounter >= stack.size)
	{
		cout << "Operation is unavailable: stack is full\n";
	}
	else
	{
		Plate* newPlate = new Plate;
		if (stack.plateCounter == 0)
		{
			stack.ptrToHead = newPlate;
			newPlate->ptrToNext = nullptr;
			newPlate->data = getData();
			++stack.plateCounter;
		}
		else
		{
			Plate* currentPlate = stack.ptrToHead;
			stack.ptrToHead = newPlate;
			newPlate->ptrToNext = currentPlate;
			newPlate->data = getData();
			++stack.plateCounter;
		}
	}
}

void delPlate(Stack& stack)
{
	if(stack.plateCounter == 0)
	{
		cout << "Operation is unavailable: stack is empty\n";
	}
	else
	{
		Plate* currentPlate = stack.ptrToHead;
		Plate* tempPtr = currentPlate->ptrToNext;
		stack.ptrToHead = tempPtr;
		delete currentPlate;
		--stack.plateCounter;
	}
}

void printStack(Stack& stack)
{
	if(stack.plateCounter == 0)
	{
		cout << "Stack is empty\n";
	}
	else
	{
		Plate* currentPlate = stack.ptrToHead;
		for(int i = 1; i <= stack.plateCounter; ++i)
		{
			cout << "[Plate " << i << " ]\n"
				<< "Data: " << currentPlate->data << '\n'
				<< "Own: " << currentPlate << '\n'
				<< "Next: " << currentPlate->ptrToNext << '\n';
			currentPlate = currentPlate->ptrToNext;
		}
	}
}

void checkKey(Stack& stack)
{
	if (stack.plateCounter == 0)
	{
		cout << "Stack is empty\n";
	}
	else
	{
		Plate* currentPlate = stack.ptrToHead;
		int request;
		cout << "Required key: ";
		cin >> request;
		for (int i = 1; i <= stack.plateCounter; ++i)
		{
			if (request == currentPlate->data)
			{
				cout << "[Plate " << i << " ]\n"
					<< "Data: " << currentPlate->data << '\n'
					<< "Own: " << currentPlate << '\n'
					<< "Next: " << currentPlate->ptrToNext << '\n';
			}
			currentPlate = currentPlate->ptrToNext;
		}
	}
}