#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct list
{
    int val;
    struct list *next;
};

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
  
    if (a->val >= b->val)
    { 
        res = a; 
        res->next = mergeList(a->next, b); 
    } else { 
        res = b; 
        res->next = mergeList(a, b->next); 
    } 
    return res; 
}

int main()
{
    list *head_1 = nullptr, *head_2 = nullptr, *head = nullptr;
    
    int n, m, temp;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        head_1 = add2front(head_1, temp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        head_2 = add2front(head_2, temp);
    }
    
    // cout << "MERGING" << endl;
    head = mergeList(head_1, head_2);
    // cout << "HEAD: ";
    print_list(head);

    deleteAll(head);
}