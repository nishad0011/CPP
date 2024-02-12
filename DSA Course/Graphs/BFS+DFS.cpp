#include <iostream>
#include <stdlib.h>
#include "queue.h"
using namespace std;

void BFS(int G[][7], int start, int n)
{
    int i = start, j;
    int visited[7] = {0};

    cout << i << " ";
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();

        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};

    if (visited[start] == 0)
    {
        visited[start] = 1;
        cout << start << " ";
        for (int j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
            {
                DFS(G, j, n);
            }
        }
    }
}

int main()
{
    system("cls");

    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   /* 1 */ {0, 0, 1, 1, 0, 0, 0},
                   /* 2 */ {0, 1, 0, 0, 1, 0, 0},
                   /* 3 */ {0, 1, 0, 0, 1, 0, 0},
                   /* 4 */ {0, 0, 1, 1, 0, 1, 1},
                   /* 5 */ {0, 0, 0, 0, 1, 0, 0},
                   /* 6 */ {0, 0, 0, 0, 1, 0, 0}};

    // BFS(G, 5, 7);
    DFS(G, 4, 7);

    return 0;
}