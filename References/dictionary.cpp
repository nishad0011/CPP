#include <iostream> // input/output
#include <typeinfo>

#include <map>
#include <string>

using namespace std;

void by_add(map<string, int> &address)
{
    cout << "&address = " << &address << endl;
    cout << "function: " << address["nishad"] << endl
         << endl;
}

void by_ptr(map<string, int> *ptr)
{
    cout << "&ptr = " << &ptr << endl;
    cout << "&(*ptr) = " << &(*ptr) << endl;

    cout << "function: " << (*ptr)["nishad"] << endl
         << endl;
}

int main()
{
    system("cls");

    map<string, int> diction1;
    diction1["nishad"] = 10;

    // cout << "typeid(diction1) = " << typeid(diction1).name() << endl;
    // cout << "typeid(&diction1) = " << typeid(&diction1).name() << endl;

    // pass by reference
    cout << "&diction1 = " << &diction1 << endl;
    cout << "&diction1 = " << to_string(diction1) << endl;
    by_add(diction1);
    by_ptr(&diction1);

    diction1.insert({{"G", 50}, {"N", 100}});

    diction1["nishad"] = 1000;
    diction1["nisha"] = diction1["nisha"] + 1;

    cout << diction1["nisha"] << endl;

    // Iterate through the map and print the elements
    for (map<string, int>::iterator it = diction1.begin();
         it != diction1.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }
    return 0;
}