#include <iostream>
#include <sstream>  //cabeçalho que contém o tipo de dado stringstream
#include <string>
#include <vector>  //cabeçalho que contém a estrutura de dados vector

using namespace std;

void vet(vector<int> vetor, int n) {
    if (n == 1) {
        cout << vetor[0] << " ";
        return;
    }
    cout << vetor[n - 1] << " ";
    (vetor, n - 1);
}

int sum(vector<int> vetor, int n) {
    if (n == 1) {
        return vetor[0];
    }
    return sum(vetor, n - 1) + vetor[n - 1];
}

void rev(vector<int> vetor, int n) {
    if (n == 1) {
        cout << vetor[0] << " ";
        return;
    }
    cout << vetor[n - 1] << " ";
    rev(vetor, n - 1);
}

int mult(vector<int> vetor, int n) {
    if (n == 1) {
        return vetor[0];
    }
    return mult(vetor, n - 1) * vetor[n - 1];
}

int min(vector<int> vetor, int n) {
    if (n == 1) {
        return vetor[0];
    }
    int m = min(vetor, n - 1);
    if (vetor[n - 1] < m) {
        return vetor[n - 1];
    } else {
        return m;
    }
}

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<int> vetor;
    int value;
    while (ss >> value) vetor.push_back(value);

    int size = vetor.size();

    cout << "vet : [ ";
    vet(vetor, size);
    cout << "]" << endl;

    cout << "rvet: [ ";
    rev(vetor, size);
    cout << "]" << endl;

    cout << "sum : ";
    cout << sum(vetor, size);
    cout << endl;

    cout << "mult: ";
    cout << mult(vetor, size);
    cout << endl;

    cout << "min : ";
    cout << min(vetor, size);
    cout << endl;
}