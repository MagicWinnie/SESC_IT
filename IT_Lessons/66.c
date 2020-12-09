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

struct list *mergeList(struct list *a, struct list *b) 
{ 
    struct list *res = NULL; 
  
    if (a == NULL) return b; 
    else if (b == NULL) return a; 
  
    if (a->val <= b->val)
    { 
        res = a; 
        res->next = mergeList(a->next, b); 
    } else { 
        res = b; 
        res->next = mergeList(a, b->next); 
    } 
    return res; 
} 

void *splitList(struct list *head, struct list **f, struct list **e)
{
    struct list* q; 
    struct list* s; 
    s = head; 
    q = head->next; 
  
    while (q != NULL) { 
        q = q->next; 
        if (q != NULL) { 
            s = s->next; 
            q = q->next; 
        } 
    } 
  
    *f = head; 
    *e = s->next; 
    s->next = NULL; 
}

struct list *sortList(struct list *head)
{    
    struct list *a;
    struct list *b;
    struct list *temp = head;

    if (temp == NULL || temp->next == NULL) return temp;

    splitList(temp, &a, &b);

    struct list *new_a = sortList(a);
    struct list *new_b = sortList(b);

    return mergeList(new_a, new_b);
}

int isCycled(struct list *head)
{   
    if (head == NULL || head->next == NULL)
        return -1;
    struct list *slow = head;
    struct list *fast = head;
    
    int ind = 0;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
 
        if (slow == fast) return ind;
        ind++;
    }
    return -1;
}

int main()
{
    struct list *head = NULL;
    head = add2front(head, -1);
    head = add2end(head, 10);
    head = add2front(head, 2);
    head = add2front(head, 1);
    print_list(head);
    head = add2end(head, 3);
    head = add2end(head, 4);
    head = deleteVal(head, 2);
    print_list(head);
    head = addVal(head, 12, 2);
    head = addVal(head, 0, 4);
    print_list(head);
    head = sortList(head);
    print_list(head);
    head->next->next->next->next = head->next->next->next;
    printf("%d\n", isCycled(head));
    deleteAll(head);
    return 0;
}
