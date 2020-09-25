#include <stdio.h>
#include <math.h>

int summ(a, n)
{
    int a1 = 0;
    for (int i = 0; i < n; i++)
    {
        a1 += a % 10;
        a = a / 10;
    }

    return a1;
}

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < pow(10, n); i++)
    {
        if (summ(i/(int)pow(10, n/2), n/2)==summ(i%(int)pow(10, n/2), n/2))
            count++;
    }
    printf("%d", count);
    printf("\n");
        
}