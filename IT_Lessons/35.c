#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int sum(int a, int b) 
{ 
    int temp;
    while (b != 0) 
    { 
        temp = a & b;   
        a = a ^ b;  
        b = temp << 1; 
    } 
    return a; 
}

int sub(int a, int b) 
{ 
    int temp;
    while (b != 0) 
    { 
        temp = (~a) & b;   
        a = a ^ b;  
        b = temp << 1; 
    } 
    return a; 
}

int mul(int a, int b) 
{ 
    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1; 
    int res = 0; 

    a = abs(a);
    b = abs(b);
    
    while (b > 0) 
    { 
        if (b & 1) 
            res = sum(res, a);
        a = a << 1; 
        b = b >> 1; 
    } 
    return sign*res; 
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", sum(a, b));
    printf("%d\n", sub(a, b));
    printf("%d\n", mul(a, b));
}