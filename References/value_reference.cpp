#include <iostream>
#include <vector>
using namespace std;

void change(int t){
    cout << endl<<"In change"<<endl;
    cout<< "&t = "<<&t<<endl;
    cout<< "t = "<<t<<endl;

}
void change2(int *t){
    (*t)++;
    cout <<endl<<  "In change2"<<endl;
    cout<< "*t = "<<*t<<endl;
    cout<< "&t = "<<&t<<endl;
    cout<< "t = "<<t<<endl;
}

int main(){
    system("cls");
    int a = 10;

    // Call by value
    change(a);

    // Call by reference
    change2(&a);

    cout <<endl<<  "In main"<<endl;
    cout<< "&a = "<<&a<<endl;
    cout<< "a = "<<a<<endl;
    return 0;
}