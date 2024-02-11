/*
    HASH (LINEAR PROBING)
    If collision find next empty space inhash table and place the element there.
    Deleting element is difficult (can be done by rehashing).
    Ideally the size of hash table should be double or more than no if elements.ie. Loading factor <= 0.5

    Loading factor (Lambda)-> no. of ele / size of hash table
    search time ->
        successful ->(1/lam) ln(1/(1-lam))
        unsuccessful -> 1/(1-lam)
 */

#include <iostream>
#include <stdlib.h>
using namespace std;
#define SIZE 10
// Hash function
int Hash(int e)
{
    return (e % SIZE);
}

int Probe(int H[], int e)
{
    int index = Hash(e);
    while (H[index % SIZE] != 0)
        index++;
    return index % SIZE;
}

void Insert(int H[], int e)
{
    int index = Hash(e);

    if (H[index] != 0)
        index = Probe(H, e);

    H[index] = e;
}

int Search(int H[], int e)
{
    int index = Hash(e);

    while (H[index % 10] != e)
    {
        if (H[index % 10] == 0)
            return -1;
        index++;
    }
    return index % 10;
}

int main()
{
    system("cls");

    int HT[10] = {0};

    Insert(HT, 12);
    Insert(HT, 112);
    Insert(HT, 63);

    cout << "Key at :" << Search(HT, 33);

    return 0;
}