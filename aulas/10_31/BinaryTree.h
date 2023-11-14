#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include "Node.h"

template <typename Type>
class BinaryTree {
private:
    Node<Type>* m_root {}; // ponteiro para a raiz

public:
    // Construtor vazio
    BinaryTree() = default;

    // Construtor que cria uma arvore a
    // partir de outras duas
    BinaryTree(const Type& val, 
               BinaryTree<Type>& tleft, 
               BinaryTree<Type>& tright) 
    {
        m_root = new Node<Type>(val,tleft.m_root,tright.m_root);
        tleft.m_root = tright.m_root = nullptr;
    }

    // Funcao que retorna true se e somente se 
    // a arvore estiver vazia
    bool empty() const {
        return m_root == nullptr;
    }

    // Funcao publica que imprime as chaves em 
    // pre-ordem
    void preOrder() const {
        preOrder(m_root);
    }
    // pos-ordem
    void postOrder() const {
        postOrder(m_root);
    }
    // ordem simetrica
    void inOrder() const {
        inOrder(m_root);
    }
    
    // Funcao publica que retorna se um certo valor
    // esta na arvore
    bool contains(const Type& val) const {
        contains(m_root, val);
    }



private:
    // funcao recursiva que percorre a arvore
    // em pre-ordem
    void preOrder(Node<Type>* node) const {
        if(node != nullptr) {
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    // funcao recursiva que percorre a arvore
    // em pos-ordem
    void postOrder(Node<Type>* node) const {
        if(node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->data << " ";
        }
    }
    // funcao recursiva que percorre a arvore
    // em ordem simetrica
    void inOrder(Node<Type>* node) const {
        if(node != nullptr) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    // Funcao recursiva que recebe a raiz de uma
    // arvore e um certo valor val e retorna true
    // se e somente se a arvore contem val
    // como uma de suas chaves
    bool contains(Node<Type> *node, const Type& val) const {
        if(node == nullptr) 
            return false;
        return (node->data == val) ||
               contains(node->left, val) ||
               contains(node->right, val);
    }

    // Funcao recursiva que recebe
    // a raiz de uma arvore e 
    // deleta todos os seus nos
    // Retorna a arvore vazia
    Node<Type>* clear(Node<Type> *node) {
        if(node == nullptr) { // caso base
            return nullptr;
        }
        else{ // caso geral
            // terminar
        }
    }

};

#endif //BINARY_TREE_H