#include <iostream>
#include <stdlib.h>
#include "queue.h"
using namespace std;

struct Node *root = NULL;

void createTree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    cout << "Enter Root of " << p->data << " : ";
    cin >> x;
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        cout << "Enter left child of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        cout << "Enter right child of " << p->data << " :";
        cin >> x;
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

void LevelOrder(struct Node *p)
{
    struct Queue q;
    create(&q, 100);

    cout << p->data << " ";
    enqueue(&q, p);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            enqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            enqueue(&q, p->rchild);
        }
    }
}

int count(struct Node *p)
{
    int x, y;
    if (p != NULL)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        return (x + y + 1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    system("cls");
    createTree();

    /*     // Display using queue.
        cout << endl
             << "pre :";
        preorder(root);

        cout << endl
             << "inorder :";
        inorder(root);

        cout << endl
             << "post :";
        postorder(root); */

    // LevelOrder(root);

    // Counting number of Nodes
    cout << "Node count is :" << count(root) << endl;
    return 0;
}