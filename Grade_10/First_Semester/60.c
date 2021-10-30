#include <stdio.h>
#include <math.h>

int main()
{
    double s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    // s1 - from high to low
    // s2 - from low to high
    // s3 - from high to low sep pos and neg
    // s4 - from low to high sep pos and neg
    for (int n = 1; n <= 10000; n++)
        s2 += pow(-1, (double)n) / (double)n;
    for (int n = 10000; n >= 1; n--)
        s1 += pow(-1, (double)n) / (double)n;
    for (int n = 1; n <= 10000; n += 2)
        s4 += pow(-1, (double)n) / (double)n;
    for (int n = 2; n <= 10000; n += 2)
        s4 += pow(-1, (double)n) / (double)n;
    for (int n = 10000; n >= 1; n -= 2)
        s3 += pow(-1, (double)n) / (double)n;
    for (int n = 9999; n >= 1; n -= 2)
        s3 += pow(-1, (double)n) / (double)n;
    printf("%.17lf\n%.17lf\n%.17lf\n%.17lf\n", s1, s2, s3, s4);
    return 0;
}