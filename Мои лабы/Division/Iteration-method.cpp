#include <iostream>
#include <cmath>
using namespace std;

double expr(double x)
{
    return (4*log(x)+5)/3;
}

double deriv(double x)
{
    return 36/x;
}
int main()
{
    const double epsilon = pow(10,-6);
    double a = 2, b = 4, x = (a+b)/2;

    if (abs(deriv(x)<1))
    {
        while(abs(x-a)>epsilon)
        {
            a = x;
            x = expr(x);
            cout<<x<<endl;
        }
    }
    return 0;
}