#include "Queue.h"

void Queue::enqueue(int x) { 
    deposit.push(x); 
}

void Queue::dequeue() {
    if (shelf.empty()) {
        while (!deposit.empty()) {
            shelf.push(deposit.top());
            deposit.pop();
        }
    }

    if (!shelf.empty()) {
        shelf.pop();
    }
}

int Queue::front() {
    if (shelf.empty()) {
        while (!deposit.empty()) {
            shelf.push(deposit.top());
            deposit.pop();
        }
    }

    if (!shelf.empty()) {
        return shelf.top();
    }

    return -1;
}

bool Queue::isEmpty() { 
    return deposit.empty() && shelf.empty(); 
}
