#include <iostream>

using namespace std;

/*int max(int v[0], int n) {
    if(n == 1) {
        return v[0];
    } else {
        int x = max(v, n-1);
        if(x > v[n-1]) {
            return x;
        } else {
            return v[n-1];
        }
    }
}
*/

int maximo(int v[], int ini, int fim) {
    if (ini == fim) return v[ini];
    int m = (ini + fim) / 2;
    int max1 = maximo(v, ini, m);
    int max2 = maximo(v, m + 1, fim);
    return (max1 > max2) ? max1 : max2;
}

int main() {
    int v[] = {12, 3, 456, 0, -1, 54, 786, 542};
    int n = sizeof(v) / sizeof(int);
    cout << maximo(v, 0, n - 1);
}