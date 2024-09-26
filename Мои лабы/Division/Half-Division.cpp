#include <iostream>
#include <cmath>
using namespace std;

double function(double x)
{
    return 3*x-4*log(x)-5;
}

int main()
{
    double a = 2, b = 4, x;
    double const epsilon = pow(10,-6);

    while(abs(a-b) > epsilon)
    {
        x = (a+b)/2;

        if(function(a)*function(b)<0)
        {
            b=x;
        }
        else
        {
            a=x;
        }
        cout<<x<<endl;
    }
    return 0;
}