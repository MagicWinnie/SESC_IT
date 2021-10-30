#include <stdio.h>
#include <stdlib.h>

struct list
{
    int val;
    struct list *next;
};

void print_list(struct list *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void deleteAll(struct list *head)
{
    struct list *curr = head;
    while (head != NULL)
    {
        head = head->next;
        free(curr);
        curr = head;
    }
}

struct list *add2front(struct list *head, int val)
{
    struct list *new = (struct list *)malloc(sizeof(struct list));
    new->val = val;
    struct list *temp = head;
    new->next = temp;
    return new;
}

struct list *path = NULL;

void DFS(int **arr, int v, int n)
{
    arr[v][v] = 1;
    for (int i = 0; i < n; i++)
        if (arr[v][i] == 1 && !arr[i][i])
            DFS(arr, i, n);
    path = add2front(path, v);
}

int main()
{
    int n;
    scanf("%d", &n);

    int **arr = (int **)calloc(n, sizeof(int *));

    for (int i = 0; i < n; i++)
        arr[i] = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    for (int i = 0; i < n; i++)
        if (!arr[i][i])
            DFS(arr, i, n);

    print_list(path);
    deleteAll(path);
    return 0;
}

/*
6
0 1 1 0 0 0 
1 0 0 1 0 0 
1 0 0 1 0 0 
0 1 1 0 0 0 
0 0 0 0 0 1 
0 0 0 0 1 0 
*/