#include <iostream>
using namespace std;

const int n = 8;
int field[n][n];

void setQueen(int stroka, int i)
{
	field[stroka][i] = 2;
}
void removeQueen(int stroka, int i)
{
	field[stroka][i] = 0;
}
void checkQueen(int stroka)
{
	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		if (field[stroka][i] == 0)
		{
			setQueen(stroka, i);
		}
	}
	flag = true;
}

int main()
{
	setQueen(2, 3);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cout << field[i][j] << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}