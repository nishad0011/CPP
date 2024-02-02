#include <iostream>
#include <stdlib.h>
using namespace std;

void Insert(int H[], int n)
{
    int i = n, value;
    value = H[i];

    while (i > 1 && value > H[i / 2])
    {
        H[i] = (H[i / 2]);
        i = (i / 2);
    }
    H[i] = value;
}

int Delete(int A[], int n)
{
    int value = A[1];
    int i, j, x, temp;
    x = A[n];
    A[1] = x;
    A[n] = value;
    i = 1;
    j = 2;
    while (j < n - 1)
    {
        if (A[j] + 1 > A[j])
        {
            j = j + 1;
        }
        if (A[i] < A[j])
        {
            // Swap
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    return value;
}

int main()
{
    system("cls");

    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};

    for (int i = 2; i <= 7; i++)
        Insert(H, i);

    cout << Delete(H, 7) << endl;
    cout << Delete(H, 6) << endl;

    for (int i = 1; i < 8; i++)
        cout << H[i] << " ";
    return 0;
}