#include <iostream>
#include <iomanip>
#include "math.hpp"

int main(){
    int x{}, y{};
    std:: cout << "Digite dois inteiros: ";
    std:: cin >> x >> y;

    std:: cout << "Soma = " << ufc::sum(x, y) << "\n";
    std:: cout << "Subtração = " << ufc::sub(x, y) << "\n";
    std:: cout << "Multiplicação = " << ufc::mul(x, y) << "\n";
    std:: cout << "Divisão = " << ufc::div(x, y) << "\n";

    return 0;
}

/*
"cpp": "cd $dir && g++ -std=c++17 -Wall -Wextra -pedantic-errors $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",*/