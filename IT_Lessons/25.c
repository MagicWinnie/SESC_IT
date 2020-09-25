#include <stdio.h>

int main()
{
    int i = 1, n = 1;
    printf("%d ", 1);
    while (1)
    {
        if (i%2==0)
            n = n*2;
        else
            n = n+1;
        if (n > 100) break;
        printf("%d ", n);
        i++;
    }

    printf("\n");
        
}