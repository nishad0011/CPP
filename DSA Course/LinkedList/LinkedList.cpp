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
}

void displayRecursive(struct Node *p)
{
    cout << p->data << "->";
    if (p->next != NULL)
    {
        displayRecursive(p->next);
    }
}

int count(struct Node *p)
{
    if (p->next != 0)
    {
        return 1 + count(p->next);
    }
    else
    {
        return 1;
    }
}

int main()
{
    int A[] = {5, 10, 20, 40, 80};
    create(A, 5);
    // display(first);
    // displayRecursive(first);
    cout << "count is " << count(first);
    return 0;
}