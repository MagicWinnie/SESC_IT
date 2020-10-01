#include <stdio.h>
#include <stdlib.h>
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

int main()
{
    int size = 10, count = 0;
    int arr1[size], arr2[size], arr3[size*2];

    // filling array
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr1[i] = (rand() % (10 - 1 + 1)) + 1;
        arr2[i] = (rand() % (10 - 1 + 1)) + 1;
    }

    printArr(arr1, size);
    printArr(arr2, size);

    for (int i = 0; i < size; i++)
    {
        arr3[i] = arr1[i];
        arr3[i+size] = arr2[i];
    }
    
    printArr(arr3, size*2);
}