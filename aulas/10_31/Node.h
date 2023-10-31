#ifndef NODE_H
#define NODE_H

template <typename Type>
struct Node {
    Type data;          // Dado armazenado no nó
    Node<Type> *left;   // Ponteiro para o filho esquerdo
    Node<Type> *right;  // Ponteiro para o filho direito

    Node(const Type &d, Node<Type> *l = nullptr, Node<Type> *r = nullptr) {
        data = d;
        left = l;
        right = r;
    }
};

#endif