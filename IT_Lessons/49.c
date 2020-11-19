#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int size = 10, count = 0;
    int arr[size];

    // filling array
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % (10 - 1 + 1)) + 1;
    }

    for (int i = 0; i < size-1; i++)
        if (arr[i] > arr[i+1]) count++;

    //printing array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n%d\n", count);
}