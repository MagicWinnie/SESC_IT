#include <stdio.h>

int main()
{

    int arr[100];

    for (int i = 0; i < 100; i++)
    {
        arr[i] = i+1;
    }

    for (int i = 0; i < 100; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}