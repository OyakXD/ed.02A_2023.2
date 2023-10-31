#include <iostream>
#include <vector>

using namespace std;

void kill(vector<int> &elem, int &pos) {
    int p, size = elem.size();
    for (int i = 0; i < size; i++) {
        if (elem[i] == pos) {
            p = i;
            break;
        }
    }

    int kill = (p + 1) % size;
    pos = elem[(kill + 1) % size];
    elem.erase(elem.begin() + kill);
}

int main() {
    int size, pos;
    cin >> size >> pos;

    vector<int> elem;
    for (int i = 0; i < size; i++) {
        elem.push_back(i + 1);
    }

    while (size--) {
        cout << "[ ";
        for (int i = 0; i < elem.size(); i++) {
            if (elem[i] == pos) {
                cout << elem[i] << "> ";
            } else {
                cout << elem[i] << " ";
            }
        }
        cout << "]" << endl;
        kill(elem, pos);
    }
}