#include <iostream>
#include <stdlib.h>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue *p, int e)
{
    if ((p->rear + 1) % p->size == p->front)
    {
        cout << "Queue is full.." << endl;
    }
    else
    {
        p->rear = (p->rear + 1) % p->size;
        p->Q[p->rear] = e;
        cout << "Enqueued :" << e << endl;
    }
}

void display(struct Queue *p)
{
    int i = p->front + 1;
    cout << "QUEUE : ";
    do
    {
        cout << p->Q[i] << " ";
        i = (i + 1) % p->size;
    } while (i != (p->rear + 1) % p->size);

    cout << endl;
}

int dequeue(struct Queue *p)
{
    int x = -1;
    if (p->front == p->rear)
        cout << "Queue is empty..";
    else
    {
        x = p->Q[p->front + 1];
        p->front = ((p->front) + 1) % p->size;
    }
    return x;
}

void create(struct Queue *p, int size)
{
    p->size = size;
    p->front = p->rear = 0;
    p->Q = new int(p->size);
}

int main()
{
    system("cls");

    struct Queue q;
    create(&q, /*size*/ 5);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 100);
    display(&q);

    cout << "Dequeued :" << dequeue(&q) << endl;
    cout << "Dequeued :" << dequeue(&q) << endl;

    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    display(&q);
}