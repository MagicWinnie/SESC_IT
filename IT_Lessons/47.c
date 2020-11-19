#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int n = 10;
    int arr[n];
    
    int max=0, min=0;


    // filling array
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % (50 + 50 + 1)) -50;
    }
    //-----

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[max])
            max = i;
        if (arr[i] < arr[min])
            min = i;
    }

    //printing array
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nMax: %d\nMin: %d\n", arr[max], arr[min]);
}