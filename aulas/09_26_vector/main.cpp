#include <iostream>
#include "Vector.h"
using namespace std;

void print_vector(const Vector& v) {
    for(unsigned int i{}; i < v.size(); ++i) {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

int main() {
    Vector vec; // cria vector vazio
    for(int i{}; i < 50; ++i) {
        vec.push_back(i);
    }
    print_vector(vec);
}