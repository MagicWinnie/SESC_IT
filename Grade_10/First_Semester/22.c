#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getNextArr(unsigned long long arr[], unsigned size)
{
    unsigned long long *tempArr = (unsigned long long*)malloc(size * sizeof(unsigned long long));
    for (int i = 0; i < size; i++) tempArr[i] = arr[i];

    unsigned long long newLen = size + 9;
    for (int i = 0; i < newLen; i++) arr[i] = 0;

    for (int i = 0; i < newLen; i++)
    {
        unsigned long long q = 0;
        for (int j = 0; j < 10; j++)
            if (i - j >= 0 && i - j < size) q += tempArr[i - j];
        arr[i] = q;
    }
}

unsigned long long luckyTickets(int n)
{
    unsigned long long *arr = (unsigned long long*)malloc(10 * sizeof(unsigned long long));
    for (unsigned long long i = 0; i < 10; i++) arr[i] = 1;

    unsigned long long result = 0;
    unsigned size = 10;
    
    for (int i = 0; i < n / 2 - 1; i++)
    {   
        arr = (unsigned long long*)realloc(arr, (size + 9) * sizeof(unsigned long long));
        getNextArr(arr, size);
        size += 9;
    }

    for (int i = 0; i < size; i++)
        result += arr[i] * arr[i];
    return result;
}

int main()
{
    int n;

    scanf("%d", &n);

    if (n % 2 != 0) { printf("n must be even\n"); return 0; }

    printf("%llu\n", luckyTickets(n));
    return 0;
}
