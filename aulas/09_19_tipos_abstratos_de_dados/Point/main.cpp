#include <iostream>
#include "Ponto.h"
using namespace std;

int main() {
    Ponto p(1,2), q(3,4);
    cout << p.getX() << "," << p.getY() << endl;
    cout << q.getX() << "," << q.getY() << endl;
    cout << "distancia: " << p.calcDistancia(q) << endl;
}