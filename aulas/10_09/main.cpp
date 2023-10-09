#include <iostream>

#include "FowardList.h"

using namespace std;

int main() {
    ForwardList lista;

    for (int i = 1; i <= 10; i++) {
        lista.push_front(i);
    }

    lista.print();
}