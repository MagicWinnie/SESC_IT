#include <stdio.h>
#include <math.h>

int main()
{
    int size = 5, n, a;
    int arr[] = {1, 2, 3, 4, 5};

    scanf("%d", &n);

    if (n < 0) {
        for (int i = 0; i < abs(n); i++)
        {
            a = arr[0];
            for (int j = 0; j < size-1; j++) 
                arr[j] = arr[j+1];
            arr[size-1] = a;
        }
    } else {
        for (int i = 0; i < n; i++)
        {
            a = arr[size-1];
            for (int j = size-1; j > 0; j--) 
                arr[j] = arr[j-1];
            arr[0] = a;
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
