
#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, d;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a == 0){
        printf("а не может быть равно 0\n"); 
        return 0;
    }
    d = sqrt(b*b - 4*a*c);

    if (d < 0)
    {
        printf("Корней нет\n");
        return 0;
    } else if (d == 0)
    {
        printf("%lf\n", (double)(-b/(2*a)));
    } else 
    {
        printf("%lf\n", (double)((-b+d)/(2*a)));
        printf("%lf\n", (double)((-b-d)/(2*a)));
    }        
}
