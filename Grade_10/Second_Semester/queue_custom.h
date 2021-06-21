// 
#pragma once
template <class T>
class QueueClass
{
private:
    struct list
    {
        T data;
        struct list *next;
    };
    typedef struct stack
    {
        struct list *top;
        struct list *bottom;
    } Stack;
    Stack *S;

public:
    QueueClass()
    {
        S = new Stack;
        S->top = NULL;
        S->bottom = NULL;
    }
    T top()
    {
        if (S->top)
            return (S->top->data);
        else
            throw "[IndexError] Stack is empty. Cannot get the top."; // return 0; // or raise an error, 'cause the stack is empty
    }
    T pop()
    {
        T a;
        struct list *p;
        p = S->top;
        a = p->data;
        S->top = p->next;
        delete[] p;
        return a;
    }
    void push(T a)
    {
        struct list *p = new struct list;
        p->data = a;
        p->next = NULL;
        if (!(S->top))
        {
            S->top = p;
            S->bottom = p;
            return;
        }
        S->bottom->next = p;
        S->bottom = p;
    }
    bool empty()
    {
        return (S->top == NULL);
    }
    ~QueueClass()
    {
        struct list *p;
        while (S->top)
        {
            p = S->top;
            S->top = p->next;
            delete[] p;
        }
        delete[] S;
    }
};