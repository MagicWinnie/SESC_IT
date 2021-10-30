#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sieveEratos(int n)
{
    bool *a = (bool *)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++)
        a[i] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j <= n; j += i)
                a[j] = false;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (a[i] == true)
            printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    sieveEratos(n);
    return 0;
}
