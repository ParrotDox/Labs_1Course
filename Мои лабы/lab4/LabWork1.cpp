#include <iostream>
#include <stdlib.h>
using namespace std;

const int n = 10;

int main()
{
    srand(time(0));
    int m[n];
    int max,position,quantity;

    for(int i=0;i<n;++i)        //Заполнение массива случайными числами
    {
        m[i] = rand()%10-5;
        cout<<m[i]<<" ";
    }

    max = m[0];
    quantity = 1;

    for(int i=1;i<n;++i)        //Цикл для перебора массива
    {
        if(m[i]>max)            //Если нашлось новое максимальное число, то обнуляем счётчики, записываем число в max
        {
            max = m[i];
            quantity = 1;
            position = i + 1;
        }
        else
        {
            if(m[i]== max)      //Если находим число равное максимальному, то прибавляем +1 к счёту равных элементов с элементом max
            {
                ++quantity;
            }
        }

    }

    cout<<endl;
    cout<<"Maximum is "<<max<<endl;         //Вывод максимального значения
    cout<<"Quantity is "<<quantity<<endl;   //Вывод кол-ва повторяющегося макс.элемента
    cout<<"Position is "<<position<<endl;   //Вывод позиции макс.элемента
    return 0;
}