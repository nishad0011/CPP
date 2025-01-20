#include <iostream> // input/output
#include <typeinfo>

#include <map>
#include <string>

using namespace std;

int main()
{
    system("cls");

    map<string, int> diction1;
    diction1["nishad"] = 10;

    // cout << typeid(diction1)).name() << endl;

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