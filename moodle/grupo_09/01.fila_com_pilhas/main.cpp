#include <iostream>

#include "Queue.h"

using namespace std;

int main() {
    // Lê número de operações.
    int q;
    cin >> q;

    // Cria fila.
    Queue queue;

    // Executa operações.
    for (int i = 0; i < q; ++i) {
        // Lê tipo da operação.
        int type;
        cin >> type;

        // Se for 1, é uma operação de inserção.
        if (type == 1) {
            int x;
            cin >> x;
            queue.enqueue(x);

            // Se for 2, é uma operação de remoção.
        } else if (type == 2) {
            queue.dequeue();

            // Se for 3, é uma operação de consulta.
        } else if (type == 3) {
            try {
                cout << queue.front() << endl;
            } catch (runtime_error *e) {
                continue;
            }
        }
    }

    return 0;
}
