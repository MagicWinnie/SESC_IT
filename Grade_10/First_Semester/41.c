#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

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
    n = (n - 360 * (int)(n / 360)) * M_PI / 180;

    for (int i = 0; i <= 10; i++)
        res += (double)(pow(-1, i) * pow(n, 2 * i + 1)) / (double)factorial(2 * i + 1);
    printf("%lf\n", res);

    return 0;
}