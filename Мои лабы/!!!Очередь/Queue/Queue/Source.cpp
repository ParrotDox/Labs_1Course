#include <iostream>
#include "Structures.h"
using namespace std;

int main()
{
	Queue* queue_one = new Queue;
	int option = -1;
	do
	{
		cout << "Options:\n"
			<< "QUIT - 0\n"
			<< "Add Node - 1\n"
			<< "Pop Node - 2\n"
			<< "Print queue - 3\n"
			<< "Check by key - 4\n"
			<< "Enter: ";
		cin >> option;
		cout << '\n';
		switch (option)
		{
		case QUIT: { break; }
		case AddN: { addNode(*queue_one); break; }
		case PopN: { popNode(*queue_one); break; }
		case PRINT: { printQueue(*queue_one); break; }
		case ChKey: { checkKey(*queue_one); break; }
		default:
			break;
		}
		cout << '\n';
	} while (option != 0);
}