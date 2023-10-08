#include <iostream>

using namespace std;

int f(long n) {
    if (n == 0 || n == 1) return 1;
    return f(n - 1) + f(n - 2);
}
