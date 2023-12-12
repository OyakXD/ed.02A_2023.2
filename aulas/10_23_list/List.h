#ifndef LIST_H
#define LIST_H
#include <stdexcept>
#include "Node.h"

/**
 * @brief Classe que implementa uma lista
 * duplamente encadeada circular com nó sentinela
 */
class List {
private:
    Node *m_head{};     // ponteiro para o no sentinela
    unsigned m_size{};  // numero de elementos na lista

public:
    // Construtor default: cria lista vazia
    List() {
        m_head = new Node(0,nullptr,nullptr);
        m_head->prev = m_head;
        m_head->next = m_head;
    }
    // Insere no final da lista
    // Compelxidade: O(1)
    void push_back(const int& val) {
        Node *aux = new Node(val, m_head->prev, m_head);
        m_head->prev->next = aux;
        m_head->prev = aux;
        m_size++;
    }
    // Remove do final O(1)
    void pop_back() {
        if(m_size != 0) {
            Node *aux = m_head->prev;
            m_head->prev = aux->prev;
            aux->prev->next = m_head;
            delete aux;
            m_size--;
        }
    }
    // Retorna o valor do ultimo elemento
    int& back() {
        if(m_size == 0) {
            throw std::runtime_error("lista vazia");
        }
        return m_head->prev->data;
    }
    const int& back() const {
        if(m_size == 0) {
            throw std::runtime_error("lista vazia");
        }
        return m_head->prev->data;
    }
    // limpa a lista
    void clear() {
        while(m_size != 0) {
            pop_back();
        }
    }
    // Destrutor: deixa lista vazia
    ~List() {
        clear();
        delete m_head;
    }
    // Diz se esta vazio
    bool empty() const {
        return m_size == 0;
    }

};

#endif 