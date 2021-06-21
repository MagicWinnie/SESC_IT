#include <stdio.h>

unsigned long long factorial(int n)
{
    if (n == 0)
        return 1;
    unsigned long long res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res; 
} 

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", factorial(n));
}