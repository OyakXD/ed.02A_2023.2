#include <iostream>

using namespace std;

int main(){
    int square[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) cin >> square[i][j];

    int sum = 0;
    for(int i = 0; i < 3; i++) sum += square[0][i];

    for(int i = 0; i < 3; i++){
        int tmp = 0;
        for(int j =  0; j < 3; j++) tmp += square[i][j];
            if(tmp != sum) {
                cout << "nao\n";
                return 0;
            }
    }

    cout <<  "sim\n";
    return 0;
}