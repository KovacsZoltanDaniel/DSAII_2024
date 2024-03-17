#include "Headers/backtracking.h"

int main() {
    int n = 3;
    int *x = new int[n];
    //Bt(x,n,0);
    //kerekpar(x,n,1);
    //descartes(x,n,1);
    //permutacio(x,n,1);
    cout << "Kombinaciok:" << endl;
    for (int k = 1; k <= n; ++k) {
        Kombinacio(x, n, k, 1);
    }
    cout << endl << "Variaciok:" << endl;
    for (int k = 1; k <= n; ++k) {
        Variacio(x, n, k, 1);
    }
    delete[]x;

    return 0;
}
