#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", j);
        printf("\n");
    }
    return 0;
}