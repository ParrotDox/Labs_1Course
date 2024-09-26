#include "Header.h"

void main()
{
	list<int> one;
	one.pushFront(1);
	one.pushFront(2);
	one.pushFront(3);
	one.print();
	iter<int> first(one);
	first.getValue();
	++first;
	++first;
	++first;
	system("pause");
}