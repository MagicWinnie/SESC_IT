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
    swap(&arr[n-1], &arr[m]);
    return n-1;
}

void insert(int val, int pos, int n, int *arr) {
    for (int c = 0; c <= pos; c++)
        arr[c] = arr[c + 1];
    arr[pos] = val;
}

int main()
{
    int size1 = 9;
    int size2 = 5;
    int size3 = size1 + size2;
    
    int arr1[] = {7, 3, 7, 5, 2, 3, 10, 3, 1};
    int arr2[] = {8, 8, 1, 5, 11};

    int *arr3 = (int*)calloc(size3, sizeof(int));

    int n_1 = size1;
    int n_2 = size2;

    printf("ARR_1: "); printArr(arr1, size1);
    printf("ARR_2: "); printArr(arr2, size2);

    int i = size3 - 1;

    while (n_1 > 0)
    {
        int max_1 = max_elem(arr1, n_1);
        arr3[i] = arr1[max_1];
        n_1--;
        i--;
    }
    
    int last_i = i;
    i = size3 - 1;
    
    while (n_2 > 0)
    {
        int max_2 = max_elem(arr2, n_2);
        for (int j = i; j >= 0; j--)
        {
            if (arr2[max_2] >= arr3[j])
            {
                insert(arr2[max_2], j, size3, arr3);
                break;
            }
        }
        n_2--;
        i--;
    }

    printf("ARR_3: "); printArr(arr3, size3);
}