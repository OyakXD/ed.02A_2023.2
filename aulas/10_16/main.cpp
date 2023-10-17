#include "Queue.h"
using namespace std;

int main() {
    Queue<double> fila1, fila2; // cria duas filas vazias

    for(int i = 1; i < 10; i++) { // preenche a fila1 com 1,2,...,9
        fila1.push(i);
    }

    for(int i = 12; i < 19; i++) { // preenche a fila2 com 12,13,...,18
        fila2.push(i);
    }

    fila1.swap(fila2); // troca as duas filas

    cout << "fila 1: "; // imprime a fila1
    while(!fila1.empty()) {
        cout << fila1.front() << " ";
        fila1.pop();
    }
    cout << endl;

    cout << "fila 2: "; // imprime a fila2
    while(!fila2.empty()) {
        cout << fila2.front() << " ";
        fila2.pop();
    }
    cout << endl;

}