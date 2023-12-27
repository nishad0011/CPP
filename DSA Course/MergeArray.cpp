#include <iostream>
using namespace std;

struct Array
{
    int Ar[10];
    int size;
    int current_length;
};

void Display(struct Array *Arr)
{
    for (int i = 0; i < Arr->current_length; i++)
        // Arr.A is address of first element
        cout << (Arr->Ar[i]) << " ";
    cout << endl
         << endl;
}

void Merge(struct Array *A, struct Array *B)
{
    struct Array C;
    C.current_length = A->current_length + B->current_length;
    int i, j, k;
    i = j = k = 0;

    // Adding smaller elements in C one by one.
    while (i < A->current_length && j < B->current_length)
    {
        if (A->Ar[i] < B->Ar[j])
            C.Ar[k++] = A->Ar[i++];
        else
            C.Ar[k++] = B->Ar[j++];
    }

    // Entering remaining element in C.
    for (; i < A->current_length;)
        C.Ar[k] = A->Ar[i++];
    for (; j < B->current_length;)
        C.Ar[k] = B->Ar[j++];

    // Displaying C
    Display(&C);
}

int main()
{
    struct Array A = {{2, 4, 6, 8, 10}, 10, 5};
    struct Array B = {{1, 3, 5, 7, 9}, 10, 5};

    Merge(&A, &B);

    return 0;
}