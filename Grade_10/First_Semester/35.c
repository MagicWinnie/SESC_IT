#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double sum(double a, double b) 
{ 
    return a+b; 
}

double sub(double a, double b) 
{ 
    return a-b; 
}

double mul(double a, double b) 
{ 
    return a*b; 
}

double division(double a, double b) 
{ 
    return a/b; 
}

int main()
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%lf\n", sum(a, b));
    printf("%lf\n", sub(a, b));
    printf("%lf\n", mul(a, b));
    printf("%lf\n", division(a, b));
}