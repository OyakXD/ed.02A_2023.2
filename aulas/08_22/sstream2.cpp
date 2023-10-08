#include <iostream>
#include <cstring>
#include <ctype.h>
#include <sstream>

using namespace std;

int main(){
    double resultado{}, token{};
    string entrada;

    int i = 5;
    while(i--){
        getline(cin, entrada);
        istringstream iss;
        iss.str(entrada);

        while(iss >> token) resultado += token;
        cout << resultado << "\n";
        resultado = 0;
    }

    return 0;
}