#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    srand(time(0));
    int n;
    cout<<"Enter the length of the array:";     //Ввод длины будущего массива
    cin>>n;
    cout<<endl;
    int m[n];

    cout<<"This is your array:";        //Создание массива случайных чисел
    for(int i=0;i<n;++i)
    {
        m[i]=rand()%100;
        cout<<m[i]<<" ";
    }

    cout<<endl;

    for(int i=0;i<n;++i)        //Часть кода, отвечающая за проставление -1 перед четным числом
    {
       if(m[i]%2==0)
       {
            ++n;
            for(int j=n;j!=i;--j)
            {
                m[j] = m[j-1];
            }
            m[i] = -1;
            ++i;
       }
       
    }

    cout<<"This is your array after an addition operation:";        //Вывод массива с -1 перед четными числами
    for(int i=0;i<n;++i)
    {
        cout<<m[i]<<" ";
    }

    cout<<endl;

    for(int i=0;i<n;++i)        //Часть кода, отвечающая за удаление нечетных элементов массива
    {
        if(m[i]%2!=0)
        {
            for(int j=i;j<n;++j)
            {
                m[j] = m[j+1];
            }
            --n;
            --i;
        }
    }

    cout<<"This is your array after a deleting operation:";         //Вывод массива после удаления из него нечётных элементов
    for(int i=0;i<n;++i)
    {
        cout<<m[i]<<" ";
    }

    return 0;
}