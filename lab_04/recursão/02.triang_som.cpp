#include <iostream>

using namespace std;

void print_vec(int vetor, int n) {
    if (n == 1) {
        cout << vetor[0] << " ";
        return;
    }
    cout << vetor[n - 1] << " ";
    (vetor, n - 1);
}

void soma(int vec[], int aux[], int n, int i) {
    if (i == n - 1) {
        return;
    }
    aux[i] = vec[i] + vec[i + 1];
    soma(vec, aux, n, i + 1);
}

void triangulo(int vec[], int n) {
    if (n == 0) {
        return;
    }

    int aux[n - 1]; 
    soma(vec, aux, n, 0);
    print_vec(aux, n - 1);
    triangulo(aux, n - 1);
    print_vec(vec, n);
    return;
}

int main() {
    int n;
    cin >> n;

    int vec[n];
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    triangulo(vec, n);
}
