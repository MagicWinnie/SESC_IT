#include <stdio.h>

int main()
{
    int arr[30] = {1};
    for (int i = 1; i < 30; i++)
        arr[i] = 2 * arr[i - 1];
    for (int i = 0; i < 30; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}