#include <iostream>
#include <iomanip>

using namespace std;

int prime(int a, int b){
    for(int i = a; i <= b; i++){
        int j;
        for(j = 2; i % j; j++);
        if(i == j) cout << j << endl;
        
    }
    return 1;
}

int main(){
    int a, b;
    cin >> a >> b;

    prime(a, b);
    return 0;
}