#ifndef STACK_H
#define STACK_H
#include <exception>
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

template <typename Type>
class Stack {
   private:
    Node<Type> *m_top{};
    unsigned m_size{};

   public:
    Stack() = default;

    Stack(std::initializer_list<Type> list) {
        for (const Type elem : list) {
            push(elem);
        }
        /*
        for (auto it = list.begin(); it != list.end(); it++) {
            push(*it);
        }
        */
    }

    void push(const Type &val) {
        m_top = new Node<Type>(val, m_top);
        m_size++;
    }

    void pop() {
        if (m_top != nullptr) {
            Node<Type> *aux = m_top;
            m_top = m_top->next;
            aux->next = nullptr;
            delete aux;
            m_size--;
        }
    }

    bool empty() const { return m_top == nullptr; }

    Type &top() {
        if (empty()) {
            std::out_of_range("empty stack");
        }
        return m_top->value;
    }

    const Type &top() const {
        if (empty()) {
            std::out_of_range("empty stack");
        }
        return m_top->value;
    }

    unsigned size() const { return m_size; }

    ~Stack() { delete m_top; }
};

#endif