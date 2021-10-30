#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct list
{
    int val;
    struct list *next;
};

bool isPresent(list *head, int val)
{
    list *temp = head;
    if (!temp)
        return false;

    while (temp != nullptr)
    {
        if (temp->val == val)
            return true;
        temp = temp->next; 
    }
    return false;
}

void print_list(list *head)
{
    list *temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
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
    if (!head)
    {
        list *lst = new list;
        lst->val = val;
        lst->next = nullptr;
        return lst;
    }
    list *new_list = new list;
    new_list->val = val;
    new_list->next = head;
    return new_list;
}

int sortingAddInd(list *head, int val)
{
    list *temp = head;
    if (!temp)
        return 0;

    int ind = 0;
    while (temp != nullptr)
    {
        if (temp->val > val)
            return ind;
        temp = temp->next; 
        ind++;
    }
    return ind;
}

list *addVal(list *head, int val, int ind)
{
    if (!head)
    {
        list *h = new list; 
        h->val = val;
        h->next = nullptr;
        return h;
    }
    list *left = new list;
    list *right = head;

    for (int i = 0; i < ind; i++) { left = right; right = right->next; }
    
    list *temp = new list;
    temp->val = val;
    temp->next = right;
    if (ind)
        left->next = temp;
    
    return ((!ind) ? temp : head);
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


int main()
{
    list *head = nullptr;
    
    int num;

    while (cin >> num)
    {
        if (!isPresent(head, num))
            head = addVal(head, num, sortingAddInd(head, num));
    }
    print_list(head);
    deleteAll(head);
}