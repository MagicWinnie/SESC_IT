#include <stdio.h>

int main()
{
    int i = 1, n = 1;
    while (1)
    {
        n = i*i;
        if (n > 100) break;
        printf("%d ", n);
        i++;
    }

    printf("\n");
        
}