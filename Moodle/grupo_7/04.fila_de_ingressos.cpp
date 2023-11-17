#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> peoples;
    for (int i = 0; i < n; i++) {
        int people_id;
        cin >> people_id;
        peoples.push_back(people_id);
    }

    int m;
    cin >> m;
    vector<int> peoples_left;
    for (int i = 0; i < m; i++) {
        int peoples_id;
        cin >> peoples_id;
        peoples_left.push_back(peoples_id);
    }

    // imprimir as pessoas que permeneceram na fila

    for (int i = 0; i < n; i++) {
        bool is_in = true;
        for (int j = 0; j < m; i++) {
            if (peoples[i] == peoples_left[j]) {
                is_in = false;
                break;
            }
        }
        if (is_in) {
            cout << peoples[i];
            if (n < i) {
                cout << " ";
            }
        }
    }
}