#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    srand(time(0));
    int n;
    cout<<"Enter the lenght of the array:"; //Ввод длины будущего массива
    cin>>n;                         
    int m[n];
    cout<<endl;

    cout<<"This is your array:";    //Создание массива случайных чисел
    for(int i=0;i<n;++i)
    {
        m[i] = rand()%10-5;
        cout<<m[i]<<" ";
    }
    cout<<endl;

    int k;      //Ввод шага для кольца
    do                              
    {
        cout<<"Enter the step for the circle:";
        cin>>k;
        cout<<endl;
    }
    while(k>n);

    cout<<"Array with entered step:";       //Вывод кольца с шагом k
    for(int i=k-1;i<n;++i)
    {
        cout<<m[i]<<" ";
    }
    for(int i=0;i<k-1;++i)
    {
        cout<<m[i]<<" ";
    }
    cout<<endl;

    int third_cup;      //Сортировка массива методом пузырька
    for(int i=n-1;i!=0;--i)
    {
        for(int j=0;j<i;++j)
        {
            if(m[j]>m[j+1])
            {
                third_cup = m[j];
                m[j] = m[j+1];
                m[j+1] = third_cup;
            }
        }
    }

    cout<<"Array with sort:";       //Вывод отсортированного массива
    for(int i=0;i<n;++i)
    {
        cout<<m[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;++i)        //Удаление четных элементов
    {
        if(m[i]%2==0)
        {
            for(int j=i;j<n;++j)
            {
                m[j] = m[j+1];
            }
            --n;
            --i;
        }
    }

    cout<<"Array after a deleting operation:";      //Вывод массива после удаление четных элементов
    for(int i=0;i<n;++i)
    {
        cout<<m[i]<<" ";
    }
    cout<<endl;

    
    if(n<=1)        //Вывод результата, если длина массива равна или меньше нулю/запрос на шаг сдвига массива и вывод массива со сдвигом
    {
        cout<<"Array's length <= 1";
    }
    else
    {
        do                              //Ввод шага для кольца
        {
            cout<<"Enter the step for the circle:";
            cin>>k;
            cout<<endl;
        }
        while(k>n);

        cout<<"Array with entered step:";       //Вывод кольца с шагом k
        for(int i=k-1;i<n;++i)
        {
            cout<<m[i]<<" ";
        }
        for(int i=0;i<k-1;++i)
        {
            cout<<m[i]<<" ";
        }
    }
    return 0;
}