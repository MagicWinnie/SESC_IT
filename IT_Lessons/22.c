#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getNext(int *arr, int n)
{
    int *arrOld = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) arrOld[i] = arr[i];
    int new = n + 8;
    arr = (int*)realloc(arr, new*sizeof(int));
    for (int i = 0; i <= new; i++)
    {
        int q = 0;
        for (int j = 0; j < 10; j++)
        {
            if (i-j >= 0 && i-j < n) q += arrOld[i-j];
        }
        printf("q: %d\n", q);
        arr[i] = q;
    }
    // for (int i = 0; i <= new; i++) printf("%d,", arr[i]);
    // printf("\n");
}

int main()
{
    int n, count = 0, size = 10;
    int *arr = (int*)malloc(size*sizeof(int));
    scanf("%d", &n);
    if (n % 2 != 0){
        printf("Not equal number of digits\n");
        return 0;
    }
    for (int i = 0; i < 10; i++) arr[i] = 1;
    for (int i = 0; i < n/2 - 1; i++)
    {
        getNext(arr, size);
        for (int i = 0; i <= size; i++) printf("%d, ", arr[i]);
        printf("\n");
        size += 9;
    }
    for (int i = 0; i < size; i++)
    {
        count += (int)pow(arr[i], 2);
        printf("%d ", arr[i]);
    }
    printf("%d\n", count);        
}