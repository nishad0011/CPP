/*
    SHELL SORT


    time ->O(n)
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

void Display(int Arr[], int Arr_len)
{
    cout << "Array :";
    for (int j = 0; j < Arr_len; j++)
        cout << Arr[j] << "  ";
    cout << endl;
}

void ShellSort(int Arr[], int size)
{
    int gap, i, j, temp;
    for (gap = size / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < size; i++)
        {
            temp = Arr[i];
            j = i - gap;

            while (j >= 0 && Arr[j] > temp)
            {
                Arr[j + gap] = Arr[j];
                j = j - gap;
            }
            Arr[j + gap] = temp;
        }
    }
    Display(Arr, size);
}

int main()
{
    system("cls");
    int Arr[] = {5, 1, 14, 16, 13, 19, 1, 3, 5, 7};
    int Arr_len = sizeof(Arr) / sizeof(int);

    ShellSort(Arr, Arr_len);

    return 0;
}