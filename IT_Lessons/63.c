#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *a = (int*)malloc(sizeof(int));
    // *a = 123456789;
    char *b = a;
    for (int i = 0; i < 10; i++)
    {
        b[i] = (char*)(i + 1);
    }
    printf("%s\n", *b);
    return 0;
}