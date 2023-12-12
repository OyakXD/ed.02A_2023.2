#ifndef PONTO_H
#define PONTO_H

class Ponto {
    private:
        double x;
        double y;
    public:
        Ponto(double x = 1, double y = 1);
        double getX();
        double getY();
        void setX(double x);
        void setY(double y);
        double calcDistancia(Ponto p);
};

#endif