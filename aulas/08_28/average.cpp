#include <iostream>
#include <string>

using namespace std;

struct student {
    int id;
    string name;
    float ap1, ap2, ap3;
};

float average(student a){
    return (a.ap1 + a.ap2 + a.ap3)/3;
}

int main() {
    student a, a1;

    cin >> a.id;
    cin.ignore();
    getline(cin, a.name);
    cin >> a.ap1 >> a.ap2 >> a.ap3;
    a1 = a;
    for(int i = 0; i < 4; i++) {
        cin >> a.id;
        cin.ignore();
        getline(cin, a.name);
        cin >> a.ap1 >> a.ap2 >> a.ap3;
        if(average(a) > average(a1)) {
            a1 = a;
        }
    }

    cout << a1.id << " " << a1.name << " " << average(a1);
}