#include <iostream>
using namespace std;

int main()
{
    int A[5] = {1};
    int b[5];
    for (int i = 0; i < (sizeof(A) / sizeof(int)); i++)
    {
        cout << A[i] << "  ";
    }
    cout << endl;

    for (int i = 0; i < (sizeof(b) / sizeof(int)); i++)
    {
        cout << b[i] << "  ";
    }
    cout << endl;
    return 0;
}