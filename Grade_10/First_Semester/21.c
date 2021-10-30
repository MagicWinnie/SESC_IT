#include <stdio.h>

int main()
{
    int count = 0;

    for (int i = 0; i < 1000000; i++)
    {
        if (i / 100000 + i / 10000 % 10 + i / 1000 % 10 == i % 1000 / 100 + i % 1000 / 10 % 10 + i % 1000 % 10)
            count++;
    }

    printf("%d\n", count);
    return 0;
}