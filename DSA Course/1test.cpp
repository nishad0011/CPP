#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr{1,2,3,4};

	int size = sizeof(arr)/sizeof(int);
	cout << size << endl; 
    return 0;
}