#include <iostream>
using namespace std;

/*
    ASCII
    a = 97
    z = 122
    A = 65
    Z = 90
*/

// Print the string.
void Display(char *p)
{
    int i;
    for (i = 0; p[i] != '\0'; i++)

        cout << p[i];
}

// Prints length of string.
void PrintLen(char *p)
{
    int i;
    for (i = 0; p[i] != '\0';)
        i++;
    cout << "length of string = " << i;
}

// Change the case of the string
void ChangeCase(char *p)
{
    int i;
    for (i = 0; p[i] != '\0'; i++)
    {
        if (p[i] >= 97 && p[i] <= 122)
            p[i] -= 32;
        else if (p[i] >= 65 && p[i] <= 90)
            p[i] += 32;
    }
}

int Palindrome(char *S)
{
    int i = 0;
    int j = 0;
    while (S[j] != '\0')
    {
        j++;
    }
    j--;
    while (i <= j)
    {
        if (S[i] != S[j])
        {
            cout << "Not a palindrome.";
            return 0;
        }
        else
        {
            i++;
            j--;
        }
    }
    cout << "Palindrome.";
    return 1;
}

int Anagram(char A[], char B[])
{
    int Table[26] = {};
    int i = 0;
    int j = 0;
    while (A[i] != '\0')
    {
        Table[A[i] - 97]++;
        i++;
    }
    while (B[j] != '\0')
    {
        if (Table[B[j] - 97] - 1 == -1)
        {
            cout << "Not an anagram.";
            return 0;
        }
        else
        {
            Table[B[j] - 97]--;
            j++;
        }
    }
    cout << "It is an anagram.";
    return 0;
}

int main()
{
    char str[] = "aabbccddddccbbaa";
    // PrintLen(str);
    // ChangeCase(str);
    // Display(str);
    // Palindrome(str);

    char A[] = "aaabbb";
    char B[] = "bbbaaa";
    Anagram(A, B); // Same Letters
    return 0;
}