#include <iostream>

using namespace std;

int main() {
    int x = 20;
    int *ptr = &x;
    int *ptr2 = nullptr;

    if(ptr2 == nullptr) {
        cout << "nada" << endl;
    } else {
        cout << ptr2 << endl;
    }


    cout << x << endl; // 20
    cout << &x << endl; // endereço de x
    cout << ptr << endl; // endereço de x
    cout << *ptr << endl; // 20
    *ptr = 50;
    cout << x << endl; // 50

    return 0;
}