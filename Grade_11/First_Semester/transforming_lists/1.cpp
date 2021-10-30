#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>

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

list *reverse(list *head)
{
    list *current = head;
    list *prev = NULL, *next = nullptr;

    while (current)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;
    return head;
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


int main()
{
    list *head = nullptr;

    int num, prev;

    cin >> num; 
    head = add2front(head, num);
    prev = num;

    while (cin >> num)
    {
        if (num != prev)
        {
            head = add2front(head, num);
            prev = num;
        }
    }
    head = reverse(head);
    print_list(head);
    deleteAll(head);
}