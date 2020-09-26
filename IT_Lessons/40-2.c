// #include <stdio.h>
// #include <stdint.h>
// #include <math.h>


// unsigned long long int factorial(int n)
// {
//     if (n == 0)
//         return 1;
//     unsigned long long int res = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         res *= i;
//     }
//     return res; 
// } 

// int main()
// {
//     double x, res = 0;
//     int n;
//     scanf("%lf %d", &x, &n);

//     for (int i = 0; i < n; i++)
//     {
//         res += (double)pow(x, i)/(double)factorial(i);
//     }

//     printf("%lf", res);
// }