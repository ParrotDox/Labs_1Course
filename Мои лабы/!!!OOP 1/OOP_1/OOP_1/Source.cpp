#include <iostream>
#include "methods.h"
using namespace std;

void main()
{
	arithmetic_progression obj(3.2, 5);
	int order = -1;
	do
	{
		cout << "0 - quit ; 1 - set; 2 - get ; 3 - operation: ";
		cin >> order;
		switch(order)
		{
		case(0):
		{
			break;
		}
		case(1):
		{
			obj.setPrivate();
			break;
		}
		case(2):
		{
			obj.getPrivate();
			break;
		}
		case(3):
		{
			int j;
			cout << "Enter pow: ";
			cin >> j;
			obj.element(j);
		}
		default:
		{
			break;
		}
		}
	} while (order != 0);
}