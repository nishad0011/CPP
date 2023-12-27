#include <iostream>
using namespace std;

struct Array
{
    int A[6] = {0};
    int size;
};

void Recursive_Binary_Search(int A[], int min, int max, int element)
{
    static bool element_found = false;
    if (min < max)
    {
        int mid = ((min + max) / 2);
        if (A[mid] == element)
        {
            cout << "Element found at index " << mid << endl;
            element_found = true;
        }
        else if (A[mid] > element)
            Recursive_Binary_Search(A, min, mid - 1, element);
        else if (A[mid] < element)
            Recursive_Binary_Search(A, mid + 1, max, element);
    }
    if (!element_found)
    {
        cout << "Element not found " << endl;
    }
}

int main()
{
    struct Array Arr;
    int temparr[] = {2, 4, 6, 8, 10, 12};
    Arr.size = sizeof(temparr) / sizeof(temparr[0]);
    for (int i = 0; i < Arr.size; i++)
    {
        Arr.A[i] = temparr[i];
    }

    Recursive_Binary_Search(Arr.A, 0, Arr.size - 1, 10);

    return 0;
}