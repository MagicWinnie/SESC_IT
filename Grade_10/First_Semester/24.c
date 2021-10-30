#include <stdio.h>

int main()
{
    int i = 1, n = 1;
    while (n <= 100)
    {
        n = i * i;
        printf("%d ", n);
        i++;
    }
    printf("\n");
    return 0;
}