#include <stdio.h>
#include <stdlib.h>

struct list
{
    int val;
    struct list *next;
    struct list *prev;
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

int len(struct list *head){
    int count = 0;
    while (head != NULL){
        head = head->next;
        count++;
    }
    return count;
}

struct list *add2front(struct list *head, int val)
{
    if (head == NULL)
    {
        struct list *lst = (struct list*)malloc(sizeof(struct list));
        lst->val = val;
        lst->next = NULL;
        lst->prev = NULL;
        return lst;
    }
    struct list *new = (struct list*)malloc(sizeof(struct list));
    new->val = val;
    new->prev = NULL;
    new->next = head;
    head->prev = new;
    return new;
}

struct list *add2end(struct list *head, int val)
{
    if (head == NULL)
    {
        struct list *lst = (struct list*)malloc(sizeof(struct list));
        lst->val = val;
        lst->next = NULL;
        lst->prev = NULL;
        return lst;
    }

    struct list *temp = head;
    struct list *h = (struct list*)malloc(sizeof(struct list));
    
    h->val = val;
    h->next = NULL;
    for(int i = 0; i < len(head) && temp->next != NULL; i++)
        temp = temp->next;
    temp->next = h;
    h->prev = temp;
    return head;
}

struct list *addVal(struct list *head, int val, int ind)
{
    if(head == NULL){
        struct list *h = (struct list*)malloc(sizeof(struct list));
        h->val = val;
        h->next = NULL;
        h->prev = NULL;
        return h;
    }
    struct list *temp, *elem;
    elem = head;
    for (int i = 0; i < ind; i++)
        elem = elem->next;

    temp = (struct list*)malloc(sizeof(struct list));
    temp->val = val;
    elem->prev->next = temp;
    temp->prev = elem->prev;
    elem->prev = temp;
    temp->next = elem;
    return head;
}

struct list *deleteVal(struct list *head, int val)
{
    struct list *temp = head;
    if (temp->val == val)
    {
        head = temp->next;
        free(temp);
        head->prev = NULL;
        return head;
    }
    while (temp->next != NULL && temp->next->val != val)
        temp = temp->next; 
    if (temp->next == NULL) return head;
    struct list *temp_next = temp->next->next;
    temp_next->prev = temp->prev;
    free(temp->next);
    temp->next = temp_next;
    return head;
}

struct list* merge(struct list* a, struct list* b)
{
    if (a == NULL) return b;
 
    if (b == NULL) return a;
 
    if (a->val <= b->val)
    {
        a->next = merge(a->next, b);
        a->next->prev = a;
        a->prev = NULL;
        return a;
    }
    else
    {
        b->next = merge(a, b->next);
        b->next->prev = b;
        b->prev = NULL;
        return b;
    }
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

    return merge(new_a, new_b);
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
    head = add2front(head, 5);
    head = add2front(head, 4);
    head = add2front(head, 3);
    head = add2front(head, 2);
    head = add2front(head, 1);
    head = add2end(head, 0);
    head = addVal(head, 22, 2);
    print_list(head);
    head = deleteVal(head, 22);
    head = addVal(head, 44, 2);
    print_list(head);
    head = sortList(head);
    print_list(head);
    // head->next->next->next->next = head->next->next->next;
    // printf("%d\n", isCycled(head));
    deleteAll(head);
    return 0;
}
