#include <iostream>
#include <string>

using namespace std;

bool is_vowel(char c) {
    return string("aeiou").find(tolower(c)) != string::npos;
}

int main() {
    string str;
    getline(cin, str);
    
    int i = 0;
    while (str[i] != '\0') {
        if (is_vowel(str[i]) && str[i + 2] == str[i]) {
            while (str[i + 1] == ' ' || str[i + 1] == str[i]) {
                i++;
                if (str[i + 1] != ' ') i++;
            }
        }
        cout << str[i];
        i++;
    }
    cout << endl;
    return 0;
}