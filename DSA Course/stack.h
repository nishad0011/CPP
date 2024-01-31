#include <iostream>
using namespace std;
#ifndef stack_h
#define stack_h

struct stack
{
    int size;
    int top;
    int *s;
};

void StackInit(struct stack *S, int size)
{
    S->size = size;
    S->s = new int[S->size];
    S->top = -1;
}

int IsFull(struct stack *S)
{
    if (S->top < S->size - 1)
        return 0;
    else
        return 1;
}

int IsEmpty(struct stack *S)
{
    if (S->top == -1)
        return 1;
    else
        return 0;
}

void push(int element, struct stack *S)
{
    if (IsFull(S))
        cout << "Stack is full..." << endl;
    else
    {
        S->top++;
        S->s[S->top] = element;
    }
}

int pop(struct stack *S)
{
    if (IsEmpty(S))
        cout << "Stack is empty" << endl;
    else
    {
        int element = S->s[S->top];
        S->top--;
        return element;
    }
    return 0;
}

void display(struct stack *S)
{
    if (IsEmpty(S))
        cout << "Stack is empty..." << endl;
    else
    {
        cout << "STACK :";
        for (int i = 0; i <= S->top; i++)
        {
            cout << S->s[i] << " ";
        }
        cout << endl;
    }
}
#endif