#include <stdio.h>

int main()
{
    int i = 0, k = 1, p = 0, n;
    scanf("%d", &n);
    int matrix[n][n];
    int len = n;

    while (k <= n*n)                      
    {
        for (i = p; i < len; i++)
        {
            matrix[p][i] = k++-1;
        }
        for (i = p+1; i < len; i++)
        {
            matrix[i][len-1] = k++-1;
        }
        for (i = len-2; i >= p; i--) 
        {
            matrix[len-1][i] = k++-1;
        }
        for (i = len-2; i > p; i--)
        {
            matrix[i][p] = k++-1;
        }
        p++;
        len--;
        
    }
    if (!n%2)
    {
        matrix[(n+1)/2][(n+1)/2] = n*n;
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}