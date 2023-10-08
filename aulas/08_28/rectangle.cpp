#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
    
};

struct Rectangle {
    Point p; // ponto superior esquerdo
    Point q; // ponto inferior direito
    Point m; // ponto inferior esquerdo
    Point s; //ponto superior direito

};

Rectangle initialize_rectangle(Point p, Point q) {
    Rectangle r;
    r.p = p;
    r.q = q;
    r.m.x = p.x;
    r.m.y = q.y;
    r.s.x = q.x;
    r.s.y = p.y;

    return r;
}

double area(Rectangle r) {
    double base = abs(r.q.x - r.m.x);
    double height = abs(r.p.y - r.m.y); 

    double area = base * height;

    return area;

    // return abs(r.q.x - r.m.x) * abs(r.p.y - r.m.y);
}

double perimeter(Rectangle r) {
    double base = abs(r.q.x - r.m.x);
    double height = abs(r.p.y - r.m.y);

    return (2 * base) + (2 * height);

    // return (2 * (abs(r.q.x - r.m.x))) + (2 * (abs(r.p.y - r.m.y)));
}

double diagonal(Rectangle r) {
    double base = abs(r.q.x - r.m.x);
    double height = abs(r.p.y - r.m.y);

    return pow(base, 2) + pow(height, 2);

    // return pow((abs(r.q.x - r.m.x), 2)) + ((abs(r.p.y - r.m.y), 2))
}

int main() {
   double x, y;
   
   cout << "Ponto superior esquerdo: ";
   cin >> x >> y;
    Point p{x, y};

   cout << "Ponto inferior direito: ";
   cin >> x >> y;
   Point q{x, y};

   Rectangle r = initialize_rectangle(p, q);

   cout << "Area: " << area(r) << endl;
   cout << "Perimetro: " << perimeter(r) << endl;
   cout << "Diagonal: " << diagonal(r) << endl;
}