#include <iostream>

using namespace std;

void swap(int *p1, int *p2) {
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

int main() {
    int p1, p2;
    cin >> p1 >> p2;

    swap(&p1, &p2);
    cout << p1 << endl << p2 << endl;
    
    return 0;
}