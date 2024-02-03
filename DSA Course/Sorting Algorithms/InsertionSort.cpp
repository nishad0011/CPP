/*
    INSERTION SORT
    Shift the list to make space for element in sorted array and the insert element at the freed up space

    passes n-1;

    time ->O(n)(Minimum) O(n^2)(Maximum)
    swaps ->O(1)(Minimum) O(n^2)(Maximum).
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

void InsertionSort(int Arr[], int Arr_len)
{
    int x, j;
    for (int i = 1; i < Arr_len; i++)
    {
        j = i - 1;
        x = Arr[i];
        while (j > -1 && Arr[j] > x)
        {
            Arr[j + 1] = Arr[j];
            j--;
        }
        Arr[j + 1] = x;
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
    int Arr[] = {20, 40, 30, 80, 10, 50, 10};
    int Arr_len = sizeof(Arr) / sizeof(int);

    InsertionSort(Arr, Arr_len);

    Display(Arr, Arr_len);

    return 0;
}