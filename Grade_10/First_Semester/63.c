#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int *a = (int *)malloc(sizeof(int));
    char *b = a;
    // *(b + 0) = 21;
    // *(b + 1) = 205;
    // *(b + 2) = 91;
    // *(b + 3) = 7;
    int last = 123456789;
    for (int i = 0; i < 4; i++)
    {
        *(b + i) = last % 256;
        last /= 256;
    }
    printf("%d\n", *a);
    return 0;
}
// 123456789 -   7 * 2^24 = 6016277
// 6016277   -  91 * 2^16 = 52501
// 52501     - 205 * 2^8  = 21