#ifndef BOX_H
#define BOX_H
#include <string>
#include <iostream>

class Box {
private:
    double height;  // altura
    double width;   // largura
    double length;  // comprimento

public:
    // Destrutor: chamado quando o objeto eh destruido
    ~Box() {
        std::cout << "caixa destruida\n";
    }

    // Construtor default
    Box() : Box(1.0,1.0,1.0) {
        std::cout << "Construtor default foi invocado.\n";
    }

    // Construtor
    Box(double h, double w, double l) {
        set_height(h);
        set_width(w);
        set_length(l);
        std::cout << "Construtor com 3 args foi invocado.\n";
    }

    // Setter: ajusta a altura
    void set_height(double a) {
        if(a >= 0) 
            height = a;
    }
    // Setter: ajusta a largura
    void set_width(double width) {
        if(width >= 0) 
            this->width = width;
    }
    // Setter: ajusta o comprimento
    void set_length(double length) {
        if(length >= 0) 
            this->length = length;
    }
    // Getter: retorna o comprimento
    double get_length() {
        return length;
    }
    // Getter: retorna a largura
    double get_width() {
        return width;
    }
    // Getter: retorna a altura
    double get_height() {
        return height;
    }
    // retorna o volume da caixa
    double volume() {
        return height * width * length;
    }
    std::string to_string() {
        return "Caixa(height:" + std::to_string(height) 
                + ",width:" + std::to_string(width) + 
                ",length:" + std::to_string(length) + ")"; 
    }
};

#endif