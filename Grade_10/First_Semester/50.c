#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int size1, size2, count = 0;
    scanf("%d %d", &size1, &size2);
    int *arr1 = (int *)malloc(size1 * sizeof(int));
    int *arr2 = (int *)malloc(size2 * sizeof(int));
    int *arr3 = (int *)malloc((size1 + size2) * sizeof(int));

    // filling array
    srand(time(NULL));

    for (int i = 0; i < size1; i++)
        arr1[i] = (rand() % (10 - 1 + 1)) + 1;
    for (int i = 0; i < size2; i++)
        arr2[i] = (rand() % (10 - 1 + 1)) + 1;

    printArr(arr1, size1);
    printArr(arr2, size2);

    for (int i = 0; i < size1; i++)
        arr3[i] = arr1[i];

    for (int i = 0; i < size2; i++)
        arr3[i + size1] = arr2[i];

    printArr(arr3, size1 + size2);
    return 0;
}