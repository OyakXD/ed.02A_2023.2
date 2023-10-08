#include <iostream>

using namespace std;

double potencia(double a, int b) {
    if (b == 0) return 1;
    return a * potencia(a, b - 1);
}

int main() {

}