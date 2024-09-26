#include "methods.h"

int main()
{
	/* Создадим лист, отправим в него несколько узлов,
	проверим работоспособность каждого метода класса list
	проверим перегруженный оператор поиска по индексу */

	list<double> list_one;
	list<char> list_two;

	list_one.pushFront(12.5);

	list_two.pushFront('D');
	list_two.pushFront('H');
	list_two.pushBack('Q');

	list_one.print();
	list_two.print();

	list_one.deleteHead();
	list_two.deleteHead();

	list_two.print();

	list_two.pushFront('A');
	list_two.pushBack('A');

	list_two.print();
	list_one.deleteHead();
	list_one.deleteTail();

	list_two.printByKey('A');

	cout << list_two[0] << endl << list_two[10];

	system("pause");
	return 0;
}