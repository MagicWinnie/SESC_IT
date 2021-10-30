#include <stdio.h>

int main()
{
    int a, b, c, d, max1, max2, max3;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    max1 = (a > b) ? a : b;
    max2 = (c > d) ? c : d;
    max3 = (max1 > max2) ? max1 : max2;
    printf("%d\n", max3);
    return 0;
}