#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(p1.x * p1.x + p2.y * p2.y);
}

int main() {
    Point p1{0, 0}; 
    Point p2;
    cin >> p2.x >> p2.y;

    cout << distance(p1, p2) << endl;

    return 0;
}