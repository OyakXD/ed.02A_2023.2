#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

bool is_vowel(char c) {
    return string("aeiou").find(tolower(c)) != string::npos;
}

int main() {
    string str;
    getline(cin, str);

    char opt;
    cin >> opt;

    switch(opt) {
        case 'M':
            for (char& c : str) {
                if (isalpha(c)) {
                    c = toupper(c);
                }
            }
            break;
        case 'm':
            for (char& c : str) {
                if (isalpha(c)) {
                    c = tolower(c);
                }
            }
            break;
        case 'p': {
            stringstream ss(str);
            string word, str_copy;
            while(ss >> word) {
                if(word.size() > 1) {
                    word[0] = toupper(word[0]);
                    for (int i = 1; i < word.size(); i++) {
                        word[i] = tolower(word[i]);
                    }
                } else {
                    word[0] = tolower(word[0]);
                }
                str_copy += word + " ";
            }
            str_copy.pop_back();
            str = str_copy;
            break;
        }
        case 'i':
            for (char& c : str) {
                if (isalpha(c)) {
                    if (isupper(c)) {
                        c = tolower(c);
                    } else {
                        c = toupper(c);
                    }
                }
            }
            break;
    }
    cout << str << endl;
    return 0;
}