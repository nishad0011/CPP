#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL; // first is global struct pointer.

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    cout << p->data << "->";
    while (p->next != NULL)
    {
        p = p->next;
        cout << p->data;
        while (p->next != NULL)
        {
            cout << "->";
            break;
        }
    }
    cout << endl;
}

void insertat(struct Node *t, int index)
{
    struct Node *temp = first;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }
    t->next = temp->next;
    temp->next = t;
}

void deleteat(int index)
{
    // Deleting first node;
    if (index == 0)
    {
        struct Node *p = first;
        first = first->next;
        delete p;
    }
    // Deleting any other node
    else
    {
        struct Node *q = first;
        struct Node *d = first;
        for (int i = 0; i < index; i++)
        {
            d = d->next;
        }
        for (int i = 0; i < index - 1; i++)
        {
            q = q->next;
        }
        q->next = d->next;
        delete d;
    }
}

void remove_duplicate(struct Node *p)
{
    struct Node *t = p;
    p = p->next;
    while (p != NULL)
    {
        if (t->data == p->data)
        {
            t->next = p->next;
            delete p;
            p = t->next;
        }
        else
        {
            t = t->next;
            p = p->next;
        }
    }
}

int main()
{
    int A[] = {5, 10, 20, 20, 40, 80};
    create(A, 6);

    Node *t = new Node;
    t->data = 1212;
    t->next = NULL;

    display(first);
    // insertat(t, 1);
    // deleteat(1);
    remove_duplicate(first);
    display(first);
    return 0;
}