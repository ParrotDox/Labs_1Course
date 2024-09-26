#include <iostream>
#include "structures.h"
using namespace std;

//struct Node
//{
//	int data;
//	Node* ptrToNextNode;
//};
//struct List
//{
//	Node* listHead = nullptr;
//	int nodeCounter = 0;
//};


//addHeadNode addNodeToPosition printList addNodeToPosition delNodeByPosition
int main()
{
	List* list_one = new List; //Наш список
	int key = -1;  //КЛЮЧ для машины состояний
	int data = -1;  //Буфер для данных
	do
	{
		cout << "|-1-QUIT|1-ADDHEAD|2-ADDTOPOSITION|3-ADDMULTITOPOSITION|4-DELHEAD|5-DELBYPOSITION|6-PRINT|7-CHECKKEY|: ";
		cin >> key;
		switch (key)
		{
		case QUIT:  //0
			break;

		case ADDHEAD: // 1
		{
			cout << "Enter data: ";
			cin >> data;
			addHeadNode(*list_one, data);  //func
			break;
		}

		case ADDTOPOSITION:  //2
		{
			int position = -1; //Куда вставить
			if (list_one->nodeCounter > 1)
			{
				do { //Циклом принимаем позицию, куда будем вставлять элемент
					cout << "\n**Cin operation**\n\n";
					cout << "Enter where to insert (1-" << list_one->nodeCounter << "): ";
					cin >> position;
					cout << "\n";
				} while (position > list_one->nodeCounter || position < 0);
			}
			else
			{
				cout << "List has " << list_one->nodeCounter << " Nodes\n"
					<< "Operation will be done automaticly\n";
				position = 0;

			}

			cout << "Enter data:";
			cin >> data;
			addNodeToPosition(*list_one, position, data);  //func
			break;
		}

		case ADDMULTITOPOSITION:  //3 Сделан на основе функ.вставки 1 ноды
		{
			int position = -1; //Куда вставить
			int repeat = 0;

			do
			{
				cout << "How many Nodes: ";
				cin >> repeat;  //Сколько раз повторяем вставку
			} while (repeat < 1);

			if (list_one->nodeCounter > 1)
			{
				do { //Циклом принимаем позицию, куда будем вставлять элемент
					cout << "\n**Cin operation**\n\n";
					cout << "Enter where to insert (1-" << list_one->nodeCounter << "): ";
					cin >> position;
					cout << "\n";
				} while (position > list_one->nodeCounter || position < 0);
			}
			else
			{
				cout << "\n**Cin operation**\n\n";
				position = 1;
			}

			for (int i = 0; i < repeat; ++i)  //Закидываем ноды в список по позиции
			{
				cout << "Enter data:";
				cin >> data;
				addNodeToPosition(*list_one, position, data);  //func
			}
			break;
		}

		case DELHEAD:  //4
		{
			delHeadNode(*list_one);
			break;
		}

		case DELBYPOSITION:  //5
		{
			int position = -1; //Какой удалить

			do { //Циклом принимаем позицию, откуда будем удалять элемент
				cout << "\n**DeleteByPosition operation**\n\n";
				cout << "Enter what element to delete (1-" << list_one->nodeCounter << "): ";
				cin >> position;
				cout << "\n";
			} while (position > list_one->nodeCounter || position < 0);
			delNodeByPosition(*list_one, position);
			break;
		}

		case PRINT:  //6
		{
			printList(*list_one);
			break;
		}

		case CHECKKEY:
		{
			int request = 0;
			cout << "Enter required key: ";
			cin >> request;
			checkKey(*list_one, request);
		}

		default:
			break;
		}
	} while (key!=-1);

	system("pause");
	return 0;
}