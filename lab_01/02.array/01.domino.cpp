#include <iostream>

using namespace std;

bool is_order(int vector[], int n){
    for(int i = 0; i < n - 1; i++) 
        if(vector[i] > vector[i+1]) 
            return 0;
    return 1;
}
int main(){
    int n;
    cin >> n;

    int vector[n];
    for(int i = 0; i < n; i++) cin >> vector[i];
    
    if(is_order) cout << "ok\n";
    else cout << "precisa de ajuste\n";
    
    return 0;
}