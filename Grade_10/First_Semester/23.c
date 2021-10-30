#include <stdio.h>

int main()
{
    int i = 0, n = 1;
    while (1)
    {
        n += i;
        if (n > 100)
            break;
        printf("%d ", n);
        i++;
    }
    printf("\n");
    return 0;
}