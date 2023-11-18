#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Imprime a matriz.
void print(string* mat, int nl) {
    for (int i = 0; i < nl; i++) {
        cout << mat[i] << endl;
    }
}

// Faz a queimada.
void fire(int nl, int nc, string* mat, int l, int c) {
    // Cria a pilha e empilha a posição inicial.
    stack<int> stack;
    stack.push(l * nc + c);

    // Enquanto a pilha não estiver vazia.
    while (!stack.empty()) {
        // Desempilha a posição atual.
        int top = stack.top();
        stack.pop();

        // Calcula a linha e a coluna da posição atual.
        int current_l = top / nc;
        int current_c = top % nc;

        // Se a posição atual for '.' ou 'o', pula para a próxima iteração.
        if (mat[current_l][current_c] == '.' ||
            mat[current_l][current_c] == 'o') {
            continue;
        }

        // Marca a posição atual como queimada.
        mat[current_l][current_c] = 'o';

        // Se a posição atual não for a primeira linha e a posição acima for
        // '#', empilha a posição acima.
        if (current_l > 0 && mat[current_l - 1][current_c] == '#') {
            stack.push((current_l - 1) * nc + current_c);
        }

        // Se a posição atual não for a última linha e a posição abaixo for
        // '#', empilha a posição abaixo.
        if (current_l < nl - 1 && mat[current_l + 1][current_c] == '#') {
            stack.push((current_l + 1) * nc + current_c);
        }

        // Se a posição atual não for a primeira coluna e a posição à esquerda
        // for '#', empilha a posição à esquerda.
        if (current_c > 0 && mat[current_l][current_c - 1] == '#') {
            stack.push(current_l * nc + current_c - 1);
        }

        // Se a posição atual não for a última coluna e a posição à direita for
        // '#', empilha a posição à direita.
        if (current_c < nc - 1 && mat[current_l][current_c + 1] == '#') {
            stack.push(current_l * nc + current_c + 1);
        }
    }
}

// Main.
int main() {
    // Lê a entrada. (Número de linhas, número de colunas, linha inicial, coluna inicial.)
    int nl, nc, l, c;
    cin >> nl >> nc >> l >> c;

    // Cria dinamicamente e lê a matriz.
    string* mat = new string[nl];
    for (int i = 0; i < nl; i++) {
        cin >> mat[i];
    }

    // Faz a queimada e imprime a matriz.
    fire(nl, nc, mat, l, c);
    print(mat, nl);

    // Libera a memória.
    delete[] mat;

    return 0;
}
