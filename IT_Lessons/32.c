#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    while (n >= 0)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%d ", j);
        }
        n--;
        printf("\n");
    }
}