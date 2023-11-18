#include "Queue.h"
#include <stdexcept>

// Insere um elemento na fila, colocando-o no depósito.
void Queue::enqueue(int x) { 
    deposit.push(x); 
}

// Remove um elemento da fila, retirando-o da prateleira.
// Se a prateleira estiver vazia, transfere todos os elementos do depósito para
// a prateleira.
void Queue::dequeue() {
    if (shelf.empty()) {
        transfer();
    }

    // Remove um elemento da prateleira.
    if (!shelf.empty()) {
        shelf.pop();
    }
}

// Retorna o elemento da frente da fila, ou seja, o elemento que está no topo
// da prateleira.
// Se a prateleira estiver vazia, transfere todos os elementos do depósito para
// a prateleira.
int Queue::front() {
    if (isEmpty()) {
        throw new std::runtime_error("Queue is empty");
    }
    
    if (shelf.empty()) {
        transfer();
    }

    return shelf.top();

}

// Transfere todos os elementos do depósito para a prateleira.
void Queue::transfer() {
    while (!deposit.empty()) {
        shelf.push(deposit.top());
        deposit.pop();
    }
}

// Retorna se a fila está vazia, ou seja, se o depósito e a prateleira estão
// vazios.
bool Queue::isEmpty() { 
    return deposit.empty() && shelf.empty(); 
}
