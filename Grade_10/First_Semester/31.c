#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j <= n; j++)
                printf("%d ", j);
        }
        else
        {
            for (int j = n; j >= 0; j--)
                printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}