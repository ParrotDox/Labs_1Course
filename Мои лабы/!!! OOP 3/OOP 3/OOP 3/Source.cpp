#include <iostream>
#include "methods.h"
using namespace std;

void main()
{
	//Базовый конструктор
	Pair obj1;
	cout << obj1;
	//Конструктор со значениями
	Pair obj2(10, 12.5);
	cout << obj2;
	//Конструктор копирования
	Pair obj3(obj2);
	cout << obj3;
	//Ввод переменной
	cin >> obj1;
	cout << obj1;
	//Сложение с int, а после с double
	obj1 = obj1 + 10;
	obj1 = obj1 + 10.2;
	cout << obj1;
	//Вычитание 1 переменной из другой
	obj1 = obj1 - obj3;
	cout << obj1;

	system("pause");
}