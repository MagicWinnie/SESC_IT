#include <stdio.h>
#include <stdlib.h>

void reverse_array(int a[], int n)
{
    int c, t;

    for (c = 0; c < n / 2; c++) {
        t = a[c];
        a[c] = a[n - c - 1];
        a[n - c - 1] = t;
    }
}

void DFS(int **arr, int *path, int v, int size, int n)
{
    arr[v][v] = 1;
	for (int i = 0; i < n; i++)
    {
		int to = arr[v][i];
		if (!arr[to][to])
			DFS(arr, path, to, size, n);
	}
    path[size] = v;
}
 
void topological_sort(int **arr, int n)
{
    int *path = (int*)calloc(1, sizeof(int));
    int size = 1;

	for (int i = 0; i < n; i++)
		if (!arr[i][i])
        {
			DFS(arr, path, i, size, n);
            size++;
            path = (int*)realloc(path, size * sizeof(int));
        }
    
	reverse_array(path, size);
    for (int i = 0; i < size; i++) printf("%d ", path[i]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int **arr = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) arr[i] = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    topological_sort(arr, n);

    return 0;
}

/*
6
0 1 1 0 0 0 
1 0 1 1 0 1 
1 1 0 0 1 0 
0 1 0 0 1 0 
0 0 1 1 0 1 
0 1 0 0 1 0 
*/