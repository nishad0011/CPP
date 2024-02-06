/*
    QUICK SORT

    passes n;

    time ->O(n log n)(Minimum) O(n^2)(Maximum)
    swaps ->
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int Arr[], int low, int high)
{
    int pivot = Arr[low];
    int i = low;
    int j = high;
    do
    {
        do
        {
            i++;
        } while (Arr[i] <= pivot);
        do
        {
            j--;
        } while (Arr[j] > pivot);

        if (i < j)
            Swap(&Arr[i], &Arr[j]);

    } while (i < j);

    Swap(&Arr[low], &Arr[j]);

    return j;
}

void QuickSort(int Arr[], int low, int high)
{
    int j;
    if (low < high)
    {
        j = Partition(Arr, low, high);
        QuickSort(Arr, low, j);
        QuickSort(Arr, j + 1, high);
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
    int Arr[] = {20, 5, 30, 80, 100, 10, 50, INT32_MAX};
    int Arr_len = sizeof(Arr) / sizeof(int);

    QuickSort(Arr, 0, Arr_len - 1);

    Display(Arr, Arr_len);

    return 0;
}