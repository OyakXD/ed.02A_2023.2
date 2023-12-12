#include <iostream>

using namespace std;

int main() {
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8};  // vetor
    int n = sizeof(vec) / sizeof(vec[0]);  // tamanho do vetor

    // imprimir elementos do vetor
    for (int i{0}; i < n; i++) cout << vec[i] << " ";
    cout << endl;

    for (auto val : vec) cout << val << " ";
    cout << endl;
}