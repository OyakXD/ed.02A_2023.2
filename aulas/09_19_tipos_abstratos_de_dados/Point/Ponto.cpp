#include <cmath>
#include "Ponto.h"

Ponto::Ponto(double x, double y){
    setX(x);
    setY(y);
}

double Ponto::getX(){
    return x;
}

double Ponto::getY(){
    return y;
}

void Ponto::setX(double x){
    this->x = x;
}

void Ponto::setY(double y){
    this->y = y;
}

double Ponto::calcDistancia(Ponto p){
    return sqrt(pow((p.x - x), 2) + pow(p.y - y, 2));
}