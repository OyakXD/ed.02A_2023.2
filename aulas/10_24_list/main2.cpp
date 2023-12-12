#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List lista {1,2,3,4,5,6,7,8,9};

    for(auto it = lista.begin(); it != lista.end(); ++it) {
        if(*it == 3) {
            auto it2 = lista.erase(it); // remove o 3
            lista.insert(it2, 666); // insere o 666 antes do 4
            break;
        }
    }

    // Imprime de frente para tras
    auto it = lista.begin();
    while(it != lista.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    // Imprime de tras para frente
    it = lista.end();
    it--;
    while(it != lista.end()) {
        cout << *it << " ";
        --it;
    }
    cout << endl;
}