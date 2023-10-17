#include <iostream>

#include "Stack.h"

using namespace std;

struct Pessoa {
    int idade;
    string nome;
};

int main() {
    Stack<Pessoa> pilha{{21, "João"}, {20, "Maria"}};
    pilha.push({18, "Kauan"});
    pilha.push({20, "teste"});

    cout << pilha.top().nome << endl;
    cout << pilha.size() << endl;
    while (!pilha.empty()) {
        pilha.pop();
    }

    cout << pilha.size();
}