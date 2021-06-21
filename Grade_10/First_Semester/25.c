#include <stdio.h>

int main()
{
    int i = 1, n = 1;
    printf("%d ", 1);
    while (n <= 100)
    {
        if (i%2 == 0)
            n = n*2;
        else
            n = n+1;
        printf("%d ", n);
        i++;
    }

    printf("\n");
        
}