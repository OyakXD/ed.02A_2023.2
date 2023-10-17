#include <iostream>

using namespace std;

int main() {
    int quarter[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) quarter[i][j];

    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (quarter[i][j] > quarter[i + 1][j]) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}