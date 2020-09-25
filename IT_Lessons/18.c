#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, d;
    scanf("%lf %lf %lf", &a, &b, &c);
    
    d = sqrt(b*b - 4*a*c);

    if (d < 0)
    {
        printf("Корней нет");
        return 0;
    } else if (d == 0)
    {
        printf("%lf", (double)(-b/(2*a)));
    } else 
    {
        printf("%lf\n", (double)((-b+d)/(2*a)));
        printf("%lf", (double)((-b-d)/(2*a)));
    }
        
    printf("\n");
        
}