#include <iostream>
#include <string.h>
using namespace std;

int not_even_arr[10];
string str_arr[10];

template <typename T>
T even_element(T a[], const int n,int x)  //Функция, принимающая разные типы данных с помощью template
{
	int counter = 0;
	switch (x)	//Кейсы для вывода типа массива разных типов
	{
		case 0:
			cout << "int Array,even numbers:";
			break;
		case 1:
			cout << "float Array,even numbers:";
			break;
		case 2:
			cout << "double Array,even numbers:";
			break;
		case -1:
			break;
	}

	for(int i = 0; i < n; ++i)
	{
		int  A = (int)a[i];  //Вещественные числа не могут быть четными, следовательно нужно конвертировать тип данных в int и после смотреть на четность
		if(A%2 != 0)
		{
			cout << A << " ";
			not_even_arr[counter] = A;
			++counter;
		}
	}
	cout << endl;
	return counter;
}

int even_element(string a[],const int n,int x)
{
	int counter = 0;
	for(int i = 0; i < n; ++i)
	{
		if(a[i].size()%2 == 0)
		{
			str_arr[counter] = a[i];
			++counter;
		}
	}
	return counter;
}	  

int main()
{
	const int size = 10;
	int arr[size] = { 1,5,3,12,8,2,6,3,1,7 };  //Целочисленный массив
	cout << "Array with even values:";
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	int ctr = even_element(arr, size, 0);  //Возврат счётчика нечетных чисел для будущего вывода нового массива
	float arr_two[size] = { 1.3745908,5.257694,3.11231674,12.023425,8.8124143,2.098792,6.9123,3.1345346,1.3142345,7.9355678 };  //Массив типа float
	even_element(arr_two, size, 1);
	double arr_three[size] = { 1.2,5.6,3.9,12.1,8.4,2.8,6.6,3.7,1.1,7.3 };  //Массив типа double
	even_element(arr_two, size, 2);
	
	cout << "New array without any even values:";  //Вывод массива без четных чисел
	for(int i = 0; i < ctr ; ++i)
	{
		cout << not_even_arr[i] << " ";
	}
	cout << endl;

	string arrstr[size] = { "1234","123","1","12","123456","1","12345","1234567","1234","12" };  //Строчный массив
	int ctr_two = even_element(arrstr, size, 0);

	cout << "String array:";  //Вывод строчного массива
	for (int i = 0; i < size; ++i)
	{
		cout << arrstr[i] << " ";
	}
	cout << endl;

	cout << "New string array:";  //Вывод нового строчного массива, в котором элементы чётной длины
	for (int i = 0; i < ctr_two; ++i)
	{
		cout << str_arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}