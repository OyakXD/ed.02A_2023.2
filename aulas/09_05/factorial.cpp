#include <iostream>

double factorial(double e){
    if(e == 1) return 1;
    return e * factorial(e - 1);
}