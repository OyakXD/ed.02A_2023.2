#ifndef BST_H
#define BST_H
#include <stdexcept>
#include "node.h"
using namespace std;

class BST { 
public:
    BST();
    ~BST();
    void add(int key);       // Adicionar chave 
    void remove(int key);    // Remover chave
    bool contains(int key);  // A arvore contem esta chave?
    int minimum();           // Devolve chave minima
    int maximum();           // Devolve chave maxima
    int successor(int k);    // Devolve chave sucessora de k
    int predecessor(int k);  // Devolve chave antecessora de k
    void bshow();
private:
    Node *root;
    Node *add(Node *node, int key);
    //Node *search(Node *node, int key); // Comentei pois acabamos implementando uma versao iterativa
    Node *clear(Node *node);
    Node *minimum(Node *node);
    Node *maximum(Node *node);
    Node *ancestral_sucessor(Node *x, Node *raiz);
    Node *ancestral_predecessor(Node *x, Node* raiz);
    Node *sucessor(Node *x, Node *raiz);
    Node *predecessor(Node *x, Node* raiz);
    Node *remove(int k, Node *node);
    Node *removeRoot(Node *node);
    void bshow(Node *node, std::string heranca);
};

// ******************************************************
// Implementacao da funcoes-membro da classe BST
// *******************************************************

// Construtor
BST::BST() {  
    root = nullptr; 
} 

// Destrutor
BST::~BST() {  
    root = clear(root);
} 

// Esta funcao recebe um ponteiro para um node e libera
// os nos da arvore enraizada nesse node. A funcao devolve
// nullptr apos apagar a arvore enraizada em node
Node *BST::clear(Node *node) {  
    if(node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
    }
    return nullptr;
}

void BST::bshow() {
    bshow(root, "");
}

void BST::bshow(Node *node, std::string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->left, heranca + "l");
}

/* // Para ser usada com a versao recursiva de contains()
Node* BST::search(Node *node, int key) {
    if(node == nullptr || node->key == key) {
        return node;
    }
    else if(node->key > key) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}*/

// Funcao publica que retorna true se e somente se a chave esta na arvore.
bool BST::contains(int key) {
    // Versao 1: recursiva
    //if(search(root, key) == nullptr) {
    //    return false;
    //}
    //else return true;
    // -------------------------

    // Versao 2: recursiva, mais enxuta
    //return search(root, key) != nullptr;
    // -------------------------

    // Versao 3: iterativa
    Node *node = root;
    while(node != nullptr && node->key != key) {
        if(node->key < key)
            node = node->right;
        else 
            node = node->left;
    }
    return node != nullptr;
}

// funcao publica que adiciona uma nova chave na arvore binaria de busca
void BST::add(int key) {
    root = add(root, key);
}

// Funcao recursiva que insere uma chave numa arvore binaria de busca
// cuja raiz eh passada por parametro. A funcao retorna a raiz da nova arvore.
Node* BST::add(Node *node, int key) {
    if(node == nullptr) 
        return new Node(key, nullptr, nullptr);
    if(node->key < key)
        node->right = add(node->right, key);
    else    
        node->left = add(node->left, key);
    return node;
}


#endif
