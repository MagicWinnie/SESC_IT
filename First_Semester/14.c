#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (a > c) swap(&a, &c);
    if (a > b) swap(&a, &b);
    if (b > c) swap(&b, &c);

    if ((a + b > c) && (b + c > a) && (a + c > b))
    {
        if      (a == b || b == c || a == c) printf("Isosceles\n");
        else if (a == b && b == c)           printf("Equilateral\n");
        if      (c * c == a * a + b * b)     printf("Right\n");
        else if (c * c > a * a + b * b)      printf("Scalene\n");
        else                                 printf("Acute\n");
    } 
    else printf("Impossible\n");        
}
