#ifndef NODE_H
#define NODE_H
#include <iostream>

/**
 * @brief Node de uma lista duplamente encadeada
 */
struct Node {
    int data;
    Node *prev;
    Node *next;

    Node(const int& d, Node *ptrPrev, Node *ptrNext)
        : data{d}, prev{ptrPrev}, next{ptrNext} {}

    /*~Node() {
        std::cout << "node liberado: " << data << "\n";
    }*/
};

#endif