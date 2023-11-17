#include <iostream>

#include "Queue.h"

using namespace std;

int main() {
    int q;
    cin >> q;

    Queue queue;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            queue.enqueue(x);
        } else if (type == 2) {
            queue.dequeue();
        } else if (type == 3) {
            int frontValue = queue.front();
            if (frontValue != -1) {
                cout << frontValue << endl;
            }
        }
    }

    return 0;
}
