#ifndef FORWARD_LIST_H
#define FORWAR_LIST_H

#include <iostream>

/**
 * @brief Classe que implementa a lógica de um nó da lista
 *
 */

class Node {
    friend class ForwardList;
    friend class iterator_list;

    int data;    // Valor guardado no node
    Node* next;  // Ponteiro para o próximo nó

    // Construtor com dois argumentos
    Node(const int& val, Node* ptrNext) {
        data = val;
        next = ptrNext;
    }

    //~Node() { std::cout << "removido" << data << "\n"; }
};

/**
 * @brief Classe que implementa a lógica de um ForwardIterator
 *
 */
class iterator_list {
   private:
    friend class ForwardList;
    Node* m_ptr;  // Ponteiro para o nó atual

   public:
    // Construtor
    iterator_list(Node* ptr) { m_ptr = ptr; }

    // operador de pré-incremento
    iterator_list& operator++() {
        m_ptr = m_ptr->next;
        return *this;
    }

    // operador de pós-incremento
    iterator_list operator++(int) {
        iterator_list temp = *this;
        m_ptr = m_ptr->next;
        return temp;
    }

    // operador de dereferenciação
    int& operator*() { return m_ptr->data; }

    // operador ==
    bool operator==(const iterator_list& it) const { return m_ptr == it.m_ptr; }

    // operador !=
    bool operator!=(const iterator_list& it) const { return m_ptr != it.m_ptr; }
};

class ForwardList {
   private:
    Node* m_head{};     // Ponteiro para o nó sentinela
    Node* m_tail{};     // Ponteiro para o último nó da lista
    unsigned m_size{};  // Numero de elemento atualmente na lista

   public:
    // Construtor default: cria lista vazia
    // A lista vazia tem um nó sentinela e 0 elementos
    ForwardList() { m_tail = m_head = new Node(0, nullptr); }

    /**
     * @brief Retorna um iterador para o primeiro elemento da lista
     *
     * @return iterator
     */

    iterator_list begin() { return iterator_list(m_head->next); }

    /**
     * @brief Retorna um iterador para o último elemento da lista
     *
     * @return iterator
     */
    iterator_list end() { return iterator_list(m_tail->next); }

    /**
     * @brief Construtor de cópia
     *
     * @param lst   Lista a ser copiada
     */
    ForwardList(const ForwardList& lst) {
        m_tail = m_head = new Node(0, nullptr);
        Node* aux = lst.m_head->next;
        while (aux != nullptr) {
            m_tail->next = new Node(aux->data, nullptr);
            aux = aux->next;
            m_tail = m_tail->next;
        }
        m_size = lst.m_size;
    }

    /**
     * @brief Printa os elementos da lista
     *
     */
    void print() {
        Node* atual = m_head->next;
        while (atual != nullptr) {
            std ::cout << atual->data << " ";
            atual = atual->next;
        }
        std::cout << "\n";
    }

    /**
     * @brief Insere um elemento no começo da lista
     *
     * @param val   Elemento a ser colocado na lista
     */

    void push_front(const int& val) {
        Node* aux = new Node(val, m_head->next);
        m_head->next = aux;
        if (m_size == 0) {
            m_tail = aux;
        }
        m_size++;
    }

    /**
     * @brief Insere um elemento no final da lista
     *
     * @param val   Elemento a ser colocado na lista
     */
    void push_back(const int& val) {
        m_tail->next = new Node(val, nullptr);
        m_tail = m_tail->next;
        m_size++;
    }

    /**
     * @brief Remove o primeiro elemento da lista
     *
     */
    void pop_front() {
        if (m_size == 0) {
            return;
        }
        Node* aux = m_head->next;
        m_head->next = aux->next;
        if (m_tail = aux) {
            m_tail = m_head;
        }
        delete aux;
    }

    /**
     * @brief Remove todos os elementos da lista
     *
     */
    void clear() {
        while (m_head->next != nullptr) {
            Node* temp = m_head->next;
            m_head->next = temp->next;
            delete temp;
        }
        m_size = 0;
        m_tail = m_head;
    }

    /**
     * @brief Destrutor da classe
     *
     */
    ~ForwardList() {
        clear();
        delete m_head;
    }
};

#endif