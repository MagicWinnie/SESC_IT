#include <stdio.h>
#include <math.h>

int main()
{
    int size = 5, a;
    int arr[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < size/2; i++)
    {
        a = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = a;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}