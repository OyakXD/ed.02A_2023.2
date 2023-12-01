#ifndef QUEUE_H
#define QUEUE_H

#include <stack>

// Fila implementada com duas pilhas.
class Queue {
   private:
    // Duas pilhas representando o depósito e a prateleira.
    std::stack<int> deposit;
    std::stack<int> shelf;

    // Transfere todos os elementos do depósito para a prateleira.
    void transfer();


   public:
    // Insere um elemento na fila, colocando-o no depósito.
    void enqueue(int x);

    // Remove um elemento da fila, retirando-o da prateleira.
    void dequeue();

    // Retorna o elemento da frente da fila, ou seja, o elemento que está no
    // topo da prateleira.
    int front();

    // Retorna se a fila está vazia, ou seja, se o depósito e a prateleira estão
    bool isEmpty();
};

#endif
