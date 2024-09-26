#include <iostream>
#include "methods.h"
using namespace std;

void main()
{
	//Базовый конструктор
	salary obj1;
	//Вывод 1 объекта
	obj1.getAll();
	//Конструктор с параметрами
	salary obj2("Kamaledinov Maxim", 16520.05, 20);
	//Вывод 2 объекта с параметрами
	obj2.getAll();
	//Конструктор копирования
	salary obj3(obj2);
	//Вывод 3 объекта, созданного путем копирования
	obj3.getAll();
	//Изменим значения в 1 объекте
	cout << "Changing values: \n";
	obj1.setAll();
	//Вывод 1 объекта
	obj1.getAll();
	//Модифицируем поле 1 объекта
	cout << "Changing prize: \n";
	obj1.setPrize();
	//Вывод 1 объекта
	obj1.getAll();
	system("pause");
}