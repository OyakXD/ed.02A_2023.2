#include <iomanip>
#include <iostream>

using namespace std;

struct Student {
    int registration;
    string name;
    float media;
};

void read_students(Student *stud, int n) {
    for (int i = 0; i < n; i++) {
        cin >> stud[i].registration;
        cin.ignore();
        getline(cin, stud[i].name);
        cin >> stud[i].media;
    }
}

void looking_for_student(Student *stud, int n, int m) {
    for (int i = 0; i < n; i++) {
        if (stud[i].registration == m) {
            cout << stud[i].name << endl;
            cout << fixed << setprecision(1) << stud[i].media << endl;
            return;
        }
    }
    cout << "NAO ENCONTRADA" << endl;
}

int main() {
    int n;
    cin >> n;

    Student *stud = new Student[n];
    read_students(stud, n);

    int m;
    cin >> m;

    looking_for_student(stud, n, m);
    delete[] stud;
}