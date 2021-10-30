#include <iostream>

using namespace std;

struct list
{
    int val;
    int edge = 0;
    struct list *next;
    struct list *prev;
};

void deleteAll(list *head)
{
    if (head != NULL)
    {    
        list *temp, *current;
        current = head->next;
        
        while(current != head)
        {
            temp = current->next;
            delete[] current;
            current = temp;
        }

        delete[] head;
        head = NULL;
    }
}

list *get_pointer(list *head, int ind)
{
    if (!head)
        return head;

    list *elem;
    elem = head;
    for (int i = 0; i < ind; i++)
        elem = elem->next;
    return elem;
}

list *add2front(list *head, int val)
{
    list *new_node = new list;
    new_node->val = val;
 
    new_node->next = head;
    new_node->prev = nullptr;
 
    if (head)
        head->prev = new_node;
         
    return new_node;
}

int main()
{
    list *head = NULL;
 
    int n, k, curr_size = 0;
    cin >> n >> k;

    for (int i = n; i >= 1; i--) { head = add2front(head, i); curr_size++; }

    list *end_pointer = get_pointer(head, curr_size - 1);
    
    end_pointer->next = head;
    head->prev = end_pointer;
    head->edge = 1;
    
    list *curr_pointer = get_pointer(head, k - 1);
    while (true)
    {
        if (curr_size <= 1)
            break;

        list *del = new list;
        del = curr_pointer;

        del->prev->next = del->next;
        del->next->prev = del->prev;

        if (curr_pointer->edge == 1)
        {
            head = curr_pointer->next;
            head->edge = 1;
        }

        delete[] del;
        curr_size--;

        for(int i = 0; i < k; i++)
            curr_pointer = curr_pointer->next;
    }

    cout << head->val << '\n';
    deleteAll(head);
    delete[] end_pointer;
}  