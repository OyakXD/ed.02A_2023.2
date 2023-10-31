#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "Node.h"

template <typename Type>
class BinaryTree {
    private:
        Node<Type> *m_root; // Ponteiro para a raiz da árvore
    public:
        // Construtor vazio
        BinaryTree() {
            m_root = nullptr;
        }

        // Contrutor que cria uma árvore a partir de outras duas
        BinaryTree(const Type &val, BinaryTree<Type> &t1, BinaryTree<Type> &t2) {
            m_root = new Node<Type>(val, t1.m_root, t2.m_root);
        }
};

#endif