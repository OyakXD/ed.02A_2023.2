#include <iostream>
#include <string>
#include <sstream>
#include <cctype> 

using namespace std;

int main() {
    string str;
    getline(cin, str);

    stringstream ss(str);

    string word;
    while (ss >> word) {
        bool is_int = true;
        bool is_float = false;
        bool has_str = false;

        int i = 0;
        if (word[i] == '-') i++;

        while (i < word.size()) {
            if (word[i] == '.') {
                is_int = false;
                is_float = true;
            } else if (!isdigit(word[i])) { 
                has_str = true;
                break;
            }
            i++;
        }

        if (has_str)
            cout << "str";
        else if (is_float)
            cout << "float";
        else if (is_int)
            cout << "int";

        if (ss.peek() != EOF) cout << " ";
    } 

    cout << endl;
    return 0;
}