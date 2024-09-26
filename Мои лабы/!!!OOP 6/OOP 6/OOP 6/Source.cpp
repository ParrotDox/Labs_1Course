#include "methods.h"

int main()
{
	//Инициализация списков
	list list_one(10);
	list list_two(10, 5);
	//Инициализация итераторов
	iter iter_one;
	iter iter_two;
	iter_one = list_one.first();
	iter_two = list_two.first();
	//Операции со списками cin / cout / =
	cout << list_one;
	cout << list_two;
	cin >> list_two;
	cout << list_two;
	list_one = list_two;
	cout << list_one;
	//Доступ по индексу
	cout << list_one[3];
	cout << list_one * list_two;
	iter_one + 4;
	++iter_one;
	cout << iter_one.get_elem();
	system("pause");
	return 0;
}