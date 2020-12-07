#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
    }
}

int main()
{
    srand(time(NULL));

    int n, lower = -50, upper = 50;
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arr[i] = rand() % (upper - lower + 1) + lower;
    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) printf("%d ", arr[i]); 
    printf("\n");

    // binary search

    int v;
    scanf("%d", &v);

    int l = 0;
    int r = n - 1;
    int f = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (v == arr[mid])
        {
            f = mid;
            break;
        }
        if (v < arr[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }

    if (f == -1)
        printf("Not found\n");
    else
        printf("Found at index: %d\n", f);

    return 0;
}