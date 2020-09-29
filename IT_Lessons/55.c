#include <stdio.h>
#include <math.h>

int main()
{
    int size = 5, a, j;
    int arr[] = {5, 1, 4, 3, 6};

    for (int i = 1; i < size; i++)
    {
        a = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > a)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = a;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}