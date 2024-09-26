#include <iostream>
#include <stdlib.h>
using namespace std;

const int n = 10;
int main()
{
    srand(time(0));
    int m[n];
    bool flag = true;

    for(int i=0;i<n;++i)        //Ручной ввод элементов массива, всего их 10, можно реализовать ввод длины
    {
        cout<<"Enter the "<<i+1<<" element:";
        cin>>m[i];
        cout<<endl;
    }

    cout<<"This is your array:";        //Вывод массива с введенными числами, если он не упорядочен, программа выведет это
    for(int i=0;i<n-1;++i)
    {
        cout<<m[i]<<" ";
        if(m[i]<=m[i+1])
        {
            //Do nothing
        }
        else
        {
            flag = false;
        }
    }

    if(flag == true)        //Вывод сообщения о том, что массив упорядочен
    {
        cout<<endl<<"Array is ordered";
    }
    else
    {
        cout<<endl<<"Array is not ordered";
    }
    cout<<endl;

    return 0;
}