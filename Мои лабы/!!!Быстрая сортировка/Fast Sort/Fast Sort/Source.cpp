#include <iostream>
using namespace std;

int partition(int list[], int start, int pivot)
{
	int i = start;
	while (i < pivot)
	{
		if (list[i] > list[pivot] && i == pivot - 1)
		{
			swap(list[i], list[pivot]);
			pivot--;
		}

		else if (list[i] > list[pivot])
		{
			swap(list[pivot - 1], list[pivot]);
			swap(list[i], list[pivot]);
			pivot--;
		}

		else i++;
	}
	return pivot;
}

void quickSort(int list[], int start, int end)
{
	if (start < end)
	{
		int pivot = partition(list, start, end);

		quickSort(list, start, pivot - 1);
		quickSort(list, pivot + 1, end);
	}
}

int main()
{
	int list[10] = { 6, 13, 53, 8, 3, 9, 14, 0, 3, -1 };

	for (int i = 0; i < 10; i++)
	{
		cout << list[i] << " ";
	}

	cout << endl;
	quickSort(list, 0, 10);
	
	for (int i = 0; i < 10; i++)
	{
		cout << list[i] << " ";
	}

	cout << endl;
	system("pause");
	return 0;
}