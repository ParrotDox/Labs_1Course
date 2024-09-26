#include <iostream>
#include <stdlib.h>
using namespace std;

int result(int* arr,int size) //Функция, вычисляет кол-во любых элементов, которые больше элементов на гл.диагонали
{
    int min_elem = *arr;    //Задаем в качестве минимального элемента первый элемент двумерного массива
    int n = 0;  //Счётчик для вычисления мин.числа на диагонали

    for(int i;i<size;++i)   //Работа с адресами, нахождение мин.элемента диагонали
    {
        if(min_elem>*(arr+(n+i*size)))  
        {
            min_elem = *(arr+(n+i*size));
        }
        ++n;    //Сдвиг на ступеньку ниже
    }
    cout<<"Minimal element of the main diagonal is:"<<min_elem<<endl;
    n = 0;
    int counter = 0; //Счетчик для элементов, которые больше мин.элемента диагонали
    for(int i=0;i<size;++i)
    {
        for(int j=0;j<size;++j)
        {
            if((min_elem>*(arr+(i*size+j))) && (arr+(i*size+n) != arr+(i*size+j)))  //Сравнение значения, сравнение адресов
            {
                ++counter;
            }
        }
        ++n;    //Сдвиг на ступеньку ниже
    }

    return counter;
}

int main()
{
    srand(time(0));
    int size;   //Переменная для хранения значения размерности массива
    do  //Задаем размерность двумерного массива
    {
        cout<<"Enter the value to set the array size(2<=size):";
        cin>>size;
    }
    while(size < 2);
    cout<<"The size is "<<size<<endl;

    int mas[size][size];    //Задаем двумерный массив размером size x size, заполнение нулями

    for(int i=0;i<size;++i) //Заполняем массив случайными числами
    {
        for(int j=0;j<size;++j)
        {
            mas[i][j] = rand()%10;
            cout<<mas[i][j]<<" ";
        }
        cout<<endl;
    }

    int call_func = result(*mas,size);
    cout<<"Quantity of elements that have smaller values than the smallest value of the diagonal:"<<call_func;
    return 0;
}