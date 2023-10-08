#ifndef PONTO_H
#define PONTO_H
#include <math.h>
class ponto{
private:
    double x, y;
    
public:
    void set_x(double x){
        this->x = x;
    }
    void set_y(double y){
        this->y = y;
    }

    double get_x(){
        return x; 
    }
    double get_y(){
        return y;
    }


    double distancia(double x, double y){
        return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
    }
};

 # endif
