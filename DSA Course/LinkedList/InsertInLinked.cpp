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

int main()
{
    int A[] = {5, 10, 20, 40, 80};
    create(A, 5);

    Node *t = new Node;
    t->data = 1212;
    t->next = NULL;

    display(first);
    insertat(t, 1);
    display(first);
    return 0;
}