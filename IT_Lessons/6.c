#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    int d = 2;
    while (d*d <= n && n % d != 0)
        d++;
    return d*d > n;
}

int main()
{
    int n, i = 2;
    scanf("%d", &n);
    while (i*i <= n)
    {
        if (n % i == 0 && isPrime(i))
            printf("%d ", i);
        if (n % (n/i) == 0 && isPrime(n/i))
            printf("%d ", n/i);
        
        i++;
    }
    printf("\n");
        
}
