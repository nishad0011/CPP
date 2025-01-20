#include <iostream> // input/output
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
    system("cls");

    // for (int i = 0; i < 10; i++)
    // {
    //     if (i == 5)
    //         continue;
    //     cout << i << " ";
    // }

    vector<int> arr = {1, 2, 3, 4, 5};
    for (int a : arr)
    {
        cout << a << " ";
    }

    return 0;
}