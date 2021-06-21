
#include <stdio.h>
#include <math.h>

int main()
{
    // ax^2 + bx + c = 0
    double a, b, c, d;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a == 0)
    {
        // bx = -c
        // x = -c/b
        if (b == 0 && c == 0) printf("Infinite number of solutions\n");
        else if (b == 0 && c != 0) printf("No solutions\n");
        else if (b != 0 && c == 0) printf("0\n");
        else if (b != 0 && c != 0) printf("%lf\n", -c/b);
        return 0;
    }
    if (b == 0)
    {
        // ax^2 + c = 0
        // ax^2 = -c
        if (a < 0) printf("%lf\n", sqrt(c/a));
        else printf("No real solutions\n");
        return 0;
    }
    d = b*b - 4*a*c;
    if (d < 0)
    {
        printf("No real solutions\n");
        return 0;
    }
    d = sqrt(d);
    if (d == 0)
    {
        printf("%lf\n", (double)(-b/(2*a)));
    } else 
    {
        printf("%lf\n", (double)((-b+d)/(2*a)));
        printf("%lf\n", (double)((-b-d)/(2*a)));
    }        
    return 0;
}
