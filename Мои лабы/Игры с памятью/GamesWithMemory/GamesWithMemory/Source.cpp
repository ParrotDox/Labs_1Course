#include <iostream>

using namespace std;

int main()
{
	srand(time(0));
	int mas[15];
	int size;
	int garb_size;
	cout << "Enter quantity to fill (0-15): ";
	cin >> size;
	garb_size = size;
	cout << "unsorted: ";
	for(int i = 0; i < size; ++i)  //Ввод случайных элементов в массив, вывод массива
	{
		mas[i] = rand() % 20;
		cout << mas[i] << " ";
	}

	cout << endl;

	//Поставить отладку на след.строку
	for(int i = 0; i < size; ++i)  //Отсортируем массив, удалим нечетные элементы
	{
		if(mas[i] % 2 != 0)
		{
			--size;
			for(int j = i; j < size; ++j)
			{
				mas[j] = mas[j + 1];
			}
			--i;
		}
	}
	
	cout << "Sorted: ";
	for(int i = 0; i < size; ++i)  //Вывод отсортированного массива
	{
		cout << mas[i] << " ";
	}

	cout << endl << "With garbage: ";
	for(int i = 0; i < garb_size; ++i)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}