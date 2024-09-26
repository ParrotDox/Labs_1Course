#include <iostream>
#include <cmath>
using namespace std;

double curve(double x)
{
    return 3*x-4*log(x)-5;
}

double tangent(double x)
{
    return 3-4/x;
}

double convergence(double x)
{
    return 4/pow(x,2);
}

int main()
{
    const double epsilon = pow(10,-6);
    double a = 2, b = 4, x;

    if(curve(a)*convergence(a)>0)
    {
        x=a;
    }
    else
    {
        x=b;
    }

    while(abs(curve(x)) > epsilon)
    {
        x = x - curve(x)/tangent(x);
        cout<<x<<endl;
    }
    return 0;
}
