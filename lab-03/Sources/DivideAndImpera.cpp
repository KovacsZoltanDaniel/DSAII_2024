//
// Created by Dani on 2024. 03. 04..
//

#include "../Headers/DivideAndImpera.h"

void Read(int *&array, int &n, ifstream &f) {
    if(!f){
        cout << "File not found" << endl;
        return;
    }
    f >> n;
    array = new int[n];
    for (int i = 0; i < n; ++i) {
        f >> array[i];
    }
}

void Print(int *a, int n) {
    cout << "A tomb elemei: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void mergesort(int *a, int i, int j) {
    int k;
    if (i < j){
        k = (i + j) / 2;
        mergesort(a, i, k);
        mergesort(a, k + 1, j);
        osszefesul(a, i, k, j);
    }
}

void osszefesul(int *a, int i, int k, int j) {
    int *b = new int[j - i + 1];
    int *c = new int[j - i + 1];
    int n1 = k - i + 1;
    int n2 = j - k;
}
