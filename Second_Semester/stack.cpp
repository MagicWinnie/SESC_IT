// Stack
// It is a linear list in which all inclusions and exclusions are made at one end of the list.
#include <iostream>

using namespace std;

struct list
{
    int data;
    struct list *next;
};
typedef struct stack { struct list *top; } Stack;

void makenull(Stack *S)
{
    struct list *p;
    while (S->top)
    {
        p = S->top;
        S->top = p->next;
        free(p);
    }
}
Stack *create()
{
    Stack *S;
    S = (Stack *)malloc(sizeof(Stack));
    S->top = NULL;
    return S;
}
int top(Stack *S)
{
    if (S->top)
        return (S->top->data);
    else
        throw "[IndexError] Stack is empty. Cannot get the top."; // return 0; // or raise an error, 'cause the stack is empty  
}
int pop(Stack *S)
{
    int a;
    struct list *p;
    p = S->top;
    a = p->data;
    S->top = p->next;
    free(p);
    return a;
}
void push(int a, Stack *S)
{
    struct list *p;
    p = (struct list *)malloc(sizeof(struct list));
    p->data = a;
    p->next = S->top;
    S->top = p;
}
int empty(Stack *S)
{
    return (S->top == NULL);
}

int main()
{

}