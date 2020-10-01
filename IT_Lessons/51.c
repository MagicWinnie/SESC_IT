#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size = 10, temp = 0, maxV = -15, maxV2 = 15, maxI = 0, maxI2 = 0;
    int arr1[size], arr2[size], arr3[size*2];

    // filling array
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr1[i] = (rand() % (10 - 1 + 1)) + 1;
        arr2[i] = (rand() % (10 - 1 + 1)) + 1;
    }

    for (int i = 0; i < size*2; i++)
    {
        arr3[i] = 0;
    }

    printArr(arr1, size);
    printArr(arr2, size);

    int a = size;

    while (a>1){
        for (int i = 0; i < a; i++)
        {
            if (arr1[i] > maxV){
                maxV = arr1[i];
                maxI = i;
            }
            if (arr2[i] > maxV2){
                maxV2 = arr2[i];
                maxI2 = i;
            }
        }

        temp = arr1[a-1];
        arr1[a-1] = maxV;
        arr1[maxI] = temp;

        temp = arr2[a-1];
        arr2[a-1] = maxV2;
        arr2[maxI2] = temp;

        a--;

        for (int i = size*2-1; i >= 0; i--)
        {
            if (arr3[i] > maxV && arr3[i] > maxV2)
            {
                continue;
            } else if (maxV >= maxV2) {
                temp = arr3[i];
                arr3[i] = maxV;
                arr3[i-2] = temp;

                temp = arr3[i-1];
                arr3[i-1] = maxV2;
                arr3[i-3] = temp;
                break;
            } else {
                temp = arr3[i];
                arr3[i] = maxV2;
                arr3[i-2] = temp;
                
                temp = arr3[i-1];
                arr3[i-1] = maxV;
                arr3[i-3] = temp;
                break;
            }
        }

        maxV = -15;
        maxV2 = -15;
    }

    printArr(arr3, size*2);
}