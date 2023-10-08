#include <iostream>

using namespace std;

int Soma(int n) {
    if (n == 1) return 1;
    return n + Soma(n-1);
}

int main() {
    int n;
    cin >> n;

    cout << Soma(n) << endl;
}