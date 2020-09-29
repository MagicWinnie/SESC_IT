#include <stdio.h>
#include <math.h>

// double power(double x, double y) 
// { 
//     return exp(y*log(x));
// } 

double power(double x, int y)  
{  
    if (y == 0)  
        return 1;

    double temp = power(x, y / 2);  

    if (y%2 == 0)  
        return temp*temp;  
    if(y > 0)  
        return x*temp*temp;  
    return (temp*temp)/x;  
}  
  

int main()
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%lf\n", power(a, b));
}