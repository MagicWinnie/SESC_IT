// Stack is a linear list in which all inclusions and exclusions are made at one end of the list.
#pragma once
template <class T>
class StackClass
{
    private:
        struct list
        {
            T data;
            struct list *next;
        };
        typedef struct stack { struct list *top; } Stack;
        Stack *S;
    public:
        StackClass()
        {
            S = new Stack; // (Stack *)malloc(sizeof(Stack));
            S->top = NULL;
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
            struct list *p;
            p = new struct list; // (struct list *)malloc(sizeof(struct list));
            p->data = a;
            p->next = S->top;
            S->top = p;
        }
        bool empty()
        {
            return (S->top == NULL);
        }
        ~StackClass()
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