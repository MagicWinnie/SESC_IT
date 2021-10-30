#include <stdio.h>
#include <stdint.h>
#include <math.h>

unsigned long long int factorial(int n)
{
    if (n == 0)
        return 1;
    unsigned long long int res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}

int main()
{
    double n, res = 0;
    scanf("%lf", &n);

    for (int i = 0; i <= 20; i++)
        res += (double)pow(n, i) / (double)factorial(i);

    printf("%lf\n", res);
    return 0;
}