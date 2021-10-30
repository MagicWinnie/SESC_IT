#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct list
{
    int val;
    struct list *next;
};

int counter(list *head)
{
    int count = 0;
    while (head)
    {
        count += (head->val < 0 && head->val % 7 == 0) ? 1 : 0;
        head = head->next;
    }
    return count;
}

void print_list(list *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteAll(list *head)
{
    list *curr = head;
    while (head)
    {
        head = head->next;
        delete[] curr;
        curr = head;
    }
}

list *add2front(list *head, int val)
{
    list *new_struct = new list;
    new_struct->val = val;
    list *temp = head;
    new_struct->next = temp;
    return new_struct;
}

list *add2end(list *head, int val)
{
    if (!head)
    {
        head = new list;
        head->val = val;
        head->next = nullptr;
        return head;
    }

    list *temp = head;
    list *new_struct = new list;
    
    new_struct->val = val;
    new_struct->next = nullptr;
    while (temp->next)
        temp = temp->next;
    temp->next = new_struct;
    return head;
}

list *addVal(list *head, int num, int ind)
{
    list *temp, *left, *right;
    right = head;
    for (int i = 0; i < ind; i++)
    {
        left = right;
        right = right->next;
    }
    temp = new list[1];
    temp->val = num;
    left->next = temp;
    left = temp;
    left->next = right;
    return head;
}

list *deleteVal(list *head, int val)
{
    list *temp = head;
    if (temp->val == val)
    {
        head = temp->next;
        delete[] temp;
        return head;
    }
    while (temp->next != nullptr && temp->next->val != val)
        temp = temp->next; 
    if (!temp->next) return head;
    list *temp_next = temp->next->next;
    delete[] temp->next;
    temp->next = temp_next;
    return head;
}

// MERGE SORT
list *mergeList(list *a, list *b) 
{ 
    list *res = nullptr; 
  
    if (!a) return b; 
    else if (!b) return a; 
  
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

void splitList(list *head, list **f, list **e)
{
    struct list* q; 
    struct list* s; 
    s = head; 
    q = head->next; 
  
    while (q)
    { 
        q = q->next; 
        if (q)
        { 
            s = s->next; 
            q = q->next; 
        } 
    } 
  
    *f = head; 
    *e = s->next; 
    s->next = nullptr; 
}

list *sortList(list *head)
{    
    list *a;
    list *b;
    list *temp = head;

    if (!temp || !temp->next) return temp;

    splitList(temp, &a, &b);

    list *new_a = sortList(a);
    list *new_b = sortList(b);

    return mergeList(new_a, new_b);
}
// MERGESORT

int isCycled(list *head)
{   
    if (!head || !head->next)
        return -1;
    list *slow = head;
    list *fast = head;
    
    int ind = 0;

    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
 
        if (slow == fast) return ind;
        ind++;
    }
    return -1;
}

int main()
{
    list *head = nullptr;
    
    int num;

    while (cin >> num)
        head = add2front(head, num);    
    
    cout << counter(head) << endl;

    // head = add2front(head, -1);
    // head = add2end(head, 10);
    // head = add2front(head, 2);
    // head = add2front(head, 1);

    // print_list(head);
    
    // head = add2end(head, 3);
    // head = add2end(head, 4);
    
    // head = deleteVal(head, 2);
    
    // print_list(head);
    
    // head = addVal(head, 12, 2);
    // head = addVal(head, 0, 4);
    
    // print_list(head);
    
    // head = sortList(head);
    
    // print_list(head);
    
    // head->next->next->next->next = head->next->next->next;
    // cout << isCycled(head) << endl;
    deleteAll(head);
}