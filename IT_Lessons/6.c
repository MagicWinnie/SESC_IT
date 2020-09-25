#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    int d = 2;
    while (d*d <= n && n%d != 0)
        d++;
    return d*d > n;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (n%i==0 && isPrime(i))
            printf("%d ", i);
    }
    printf("\n");
        
}