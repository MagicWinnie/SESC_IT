#include <stdio.h>
#include <math.h>

int main()
{
    int size = 7, a;
    int arr[] = {2, 11, 7, 5, 2, 1, 4, 3};

    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                a = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = a;
            }
        }
    }

    
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
        
    if(size%2==0)
        printf("\n%lf\n", (double)((arr[size/2] + arr[size/2-1])/2.0));
    else
        printf("\n%d\n", arr[size/2]);
}