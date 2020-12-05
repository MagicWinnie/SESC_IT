#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int max_elem(int *arr, int n)
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[m])
            m = i;
    }
    if (n - 1 == -1) n = 1;
    // printf("B %d %d %d %d\n", arr[m], arr[n-1], m, n-1);
    swap(&arr[n-1], &arr[m]);
    // printf("A %d %d %d %d\n", arr[m], arr[n-1], m, n-1);
    // printArr(arr, n);
    return n-1;
}

void insert(int val, int pos, int n, int *arr) {
    for (int c = 0; c <= pos; c++)
        arr[c] = arr[c + 1];
    arr[pos] = val;
}

int main()
{
    int size1, size2, n_1, n_2;
    scanf("%d %d", &size1, &size2);
    // int arr1[size1], arr2[size2], arr3[size1+size2];
    int *arr1 = (int*)malloc(size1*sizeof(int));
    int *arr2 = (int*)malloc(size2*sizeof(int));
    int *arr3 = (int*)malloc((size1+size2)*sizeof(int));

    // filling array
    srand(time(NULL));

    for (int i = 0; i < size1; i++)
    {
        arr1[i] = (rand() % (10 - 1 + 1)) + 1;
    }

    for (int i = 0; i < size2; i++)
    {
        arr2[i] = (rand() % (10 - 1 + 1)) + 1;
    }

    n_1 = size1;
    n_2 = size2;

    printf("ARR_1: "); printArr(arr1, size1);
    printf("ARR_2: "); printArr(arr2, size2);

    int i = size1+size2-1;
    while (n_1 > 0)
    {
        int max_1 = max_elem(arr1, n_1);
        arr3[i] = arr1[max_1];
        n_1--;
        i--;
    }
    int last_i = i;
    i = size1+size2-1;
    while (n_2 > 0)
    {
        int max_2 = max_elem(arr2, n_2);
        for (int j = i; j >= 0; j--)
        {
            if (arr2[max_2] >= arr3[j])
            {
                insert(arr2[max_2], j, size1+size2, arr3);
                printArr(arr3, size1+size2);
                break;
            }
        }
        n_2--;
        i--;
    }

    printf("ARR_3: "); printArr(arr3, size1+size2);
}