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

    for(int i=0;i<side;++i) //Заполнение рандомными элементами
    {
        for(int j=0;j<side;++j)
        {
            m[i][j] = rand()%9;
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;

    for(int i=0;i<side;++i) //Ставим 0, если i+j даёт четное число, иначе ставим числа от 1 до 9
    {
        for(int j=0;j<side;++j)
        {
            if((i+j+1)%2==0)
            {
                m[i][j] = 0;
                cout<<m[i][j]<<" ";
            }
            else
            {
                m[i][j] = k;
                cout<<m[i][j]<<" ";
                ++k;
                if(k>9)
                {
                    k=1;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}