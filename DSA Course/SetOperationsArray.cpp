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

void Union(struct Array *A, struct Array *B)
{
    struct Array C;
    int i, j, k;
    i = j = k = 0;

    //
    while (i < A->current_length && j < B->current_length)
    {
        if (A->Ar[i] < B->Ar[j])
            C.Ar[k++] = A->Ar[i++];
        else if (A->Ar[i] > B->Ar[j])
            C.Ar[k++] = B->Ar[j++];
        else if (A->Ar[i] == B->Ar[j])
        {
            C.Ar[k++] = A->Ar[i++];
            j++;
        }
    }

    // Entering remaining element in C.
    for (; i < A->current_length;)
        C.Ar[k++] = A->Ar[i++];
    for (; j < B->current_length;)
        C.Ar[k++] = B->Ar[j++];

    C.current_length = k;
    // Displaying C
    Display(&C);
}

void Intersection(struct Array *A, struct Array *B)
{
    struct Array C;
    int i, j, k;
    i = j = k = 0;

    // Only add common elements.
    while (i < A->current_length && j < B->current_length)
    {
        if (A->Ar[i] < B->Ar[j])
            i++;
        else if (A->Ar[i] > B->Ar[j])
            j++;
        else if (A->Ar[i] == B->Ar[j])
        {
            C.Ar[k++] = A->Ar[i++];
            j++;
        }
    }

    C.current_length = k;
    // Displaying C
    Display(&C);
}

int main()
{
    struct Array A = {{2, 3, 5, 7, 10}, 10, 5};
    struct Array B = {{1, 3, 5, 7, 9}, 10, 5};

    // Union(&A, &B);
    // Intersection(&A, &B);
    return 0;
}