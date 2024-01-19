#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *s;
};

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

int main()
{
    struct stack st;
    st.size = 5;
    st.s = new int[st.size];
    st.top = -1;

    display(&st);

    push(10, &st);
    push(20, &st);
    push(30, &st);
    push(40, &st);
    push(50, &st);
    push(60, &st);
    push(70, &st);

    display(&st);
    return 0;
}