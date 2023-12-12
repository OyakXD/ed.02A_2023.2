#ifndef LIST_H
#define LIST_H
#include <stdexcept>
#include <initializer_list>
#include "Node.h"

/***************************************************
 * @brief Classe que implementa um iterador
 * do tipo bidirecional para a nossa lista 
 * duplamente encadeada 
 */
class iterator_list {
private:
    // Classe amiga
    friend class List;
    // Atributo
    Node* m_ptr{};

public:
    // Construtor
    iterator_list() = default;
    // Construtor que recebe endereço
    iterator_list(Node *ptr) {
        m_ptr = ptr;
    }
    bool operator==( const iterator_list& it ) {
        return m_ptr == it.m_ptr;
    }
    bool operator!=( const iterator_list& it ) {
        return m_ptr != it.m_ptr;
    }
    int& operator*() {
        return m_ptr->data;
    }
    // pre-incremento
    iterator_list& operator++() {
        m_ptr = m_ptr->next;
        return *this;
    }
    // pos-incremento
    iterator_list operator++(int) {
        iterator_list temp = *this;
        m_ptr = m_ptr->next;
        return temp;
    }
    // pre-decremento
    iterator_list& operator--() {
        m_ptr = m_ptr->prev;
        return *this;
    }
    // pos-decremento
    iterator_list operator--(int) {
        iterator_list temp = *this;
        m_ptr = m_ptr->prev;
        return temp;
    }
}; // Fim da classe iterator_list

/*********************************************************
 * @brief Classe que implementa uma lista
 * duplamente encadeada circular com nó sentinela
 */
class List {
private:
    Node *m_head{};     // ponteiro para o no sentinela
    unsigned m_size{};  // numero de elementos na lista

public:
    using iterator = iterator_list;  

    // retorna um iterador para o primeiro elemento
    iterator begin() {
        return iterator(m_head->next);
    }

    // retorna um iterador para o node apos o ultimo elemento
    iterator end() {
        return iterator(m_head);
    }

    // Insere um novo elemento antes do iterador position.
    // Retorna um iterador apontando para o 
    // elemento recem-inserido.
    iterator insert(iterator position, const int& val) {
        Node* temp = new Node(val, position.m_ptr->prev, position.m_ptr);
        position.m_ptr->prev->next = temp;
        position.m_ptr->prev = temp;
        m_size++;
        return iterator(temp);
    }

    // Remove o elemento apontado pelo iterador position.
    // Retorna um iterador apontando para o elemento 
    // logo apos o elemento que foi removido. 
    // Se a função apagou o último elemento,
    // o valor retornado é o iterador end().
    iterator erase(iterator position) {
        iterator temp(position.m_ptr->next);
        position.m_ptr->prev->next = temp.m_ptr;
        temp.m_ptr->prev = position.m_ptr->prev;
        delete position.m_ptr;
        m_size--;
        return temp;
    }

    // Construtor default: cria lista vazia
    List() {
        m_head = new Node(0,nullptr,nullptr);
        m_head->prev = m_head;
        m_head->next = m_head;
    }

    // Construtor com lista inicializadora
    List(const std::initializer_list<int> lst) : List() {
        for(const int& elem : lst) {
            push_back(elem);
        }
    }

    // Diz se esta vazio
    bool empty() const {
        return m_size == 0;
    }

    unsigned size() const {
        return m_size;
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

};

#endif 