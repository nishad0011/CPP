#include <iostream> // input/output
// #include <stdlib.h>
using namespace std;

int main()
{
    system("cls");

    string s = "Hello";
    s.append(" World");

    cout << s.back() << endl;
    cout << s.find('l') << endl;

    s.erase(s.begin() + 5);
    cout << s.substr(0, 3) << endl;

    cout << "s =" << s;
    return 0;
}