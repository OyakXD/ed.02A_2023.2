#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List lst;

    for(int i = 1; i <= 9; i++) {
        lst.push_back(i);
    }
    
    while(!lst.empty()) {
        cout << lst.back() << " ";
        lst.pop_back();
    }
    cout << endl;
}