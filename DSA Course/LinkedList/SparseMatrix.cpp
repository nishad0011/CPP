#include <iostream>
using namespace std;
struct Node
{
    int data;
    int column;
    struct Node *next;
};
struct Node *A[5];

void create(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        A[i] = new struct Node;
        A[i]->data = -1;
        A[i]->column = -1;
        A[i]->next = NULL;
    }
}

void insert(int element, int row, int col)
{
    if (A[row]->data == -1)
    {
        A[row]->data = element;
        A[row]->column = col;

        struct Node *temp = new struct Node;
        temp->column = -1;
        temp->data = -1;
        temp->next = NULL;

        A[row]->next = temp;
    }
    else
    {
        struct Node *p = A[row];
        struct Node *q;
        while (((p->next->data) != -1) && col > p->next->column)
        {
            p = p->next;
        }
        q = p->next;
        struct Node *t = new struct Node;
        p->next = t;
        t->column = col;
        t->data = element;
        t->next = q;
    }
}

void display(int r, int c)
{
    struct Node *p;
    for (int i = 0; i < r; i++)
    {
        p = A[i];
        for (int j = 0; j < c; j++)
        {
            if (p->column == j)
            {
                cout << " " << p->data;
                p = p->next;
            }
            else
            {
                cout << " 0";
            }
        }
        cout << endl;
    }
}

int main()
{
    int rows, columns;
    rows = columns = 5;

    create(rows, columns);
    // insert(element,row,col)
    insert(1, 1, 1);
    insert(2, 1, 3);
    insert(3, 3, 1);
    insert(4, 3, 3);
    display(rows, columns);
    return 0;
}
