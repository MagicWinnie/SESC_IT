#include <stdio.h>
#include <math.h>

int main()
{
    int size = 5, a, b;
    int arr[] = {5, 1, 4, 3, 2};

    for (int i = 0; i < size; i++)
    {
        a = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[a])
                a = j;
        }
        b = arr[i];
        arr[i] = arr[a];
        arr[a] = b;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}