#include <stdio.h>

int main()
{
    
    int num, n, m=-9999;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if(num > m) m = num;
    }
    printf("%d\n", m);       
}
