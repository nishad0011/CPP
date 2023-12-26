#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    // Normal 2D array  A
    int A[2][3] = {{3, 6, 9}, {4, 8, 12}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << A[i][j] << "  ";
        }
        cout << endl;
    }

    // B is pointer to array
    int *B[1];
    int ARR[5] = {10, 20, 30, 40, 50};
    B[0] = ARR;
    cout << &B << endl;
    cout << *B << endl;
    cout << *ARR << endl;
    cout << &ARR << endl;
    cout << B[0] << endl;
    cout << &B[0] << endl;

    return 0;
}