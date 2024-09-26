#include <iostream>
using namespace std;

void shellSort(int list[], int arrayLength)
{
	for (int step = arrayLength / 2; step > 0; step /= 2)
	{
		for (int i = step; i < arrayLength; i += 1)
		{
			int j = i;
			while (j >= step && list[j - step] > list[i])
			{
				swap(list[j], list[j - step]);
				j -= step;
			}
		}
	}
}

int main()
{
	int list[10] = { 3,19,8,0,48,4,5,12,8,10 };
	for (int i = 0; i < 10; i++)
	{
		cout << list[i] << " ";
	}

	cout << endl;

	shellSort(list, 10);
	shellSort(list, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << list[i] << " ";
	}

	cout << endl;
	system("pause");
	return 0;
}