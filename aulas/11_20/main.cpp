#include <iostream>
#include <chrono>
#include <cstdlib>
#include "sorting.h"
using namespace std;

int main() {
    srand(time(nullptr));
    int n = 1000;
    int v1[n], v2[n], v3[n];
    for(int i = 0; i < n; i++) {
        v1[i] = v2[i] = v3[i] = rand() % 2000;
    }

    auto start = chrono::system_clock::now();
    quicksort(v3, 0, n-1);
    auto end = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "quicksort = " << duration.count() << " ms\n";

    start = chrono::system_clock::now();
    insertionSort(v1, n);
    end = chrono::system_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "insertion = " << duration.count() << " ms\n";

    start = chrono::system_clock::now();
    selectionSort(v2, n);
    end = chrono::system_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "selection = " << duration.count() << " ms\n";
}