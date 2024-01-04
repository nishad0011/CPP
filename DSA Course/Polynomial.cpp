#include <iostream>
using namespace std;

struct Term
{
    int coefficient;
    int exponential;
};

struct Polynomial
{
    int n;
    struct Term *t;
};

void Create(struct Polynomial *S)
{
    cout << "No. of terms?" << endl;
    cin >> S->n;
    S->t = (struct Term *)malloc(S->n * sizeof(struct Term));

    for (int i = 0; i < S->n; i++)
    {
        cout << "Enter Term" << i << "(Coefficient and Exponent):";
        cin >> S->t[i].coefficient >> S->t[i].exponential;
    }
}

void Display(struct Polynomial *S)
{
    cout << "Displaying polynomial" << endl;
    for (int i = 0; i < S->n; i++)
    {
        cout << S->t[i].coefficient << "x^" << S->t[i].exponential << " + ";
    }
}

int main()
{
    struct Polynomial p1;
    Create(&p1);
    Display(&p1);
    return 0;
}