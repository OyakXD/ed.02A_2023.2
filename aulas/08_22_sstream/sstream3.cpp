#include <iostream>
#include <string>
#include <sstream>

using namespace std;;

int main(){
    string entrada;
    string p1, p2, p3;
    getline(cin, entrada);

    istringstream iss(entrada);

    getline(iss, p1, ';');
    getline(iss, p2, ';');
    getline(iss, p3, ';');
    cout << p1 << "," << p2 << "," << p3 << endl;

    return 0;
}