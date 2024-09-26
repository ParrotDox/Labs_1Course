#include <iostream>
#include <cmath>
using namespace std;

double recur(int x)
{
	if (x == 1)
	{
		cout << "x = " << x << " " << "y=" << pow(-1, x) * pow(x, 2 * x + 1) / (2 * x + 1) << endl;
		return pow(-1, x) * pow(x, 2 * x + 1) / 2 * x + 1;
	}
	if(x>1)
	{
		cout << "x = " << x << " " << "y=" << pow(-1, x) * pow(x, 2 * x + 1) / (2 * x + 1) << endl;
		return pow(-1, x) * pow(x, 2 * x + 1) / (2 * x + 1) + recur(x - 1);
	}
}

int main()
{
	int n;
	do
	{
		cout << "Enter the n value:";
		cin >> n;
	} while (n < 0);
	
	double sum;
	sum = recur(n);
	cout << "sum = " << sum << endl;
	system("pause");
	return 0;
}