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

int LoopCheck(struct Node *p)
{
    struct Node *a = p;
    a = a->next;
    while (a->next != NULL && p->next != NULL)
    {
        if (p->data == a->data)
        {
            cout << "It is a loop." << endl;
            return 0;
        }
        else
        {
            p = p->next;
            a = a->next->next;
        }
    }
    cout << "It is NOT a loop." << endl;
    return 0;
}

int main()
{
    int A[] = {5, 10, 20, 30, 40, 80};
    create(A, 6);

    // Node *t = first;
    // while (t->next != NULL)
    //     t = t->next;
    // t->next = first;

    LoopCheck(first);
    return 0;
}