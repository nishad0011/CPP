#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
using namespace std;

int main()
{
    // Create a map of strings to integers
    map<string, int> mp;

    // Insert some values into the map
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;

    // Get an iterator pointing to the first element in the
    // map
    auto it = mp.begin();

    cout << typeid(it).name();

    return 0;
}