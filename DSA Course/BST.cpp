#include <iostream>
#include <stdlib.h>
#include "stack.h"

using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct Node *root = NULL;

void Insert(int key)
{
    struct Node *t = root;
    struct Node *r = NULL, *p;

    if (t == NULL)
    {
        p = (struct Node *)malloc(sizeof(Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

struct Node *RecInsert(struct Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = RecInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = RecInsert(p->rchild, key);
    }

    return p;
}

struct Node *InPre(struct Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

struct Node *InSuc(struct Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

int Height(struct Node *p)
{
    if (p == NULL)
        return 0;
    int x, y;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSuc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << " " << p->data;
        Inorder(p->rchild);
    }
}

int main()
{
    system("cls");

    /*     root = RecInsert(root, 10);
        RecInsert(root, 5);
        RecInsert(root, 20);
        RecInsert(root, 8);
        RecInsert(root, 30);
        Delete(root, 30);
        Inorder(root); */

    return 0;
}
