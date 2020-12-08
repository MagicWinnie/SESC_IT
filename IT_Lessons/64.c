#include <stdio.h>
#include <stdlib.h>

void print(unsigned long long *arr, int n)
{
    printf("-------------------\n");
    for (int j = 0; j < n; j++)
        printf("%d ", arr[j]);
    printf("\n-------------------\n");
}

int main()
{
    int n, k;
    
    FILE *fin = fopen("64.txt", "r");
    FILE *fout = fopen("64.out", "w");

    fscanf(fin, "%d %d", &n, &k);
    fclose(fin);

    unsigned long long* arr = (unsigned long long*)calloc(n + 1, sizeof(unsigned long long));

    if (k > n)
    {
        fprintf(fout, "K cannot be greater than N\n");
        return -1;
    }
    if (k < 0 || n <= 0)
    {
        fprintf(fout, "K or N cannot be lower than 0\n");
        return -1;
    }
    if (k == 0 || k == n) fprintf(fout, "1\n");
    else {
        arr[0] = 1;
        for (int j = 1; j <= n; j++)
        {
            for (int i = j; i >= 1; i--)
                arr[i] = arr[i - 1] + arr[i];
            // print(arr, n + 1);
        }
        fprintf(fout, "%llu\n", arr[k]);
    }
    fclose(fout);
    free(arr);
    return 0;
}