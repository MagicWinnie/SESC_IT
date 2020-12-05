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
    struct list *new = (struct list*)malloc(sizeof(struct list));
    new->val = val;
    struct list *temp = head;
    new->next = temp;
    return new;
}

struct list *add2end(struct list *head, int val)
{
    if (head == NULL)
    {
        head = (struct list*)malloc(sizeof(struct list));
        head->val = val;
        head->next = NULL;
        return head;
    }

    struct list *temp = head;
    struct list *new = (struct list*)malloc(sizeof(struct list));
    
    new->val = val;
    new->next = NULL;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
    return head;
}

struct list *addVal(struct list *head, int num, int ind)
{
    struct list *temp, *left, *right;
    right = head;
    for (int i = 0; i < ind; i++)
    {
        left=right;
        right=right->next;
    }
    temp = (struct list*)malloc(sizeof(struct list));
    temp->val = num;
    left->next = temp;
    left = temp;
    left->next = right;
    return head;
}

struct list *deleteVal(struct list *head, int val)
{
    struct list *temp = head;
    if (temp->val == val)
    {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp->next != NULL && temp->next->val != val)
        temp = temp->next; 
    if (temp->next == NULL) return head;
    struct list *temp_next = temp->next->next;
    free(temp->next);
    temp->next = temp_next;
    return head;
}

struct list *sortList(struct list *head)
{
    
}

int isCycled(struct list *head)
{

}

int main()
{
    struct list *head = NULL;
    head = add2end(head, 10);
    head = add2front(head, 2);
    head = add2front(head, 1);
    print_list(head);
    head = add2end(head, 3);
    head = add2end(head, 4);
    head = deleteVal(head, 2);
    print_list(head);
    head = addVal(head, 12, 2);
    print_list(head);
    deleteAll(head);
    return 0;
}