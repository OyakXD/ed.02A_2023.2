#include <iostream>

#include "FowardList.h"

using namespace std;

int main() {
    ForwardList lista;

    for (int i = 1; i <= 10; i++) {
        lista.push_front(i);
    }
    // Caminhar pela lista imprimindo na tela o valor os elementos

    lista.push_back(11);

    for (auto it = lista.begin(); it != lista.end(); ++it) {
        cout << *it << " ";
    }
}