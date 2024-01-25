#include <iostream>
#ifndef queue_h
#define queue_h

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};

void create(struct Queue *p, int size)
{
    p->size = size;
    p->front = p->rear = 0;
    p->Q = (Node **)malloc(p->size * sizeof(Node *));
}

void enqueue(struct Queue *p, Node *e)
{
    if ((p->rear + 1) % p->size == p->front)
    {
        std::cout << "Queue is full..";
    }
    else
    {
        p->rear = (p->rear + 1) % p->size;
        p->Q[p->rear] = e;
    }
}

Node *dequeue(struct Queue *p)
{
    Node *x = NULL;
    if (p->front == p->rear)
        std::cout << "Queue is empty..";
    else
    {
        x = p->Q[p->front + 1];
        p->front = ((p->front) + 1) % p->size;
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}
#endif