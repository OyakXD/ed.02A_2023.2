#include <iostream>
#include <cstring>
#include <ctype.h>
#include <sstream>

using namespace std;

int main(){
    double resultado{}, token{};
    string entrada;
    getline(cin, entrada);

    istringstream iss;
    iss.str(entrada);

    while(iss >> token) resultado += token;

    cout << resultado << "\n";

    return 0;
}