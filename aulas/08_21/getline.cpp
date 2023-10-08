#include <iostream>
#include <string>

using namespace std;

int main() {
    int idade;
    cout << "digite sua idade:";
    cin >> idade;
    cin.ignore();
    string name;
    cout << "digite seu nome: ";
    getline(cin, name);

    cout << "nome: " << name << ", idade:" << idade << endl;
}