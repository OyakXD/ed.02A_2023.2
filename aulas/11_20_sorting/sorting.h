#ifndef SORTING_H
#define SORTING_H

void insertionSort(int A[], int n) {
    for(int j = 1; j < n; j++) {
        int key = A[j];
        int i = j-1;
        while(i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

void selectionSort(int A[], int n) {
    for(int i = 0; i < n-1; i++) {
        int indexMin = i;
        for(int j = i+1; j < n; j++) {
            if(A[j] < A[indexMin]) {
                indexMin = j;
            }
        }
        int aux = A[i];
        A[i] = A[indexMin];
        A[indexMin] = aux;
    }
}

int partition(int A[], int l, int r) {
    int pivo = A[r];
    int j = l;
    for(int k = l; k < r; k++) {
        if(A[k] <= pivo) {
            int aux = A[k];
            A[k] = A[j];
            A[j] = aux;
            j++;
        }
    }
    A[r] = A[j];
    A[j] = pivo;
    return j;
}

void quicksort(int A[], int l, int r) {
    if(l < r) {
        int j = partition(A, l, r);
        quicksort(A, l, j-1);
        quicksort(A, j+1, r);
    }
}

#endif