
#include <iostream> //input and output
#include <vector>
#include <algorithm> //array reversing,sorting
using namespace std;
int main()
{
    system("cls");

    vector<int> vectorname = {1, 20, 300, 40};

    // reverse(vectorname.begin(), vectorname.end());
    // reverse(vectorname.begin() + 1, vectorname.end());

    // vectorname.push_back(100); // Add ele at the end
    // vectorname.pop_back();     // Pop last
    // vectorname.insert(vectorname.begin() + 4, 999);

    // cout << vectorname.back() << endl;

    sort(vectorname.begin(), vectorname.end());

    int size = vectorname.size();
    for (int i = 0; i < size; i++)
    {
        cout << vectorname[i] << " ";
    }

    return 0;
}