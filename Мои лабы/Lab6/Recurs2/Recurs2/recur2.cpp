#include <iostream>
using namespace std;

int fibonachi(int x);
int main()
{
	int n;
	do
	{
		cout << "Enter the lenght of the fibonachi array:";
		cin >> n;
	} 
	while (n < 2);
	
	for(int i=1;i<=n;++i)
	{
		cout << fibonachi(i) <<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}
int fibonachi(int x)
{
	if (x == 1 || x == 2) return 1;
	if (x > 2) return fibonachi(x - 1) + fibonachi(x - 2);
}