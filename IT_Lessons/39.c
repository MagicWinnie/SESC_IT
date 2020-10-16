#include <stdio.h>
#include <math.h>

double powerDouble(double x, double y) 
{ 
    return exp(y*log(x));
} 

double power(int x, int y)  
{  
    double res = x;
    if (y == 0)  
        return 1;
    for (int i = 1; i < abs(y); i++)
        res *= x;
    if (x > 0) return res;
    return 1/res;
}  
  

int main()
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%lf\n", power(a, b));
}