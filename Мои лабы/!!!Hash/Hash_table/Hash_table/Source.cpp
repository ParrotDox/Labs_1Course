#include "Methods.h"

int main()
{
	hash_table one(5);
	one.add('1', 1);
	one.add('1', 2);
	one.add('1', 3);
	one.add('1', 4);
	one.add('1', 5);
	one.add('1', 6);
	one.add('1', 7);
	one.add('1', 8);
	one.print();
	system("pause");
	return 0;
}