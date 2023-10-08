#include <iostream>
#include <string>

using namespace std;

/*
    bool is_palin(string str) {
    if (str.size() <= 1) return true;
    if (str[0] != str[str.size() - 1]) return false;
    return is_palin(str.substr(1, str.size() - 2));
}
*/

bool eh_palindromo(string palavra, int ini, int fim) {
    if (ini >= fim) return true;
    return palavra[ini] == palavra[fim] && eh_palindromo(palavra, ini + 1, ini - 1);
}

int main() {
    string str;

    while (1) {
        cin >> str;
        if (str == "exit") break;

        // bool is = is_palin(str);
        bool is = eh_palindromo(str, 0, str.size() - 1);
        if (is)
            cout << "eh" << endl;
        else
            cout << "nao eh" << endl;
    }
}