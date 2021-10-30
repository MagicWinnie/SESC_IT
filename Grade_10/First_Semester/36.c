#include <stdio.h>

int conjunction(int a, int b)
{
    return a & b;
}

int disjunction(int a, int b)
{
    return a | b;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", conjunction(a, b), disjunction(a, b));
    return 0;
}