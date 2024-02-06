/*
    INSERTION SORT
    Find the biggest element and shift it to the end.
    Repeat with last element excluded.
    Continue for n-1 passes.

    passes n-1;

    time ->
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

void SelectionSort(int Arr[], int Arr_len)
{
    int k;
    for (int i = 0; i < Arr_len - 1; i++)
    {
        for (int j = k = i; j < Arr_len; j++)
        {
            if (Arr[j] < Arr[k])
            {
                k = j;
            }
        }
        Swap(&Arr[k], &Arr[i]);
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
    int Arr[] = {20, 5, 30, 80, 100, 10, 50};
    int Arr_len = sizeof(Arr) / sizeof(int);

    SelectionSort(Arr, Arr_len);

    Display(Arr, Arr_len);

    return 0;
}