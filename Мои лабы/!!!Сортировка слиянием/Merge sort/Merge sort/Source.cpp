#include <iostream>
using namespace std;
 
void merge(int array[], int start, int end, int mid);
void mergeSort(int array[], int start, int end)
{
	int mid;
	if(start < end)
	{
		mid = (start + end) / 2;
		mergeSort(array, start, mid);
		mergeSort(array, mid + 1, end);
		merge(array, start, end, mid);
	}
}
void merge(int array[], int start, int end, int mid)
{
	int mergedArray[15];
	int i = start;
	int k = start;
	int j = mid + 1;
	while(i<= mid && mid+1 <= end)
	{
		if(array[i] < array[j])
		{
			mergedArray[k] = array[i];
			++k;
			++i;
		}
		else
		{
			mergedArray[k] = array[j];
			++k;
			++j;
		}
	}
	while(i <= mid)
	{
		mergedArray[k] = array[i];
		++k;
		++i;
	}
	while(j <= end)
	{
		mergedArray[k] = array[j];
		++k;
		++j;
	}

	for(i = start; i < k; ++i)
	{
		array[i] = mergedArray[i];
	}
}

int main()
{
	int array[15] = {3,2,17,8,9,2,4,5,34,1,3,-1,0,5,7};
	for(int i = 0; i < 15; ++i)
	{
		cout << array[i] << " ";
	}
	cout << '\n';
	mergeSort(array, 0, 14);
	for (int i = 0; i < 15; ++i)
	{
		cout << array[i] << " ";
	}
	system("pause");
	return 0;
}