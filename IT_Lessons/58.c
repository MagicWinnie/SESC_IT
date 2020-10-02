#include <stdio.h>
#include <stdbool.h>

void sieveEratos(int n)
{
    bool a[n+1];
    for (int i = 0; i <= n; i++)
        a[i] = true;
    for (int i = 2; i*i <= n; i++)
    {
        if (a[i])
        {
            int j = 0, k = 0;
            for (int j = i*i; j<=n; j+=i)
                a[j] = false;            
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (a[i] == true){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    sieveEratos(n);
}
