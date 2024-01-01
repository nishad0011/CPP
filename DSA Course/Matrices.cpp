#include <iostream>
using namespace std;

struct Matrix
{
    int A[5][5] = {0};
    int size;
};

void DisplayMatrix(struct Matrix *p)
{
    cout << endl
         << endl;
    int i, j;
    for (i = 0; i < p->size; i++)
    {
        for (j = 0; j < p->size; j++)
        {
            cout << p->A[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void DiagMatrixSet(struct Matrix *p, int TempArr[], int size)
{
    p->size = size;
    for (int i = 0; i < p->size; i++)
    {
        p->A[i][i] = TempArr[i];
    }
    cout << "Matrix Set.";
}

int main()
{
    struct Matrix M;
    int Ar[] = {1, 9, 10, 21, 5};
    DiagMatrixSet(&M, Ar, 5);
    DisplayMatrix(&M);
    return 0;
}