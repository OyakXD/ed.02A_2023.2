#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>

#include "Node.h"
template <typename Type>
class BinaryTree {
   private:
    Node<Type> *m_root;  // Ponteiro para a raiz da árvore

   public:
    // Construtor vazio
    BinaryTree() { m_root = nullptr; }

    // Contrutor que cria uma árvore a partir de outras duas
    BinaryTree(const Type &val, BinaryTree<Type> &t1, BinaryTree<Type> &t2) {
        m_root = new Node<Type>(val, t1.m_root, t2.m_root);
    }

    void preOrder() { 
        preOrder(m_root); 
    }
    void postOrder() { 
        postOrder(m_root); 
    }
    void inOrder() { 
        inOrder(m_root); 
    }

   private:
    // Função recursiva que percorre a árvore em pré-ordem
    void preOrder(Node<Type> *node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->m_data << " ";
        preOrder(node->m_left);
        preOrder(node->m_right);
    }

    void postOrder(Node<Type> *node) {
        if (node == nullptr) {
            return;
        }
        postOrder(node->m_left);
        postOrder(node->m_right);
        std::cout << node->m_data << " ";
    }

    void inOrder(Node<Type> *node) {
        if (node == nullptr) {
            return;
        }
        inOrder(node->m_left);
        std::cout << node->m_data << " ";
        inOrder(node->m_right);
    }
};

#endif