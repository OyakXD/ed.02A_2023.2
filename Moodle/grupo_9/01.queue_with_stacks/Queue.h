#ifndef QUEUE_H
#define QUEUE_H

#include <stack>

class Queue {
   private:
    std::stack<int> deposit;
    std::stack<int> shelf;

   public:
    void enqueue(int x);
    void dequeue();
    int front();
    bool isEmpty();
};

#endif
