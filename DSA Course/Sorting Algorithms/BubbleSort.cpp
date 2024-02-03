/*
    BUBBLE SORT
    pass 1 -> n-1 comparisons, After pass biggest element reaches bottom (in ascending sort).
    pass 2 -> n-2 comparisons, After pass second largest element reaches bottom.
    Continue for n-1 passes

    sort ->O(n^2)
    swaps ->O(n^2) (Maximum).
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

void BubbleSort(int Arr[], int Arr_len)
{
    bool flag;
    int temp;
    for (int i = 0; i < Arr_len - 1; i++)
    {
        flag = false;
        for (int j = 0; j < Arr_len - 1 - i; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                // Swap
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag) // No swap occured in the pass ie.Array is sorted
        {
            break;
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
    int Arr[] = {20, 40, 30, 80, 10, 50};
    int Arr_len = sizeof(Arr) / sizeof(int);

    BubbleSort(Arr, Arr_len);

    Display(Arr, Arr_len);

    return 0;
}