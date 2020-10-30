#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(int **arr, int m, int n)
{
    printf("-------------------\n%d\n", m);
    for (int j = 0; j < n; j++)
        printf("%d ", arr[m][j]);
    printf("\n-------------------\n");
}

int main()
{
    int n, k;
    int** arr = (int**)malloc(2*sizeof(int*));

    arr[0] = (int*)malloc(3*sizeof(int));
    arr[1] = (int*)malloc(4*sizeof(int));

    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 1;
    
    scanf("%d %d", &n, &k);

    if (k > n)
    {
        printf("K cannot be greater than N\n");
        return -1;
    }
    if (k < 0 || n < 0)
    {
        printf("K or N cannot be lower than 0\n");
        return -1;
    }
    if (n == 0 || n == 1 || k == 0 || k == n) printf("1\n");
    else {
        for (int i = 3; i <= n; i++)
        {
            arr[1] = (int*)realloc(arr[1], (i+1)*sizeof(int));
    
            arr[1][0] = 1;
            arr[1][i] = 1;
    
            for (int j = 1; j < i; j++)
                arr[1][j] = arr[0][j-1]+arr[0][j];     
    
            arr[0] = (int*)realloc(arr[0], (i+1)*sizeof(int));
            memcpy(arr[0], arr[1], sizeof(int)*(i+1));
        }
        printf("%d\n", arr[0][k]);
    }
    free(arr);
    return 0;
}