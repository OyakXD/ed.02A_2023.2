#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Pos {
    int l;
    int c;
};

vector<Pos> get_vizinhos(Pos p) {
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

bool posicao_valida(Pos p, int nl, int nc) {
    return p.l >= 0 && p.l < nl && p.c >= 0 && p.c < nc;
}

bool pode_andar(vector<string>& mat, vector<vector<bool>>& visitado, Pos p) {
    return mat[p.l][p.c] == ' ' && !visitado[p.l][p.c];
}

int main() {
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, "");
    vector<vector<bool>> visitado(nl, vector<bool>(nc, false));
    getchar();
    Pos inicio, fim;

    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    for(int l = 0; l < nl; l++) {
        for(int c = 0; c < nc; c++) {
            if(mat[l][c] == 'I') {
                mat[l][c] = ' ';
                inicio = Pos{l, c};
            }
            if(mat[l][c] == 'F') {
                mat[l][c] = ' ';
                fim = Pos{l, c};
            }
        }
    }

    stack<Pos> pilha;
    stack<Pos> caminho; // pilha para armazenar o caminho correto
    
    visitado[inicio.l][inicio.c] = true;
    pilha.push(inicio);

    while (!pilha.empty()) {
        Pos atual = pilha.top();
        
        if (atual.l == fim.l && atual.c == fim.c) {
            // Encontramos o caminho! Vamos copiar a pilha para marcar o caminho
            caminho = pilha;
            break;
        }

        vector<Pos> vizinhos = get_vizinhos(atual);
        bool encontrou_vizinho = false;

        for (Pos vizinho : vizinhos) {
            if (posicao_valida(vizinho, nl, nc) && pode_andar(mat, visitado, vizinho)) {
                visitado[vizinho.l][vizinho.c] = true;
                pilha.push(vizinho);
                encontrou_vizinho = true;
                break;
            }
        }

        if (!encontrou_vizinho)
            pilha.pop();
    }

    // Marca apenas o caminho correto
    while (!caminho.empty()) {
        Pos p = caminho.top();
        mat[p.l][p.c] = '.';
        caminho.pop();
    }

    for(const string& line : mat)
        cout << line << endl;

    return 0;
}