/*
    HASH (CHAINING)

    search time ->O(n)
 */

#include "Chains.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

// Hash function
int Hash(int e)
{
    return (e % 10);
}

void Insert(struct Node *H[], int e)
{
    int index = Hash(e);
    SortedInsert(&H[index], e);
}

int main()
{
    system("cls");

    struct Node *HT[10];

    for (int i = 0; i < 10; i++)
        HT[i] = NULL;

    Insert(HT, 12);
    Insert(HT, 112);
    Insert(HT, 62);

    // Searching
    struct Node *temp;
    temp = Search(HT[Hash(12)], 11);
    cout << temp->data;

    return 0;
}