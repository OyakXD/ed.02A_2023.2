#include <iostream>
#include <iomanip>

using namespace std;

double factorial(double e){
    if(e == 1) return 1;
    else return e * factorial(e - 1);
}

double euler(double n){
    if(n == 0) return 1; 
    return (1 / factorial(n)) + euler(n - 1);


}

int main(){
    int n;
    cin >> n;

    cout << fixed << setprecision(6) << euler(n) << endl;
    return 0;
}