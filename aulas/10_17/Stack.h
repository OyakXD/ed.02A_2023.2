#ifndef STACK_H
#define STACK_H
#include <initializer_list>

/***********************************************************
 * @brief Classe que implementa um Node da fila
 * @tparam Type tipo do Node
 */
template <typename Type>
struct Node {
    Type value;
    Node *next;

    Node(const Type &val, Node *nextPtr) {
        value = val;
        next = nextPtr;
    }

    ~Node() { delete next; }

};  // fim da classe Node<T>

template <typename type>
class Stack {
   private:
    Node<Type> *m_top{};
    unsigned m_size{};

   public:
    Stack() = default;

    void push(const Type &val) {
        m_top = new Node<type>(val, m_top);
        m_size++;
    }
};

#endif