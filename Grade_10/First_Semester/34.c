#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, len_n, len_m, k = 1, p_n = 0, p_m = 0;
    scanf("%d", &n);
    m = n;

    int **arr = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *)calloc(m, sizeof(int));
    len_n = n - 1;
    len_m = m - 1;

    while (k <= n * m)
    {
        for (int j = p_m; j <= len_m; j++)
        {
            if (!arr[p_n][j])
                arr[p_n][j] = (k++ - 1);
        }
        p_n++;
        for (int i = p_n; i <= len_n; i++)
        {
            if (!arr[i][len_m])
                arr[i][len_m] = (k++ - 1);
        }
        len_m--;
        for (int j = len_m; j >= p_m; j--)
        {
            if (!arr[len_n][j])
                arr[len_n][j] = (k++ - 1);
        }
        len_n--;
        for (int i = len_n; i >= p_n; i--)
        {
            if (!arr[i][p_m])
                arr[i][p_m] = (k++ - 1);
        }
        p_m++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
    return 0;
}