#include <iostream>
using namespace std;

int hanoi(int disks, int start, int temp, int point);

int main()
{
	hanoi(3, 1, 3, 2);
	system("pause");
	return 0;
}

int hanoi(int disks, int start, int temp, int point)
{
	if(disks > 0)
	{
		hanoi(disks - 1, start, point, temp);
		cout << start << "->" << temp << endl;
		hanoi(disks - 1, point, temp, start);
	}

	return 0;
}