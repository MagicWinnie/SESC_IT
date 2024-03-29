#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int size = 10;
    int arr[size];

    int sum = 0, mul = 1;

    // filling array
    srand(time(NULL));

    for (int i = 0; i < size; i++)
        arr[i] = (rand() % (10 - 1 + 1)) + 1;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        mul *= arr[i];
    }

    //printing array
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\nArithmetic mean: %lf\n", (double)sum / size);
    printf("Geometric mean: %lf\n", pow((double)mul, (double)1 / size));
    return 0;
}