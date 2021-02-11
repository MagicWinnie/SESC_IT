#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int m = n;
    while (n <= 2*m)
    {
        for (int j = n-m; j <= n; j++)
        {
            printf("%d ", j);
        }
        n++;
        printf("\n");
    }
}