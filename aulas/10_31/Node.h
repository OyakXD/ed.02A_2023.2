#ifndef NODE_H
#define NODE_H

template <typename Type>
struct Node {
    Type m_data;          // Dado armazenado no nó
    Node<Type> *m_left;   // Ponteiro para o filho esquerdo
    Node<Type> *m_right;  // Ponteiro para o filho direito

    Node(const Type &d, Node<Type> *l = nullptr, Node<Type> *r = nullptr) {
        data = d;
        m_left = l;
        m_right = r;
    }
};

#endif