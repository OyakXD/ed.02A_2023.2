#include <iostream>
#include <limits>

using namespace std;

int read_int() {
    int valor{};
    while (true) {
        cin >> valor;
        if (cin.fail()) {  // houve falha na leitura
                           // reseto os bits de erro
            cin.clear();
            // limpo o buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida, tente novamente: ";
        } else {  // não houve falha na leitura
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

int main() {
    int x{};
    cout << "Digite um int: ";
    x = read_int();
    cout << "Valor digitado: " << x << endl;
    return 0;
}