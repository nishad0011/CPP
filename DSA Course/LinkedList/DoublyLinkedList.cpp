#include <iostream>
using namespace std;
struct DNode
{
    int data;
    struct DNode *prev;
    struct DNode *next;
} *first = NULL;

void create(int A[], int length)
{
    struct DNode *t, *last;
    first = new struct DNode;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (int i = 1; i < length; i++)
    {
        t = new struct DNode;
        t->data = A[i];
        last->next = t;
        t->prev = last;
        t->next = NULL;
        last = last->next;
    }
}

void display(struct DNode *p)
{
    while (p != NULL)
    {
        cout << p->data;
        if (p->next != NULL)
        {
            cout << " - ";
        }
        p = p->next;
    }
    cout << endl;
}

void insert(int element, int index)
{
    struct DNode *t, *p, *q;
    p = first;

    t = new struct DNode;
    t->data = element;
    t->next = t->prev = NULL;

    if (index == 0)
    {
        p->prev = t;
        t->next = p;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            if (p->next)
                p = p->next;
        }
        q = p->next;
        p->next = t;
        t->prev = p;
        if (q)
        {
            t->next = q;
            q->prev = t;
        }
    }
}
int main()
{
    int A[] = {10, 20, 25, 30, 40, 50, 60, 70};
    int len = sizeof(A) / sizeof(A[0]);

    create(A, len);
    display(first);
    insert(100, 8);
    display(first);
    return 0;
}
