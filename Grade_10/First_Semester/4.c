#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, d = 1, i = 0;

    scanf("%d", &n);
    while (d * d <= n)
    {
        if (n % d == 0)
        {
            if (d == n / d)
            {
                printf("%d ", d);
            }
            else
            {
                printf("%d ", d);
                printf("%d ", n / d);
            }
        }
        d++;
    }
    printf("\n");
    return 0;
}