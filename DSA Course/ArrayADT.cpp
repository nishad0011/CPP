#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int current_length;
};

void Swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void Display(struct Array *Arr)
{
    for (int i = 0; i < Arr->current_length; i++)
        // Arr.A is address of first element
        cout << *(Arr->A + i) << " ";
    cout << endl
         << endl;
}

void Append(struct Array *p, int element)
{
    /*
    p->x gives value of x.

    */
    *((p->A) + (p->current_length)) = element;
    (p->current_length)++;

    // Display modified array
    cout << "Array after appending :" << endl;
    Display(p);
}

void Insert(struct Array *p, int index, int value)
{
    int i = p->current_length;

    // Shifting the elements
    for (i; i >= index; i--)
    {
        *(p->A + i) = *(p->A + (i - 1));
    }

    // Insert element at emptied location
    *(p->A + (index - 1)) = value;

    // update current_length
    p->current_length++;

    // Display modified array
    cout << "Array after insertion :" << endl;
    Display(p);
}

void Delete(struct Array *p, int index)
{
    if (index < 1 || index > p->current_length)
        cout << "Unable to delete.." << endl;
    else
    {
        for (int x = index; x < p->current_length; x++)
        {
            *((p->A) + x - 1) = *((p->A) + x);
        }
        *(p->A + (p->current_length) - 1) = 0;
        p->current_length--;
        // Display modified array
        cout << "Array after Deletion :" << endl;
        Display(p);
    }
};

void LinearSearch(struct Array *p, int element)
{
    bool el_found = false;
    for (int i = 0; i < p->current_length; i++)
    {
        if (*(p->A + i) == element)
        {
            cout << "Element found at index " << i + 1 << endl;
            el_found = true;
            if (i != 0)
                Swap(p->A + i, p->A + i - 1);
        }
    }
    if (!el_found)
        cout << "Element not found" << endl;

    // Display modified array
    cout << "Array after Search :" << endl;
    Display(p);
}

int main()
{
    int tempArr[] = {2, 4, 6, 8, 10, 12};
    int tempArrLen = sizeof(tempArr) / sizeof(int);
    int Array[20] = {}; //{} initializes array of 0s.

    // initializing array Array[10] with tempArr[]
    for (int i = 0; i < tempArrLen; i++)
        Array[i] = tempArr[i];

    struct Array Arr;
    Arr.A = Array;
    Arr.size = sizeof(Array) / sizeof(int);
    Arr.current_length = tempArrLen; // initially in this case only

    cout << endl
         << "Current Array :" << endl;
    Display(&Arr);
    Append(&Arr, 999);
    Insert(&Arr, 3, 1000);
    // Delete(&Arr, 1);
    LinearSearch(&Arr, 999);
    return 0;
}