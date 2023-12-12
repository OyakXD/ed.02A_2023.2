#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cout << "Digite a ordem da matriz: ";
    cin >> n;

    // cria matriz dinamicamente
    int **matriz = new int *[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];
    }

    // lê os inteiros do teclado
    cout << "Digite os elementos da matriz: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }

    // imprime a matriz
    cout << "Matriz: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "[ ";
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << "]" << endl;
    }

    // deleta a matriz
    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}