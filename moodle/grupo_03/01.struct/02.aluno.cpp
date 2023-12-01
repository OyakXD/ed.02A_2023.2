#include <iomanip>
#include <iostream>

using namespace std;

struct Student {
    string name;
    int registration;
    string discipline;
    double note;
};

void read_student(Student &s) {
    getline(cin, s.name);
    cin >> s.registration;
    cin.ignore();
    getline(cin, s.discipline);
    cin >> s.note;
    cin.ignore();
}

void print_approval(Student s) {
    if (s.note < 7) {
        cout << s.name << " reprovado(a) em " << s.discipline << endl;
    } else {
        cout << s.name << " aprovado(a) em " << s.discipline << endl;
    }
}

int main() {
    Student s;
    read_student(s);
    print_approval(s);
}