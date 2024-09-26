#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int side; //Ввод стороны квадрата
    do
    {
        cout<<"Enter the value of the quad's side:";
        cin>>side;
    }
    while(side<2);
    int m[side][side]; //Задаём размерность массиву (Все элементы равны 0)
    int k = 1; //Счетчик для лесенки
    cout<<endl;

    for(int i=0;i<side;++i) //Добавление лесенки
    {

        k = 1 + i; //Шаг лесенки
        for(int j=0;j<side;++j)
        {
            m[i][j] = k;
            if(k!=0) //Условие для лесенки, чтобы она не уходила в минус
            {
                --k;
            }
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}