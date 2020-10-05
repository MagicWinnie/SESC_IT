#include <stdio.h>

int main()
{
    int n, d = 1;
    scanf("%d", &n);
    while (d*d <= n){
        if (n%d == 0) printf("%d %d ", d, n/d);
        d++;
    }
    printf("\n");
}