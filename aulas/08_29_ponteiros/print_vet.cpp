#include <iostream>

using namespace std;

void print_vetor(int n, int vet[]) {
    for(int i = 0; i < n; i++) {
        cout << vet[i] << endl;
    }
    cout << endl;
}

int main() {
    int v[5] = {5, 7, 1, 3, 2};

    int *ptr  = v;

    for(int i = 0; i < 5; i++) {
        cout << *(ptr + i) << endl;
    }

    return 0;

    /*
    int n;
    cin >> n;
    *ptr += n;

    cout << *ptr << endl; 

    cout << v[0] << endl; // 1
    cout << v << endl; // endereço de memória
    cout << *v << endl; // 1
    cout << &v[0] << endl; // endereço de memória

    print_vetor(5, v);
    */
}