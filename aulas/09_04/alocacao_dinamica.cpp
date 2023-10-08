#include <iostream>

using namespace std;

struct People {
    string name;
    int age;
};

void fill_array(People *A, int n) {
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cout << "Digite o nome: ";
        getline(cin, A[i].name);
        cout << "Digite a idade: ";
        cin >> A[i].age;
    }
}

void print_array(People *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << "nome: " << A[i].name << ", idade: " << A[i].age << endl;
    }
}

int main() {
    int n;
    cin >> n;

    People *ptr = new People[n];

    fill_array(ptr, n);
    print_array(ptr, n);

    delete[] ptr;
    return 0;
}