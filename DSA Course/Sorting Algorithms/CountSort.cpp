/*
    COUNT SORT
    1. Find maximum element in the given Array.
    2. Create a new array(C) of size of maximum element.
    3. Increment value in C at the index same as the value of element. eg.If Arr[0] is 15 increment 1 at C[15].Continue till the end of Arr.
    4. Now, insert Arr with index of C at non-zero values and decrement the non-zero value. Continue till C is completely empty.

    time ->O(n)
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

int findMax(int Arr[], int size)
{
    int maximum = INT32_MIN;
    for (int i = 0; i < size; i++)
    {
        if (Arr[i] > maximum)
            maximum = Arr[i];
    }
    return maximum;
}

void CountSort(int Arr[], int size)
{
    int max, *C;

    max = findMax(Arr, size);

    C = (int *)malloc(sizeof(int) * (max + 1));
    for (int a = 0; a <= max + 1; a++)
        C[a] = 0;

    for (int i = 0; i < size; i++)
        C[Arr[i]]++;

    int k = 0;
    for (int j = 0; j < max + 1; j++)
    {
        while (C[j] != 0)
        {
            Arr[k++] = j;
            C[j]--;
        }
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
    int Arr[] = {5, 1, 14, 16, 13, 19, 1, 3, 5, 7};
    int Arr_len = sizeof(Arr) / sizeof(int);

    CountSort(Arr, Arr_len);

    Display(Arr, Arr_len);

    return 0;
}