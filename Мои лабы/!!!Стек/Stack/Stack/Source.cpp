#include <iostream>
#include "Structures.h"
using namespace std;

//QUIT = 0,
//AddP = 1,
//DelP = 2,
//PRINT = 3,
//chKey = 4

int main()
{
	Stack* stack_one = new Stack;
	int option = -1;
	do
	{
		cout << "Options:\n"
			<< "QUIT - 0\n"
			<< "Add plate - 1\n"
			<< "Delete plate - 2\n"
			<< "Print stack - 3\n"
			<< "Check key - 4\n"
			<< "Enter: ";
		cin >> option;
		cout << '\n';
		switch (option)
		{
		case QUIT: { break; }
		case AddP: { addPlate(*stack_one); break; }
		case DelP: { delPlate(*stack_one); break; }
		case PRINT: { printStack(*stack_one); break; }
		case ChKey: { checkKey(*stack_one); break; }
		default:
			break;
		}
		cout << '\n';
	} while (option != 0);
	system("pause");
	return 0;
}