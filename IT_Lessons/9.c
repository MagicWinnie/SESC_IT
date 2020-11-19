#include <stdio.h>

int main()
{
    int a, b, c, d, max1, max2, max3;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a > b) max1 = a;
    else max1 = b;

    if (c > d) max2 = c;
    else max2 = d;
    
    if (max1 > max2) max3 = max1;
    else max3 = max2;
    printf("%d\n", max3);
}

