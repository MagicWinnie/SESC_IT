#include <stdio.h>
#include <stdlib.h>

void bubble(int *arr, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int a = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = a;
            }
        }
    }
}

int main()
{
    int n, d = 1, i = 0;
    int *delit = (int*)malloc(sizeof(int)); 

    scanf("%d", &n);
    while (d*d <= n){
        if (n%d == 0)
        {
            if (d == n/d) 
            {
                delit[i] = d;
                i++;
                delit = (int*)realloc(delit, (i+1)*sizeof(int));
            }
            else
            {
                delit[i] = d;
                i++;
                delit = (int*)realloc(delit, (i+1)*sizeof(int));
                delit[i] = n/d;
                i++;
                delit = (int*)realloc(delit, (i+1)*sizeof(int));
            } 
        }
        d++;
    }
    bubble(delit, i);
    for (int j = 0; j < i; j++)
        printf("%d ", delit[j]);   
    printf("\n");
    return 0;
}