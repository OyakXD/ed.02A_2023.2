#include <iostream>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    int registration;
    string discipline;
    double note;

};

void read_student(Student *s) {
    for(int i = 0; i < 2; i++) {
        getline(cin, s[i].name);
        cin >> s[i].registration;
        cin.ignore();
        getline(cin, s[i].discipline);
        cin >> s[i].note;
        cin.ignore();
    }
}

void print_note(Student *s) {
    if (s[0].note > s[1].note) {
        cout << fixed << setprecision(1) << s[0].name << " , " << s[0].note << endl;
    } else if (s[0].note < s[1].note) {
        cout << fixed << setprecision(1) << s[1].name << " , " << s[1].note << endl;
    } else {
        cout << fixed << setprecision(1) << s[0].name << " e " << s[1].name << " , " << s[0].note << endl;
    }
}

int main() {
    Student s[2];
    read_student(s);
    print_note(s);
}