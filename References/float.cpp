#include <iostream>
#include <typeinfo>

using namespace std;
int main()
{
    system("cls");

    float f;

    f = 10 / 3; // gives int to float
    cout << "f = " << f << endl;

    f = float(10) / 3; // Gives float
    cout << "f = " << f << endl;

    cout << "typeid(f).name() = " << typeid(f).name() << endl;

    string s = to_string(f);
    cout << "to_string(f) = " << s << endl;
    cout << "s = " << s << endl;
    cout << "typeof s = " << typeid(s).name() << endl;

    cout << "stof(s) = " << stof(s) << endl;
    cout << "stoi(s) = " << stoi(s) << endl;
    cout << "typeof stof(s) = " << typeid(stof(s)).name() << endl;
    cout << "typeof stoi(s) = " << typeid(stoi(s)).name() << endl;

    return 0;
}