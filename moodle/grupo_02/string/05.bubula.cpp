#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

bool is_vowel(char c) {
    return string("aeiou").find(tolower(c)) != string::npos;
}

int main() {
    string str, word;
    string result;

    getline(cin, str);
    stringstream ss(str);

    while (ss >> word) {
        string processed = word;
        for (int i = 0; i < word.size() - 1; i++) {
            if (is_vowel(word[i]) && !is_vowel(word[i + 1])) {
                string syllable = word.substr(0, i + 1);
                processed = syllable + syllable + syllable + word.substr(i + 1);
                break;
            }
        }
        result += processed + " ";
    }
    result.pop_back();
    cout << result << endl;
    return 0;
}
