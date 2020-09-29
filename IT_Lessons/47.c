#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int arr[10];
    
    int max=-51, min=51;


    // filling array
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        arr[i] = (rand() % (50 + 50 + 1)) -50;
    }


    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    //printing array
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nMax: %d\nMin: %d\n", max, min);
}