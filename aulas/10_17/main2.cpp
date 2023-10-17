#include <iostream>
#include <sstream>

#include "Stack.h"

using namespace std;

int main() {
    string input{"AMU MEGASNEM ATERCES"}, token;
    stringstream ss{input};

    while (ss >> token) {
        Stack<char> pilha;
        for (char e : token) {
            pilha.push(e);
        }
        while (!pilha.empty()) {
            cout << pilha.top();
            pilha.pop();
        }
        cout << " ";
    }
    cout << endl;
}