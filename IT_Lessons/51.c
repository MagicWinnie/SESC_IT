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

int main()
{
    int size1, size2, temp = 0, maxV = -15, maxV2 = 15, maxI = 0, maxI2 = 0;
    scanf("%d %d", &size1, &size2);
    int arr1[size1], arr2[size2], arr3[size1+size2];

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

    for (int i = 0; i < size1+size2; i++)
    {
        arr3[i] = 0;
    }

    printArr(arr1, size1);
    printArr(arr2, size2);

    

    printArr(arr3, size1+size2);
}