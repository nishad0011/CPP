/*
    MERGE SORT
    place i and j at beginning of two lists (or different sorted sections in single list).
    Compare i and j elements.Place the smaller element in a new list and increment that pointer by 1.
    Continue till one list is completely added and then add the remaining elements of other list to the sombined list.

    Passes -> log n
    time ->O(n log n)
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

void MergeSort(int Arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int B[20];
    while (i <= mid && j <= high)
    {
        if (Arr[i] < Arr[j])
            B[k++] = Arr[i++];
        else
            B[k++] = Arr[j++];
    }
    for (; i <= mid; i++)
    {
        B[k++] = Arr[i];
    }
    for (; j <= high; j++)
    {
        B[k++] = Arr[j];
    }
    for (int i = low; i <= high; i++)
    {
        Arr[i] = B[i];
    }
}

void RecursiveMergeSort(int Arr[], int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        RecursiveMergeSort(Arr, low, mid);
        RecursiveMergeSort(Arr, mid + 1, high);
        MergeSort(Arr, low, mid, high);
    }
}

void Display(int Arr[], int Arr_len)
{
    cout << "Array :";
    for (int j = 0; j < Arr_len; j++)
        cout << Arr[j] << "  ";
    cout << endl;
}

int main()
{
    system("cls");
    int Arr[] = {100, 40, 600, 80, 30, 50, 70};
    int Arr_len = sizeof(Arr) / sizeof(int);

    RecursiveMergeSort(Arr, 0, Arr_len - 1);

    Display(Arr, Arr_len);

    return 0;
}