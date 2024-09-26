#include <iostream>
#include "Structures.h"
using namespace std;
//AddHN = 1,
//AddTN = 2,
//AddNbyP = 3,
//DelHN = 4,
//DelTN = 5,
//DelNbyP = 6,
//PRINT = 7,
//ChKey = 8
int main()
{
	List* list_one = new List;
	int option = -1;
	do
	{
		cout << "Options:\n"
			<< "QUIT - 0\n"
			<< "Add Head Node - 1\n"
			<< "Add Tail Node - 2\n"
			<< "Add Node by Position - 3\n"
			<< "Delete Head Node - 4\n"
			<< "Delete Tail Node - 5\n"
			<< "Delete Node by Position - 6\n"
			<< "Print List - 7\n"
			<< "Check by key - 8\n"
			<< "Enter: ";
		cin >> option;
		cout << '\n';
		switch (option)
		{
		case QUIT: { break; }
		case AddHN: { addHeadNode(*list_one); break; }
		case AddTN: { addTailNode(*list_one); break; }
		case AddNbyP: { addNodeByPosition(*list_one); break; }
		case DelHN: { deleteHeadNode(*list_one); break; }
		case DelTN: { deleteTailNode(*list_one); break; }
		case DelNbyP: { deleteNodeByPosition(*list_one); break; }
		case PRINT: { printList(*list_one); break; }
		case ChKey: { checkKey(*list_one); break; }
		default:
			break;
		}
		cout << '\n';
	} while (option != 0);
	system("pause");
	return 0;
}