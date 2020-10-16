#include <stdio.h>
#include <math.h>

int fib(int n)
{
    return (pow((1.0+sqrt(5))/2, (double)n) - pow((1.0-sqrt(5))/2, (double)n))/sqrt(5) + 1e-9;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
}