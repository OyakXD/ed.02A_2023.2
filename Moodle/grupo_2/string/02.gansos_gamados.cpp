#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    istringstream stream(str);

    string previous_word, current_word;
    bool order = true;
    while (stream >> current_word) {
        if (current_word < previous_word) {
            order = false;
            break;
        }
        previous_word = current_word;
    }

    if (order) 
        cout << "sim\n";
    else 
        cout << "nao\n";

    return 0;
}
