#include <iostream>

using namespace std;

void invert(int vet[], int ini, int fim) {
    if (ini >= fim) return;
    int aux = vet[ini];
    vet[ini] = vet[fim];
    vet[fim] = aux;
    invert(vet, ini + 1, fim - 1);
}

int main() {
    int vet[] = {1, 2, 3, 4, 5};
    invert(vet, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << vet[i] << " ";
    }
    cout << endl;
    return 0;
}