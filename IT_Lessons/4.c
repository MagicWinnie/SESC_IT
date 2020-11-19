#include <stdio.h>

int main()
{
    int n, d = 1;
    scanf("%d", &n);
    while (d*d <= n){
        if (n%d == 0)
        {
            if (d == n/d) printf("%d ", d);
            else printf("%d %d ", d, n/d);
            // if (n % d == 0)
            //     printf("%d ", d);
            // if (n % (n/d) == 0)
            //     printf("%d ", n/d);
        }
        d++;
    }
    printf("\n");
}