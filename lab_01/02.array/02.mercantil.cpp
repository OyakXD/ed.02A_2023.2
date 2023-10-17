#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    float prices[n];
    for (int i = 0; i < n; i++) cin >> prices[i];

    float playerA[n];
    for (int i = 0; i < n; i++) cin >> playerA[i];

    int countA = 0, countB = 0;
    char playerB[n];
    for (int i = 0; i < n; i++) {
        cin >> playerB[i];
        if (playerA[i] == prices[i] ||
            (playerA[i] > prices[i] && playerB[i] == 'M') ||
            (playerA[i] < prices[i] && playerB[i] == 'm'))
            countA++;
        else
            countB++;
    }

    if (countA > countB)
        cout << "primeiro\n";
    else if (countA < countB)
        cout << "segundo\n";
    else
        cout << "empate\n";

    return 0;
}
