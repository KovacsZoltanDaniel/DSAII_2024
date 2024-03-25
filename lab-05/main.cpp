#include "Queen.h"



int main() {
    int n=4;
    int *x = new int[n];
    int array[8] = {100,300,25,156};
    //kiralyno(x,n,1);
    //Bt(x,n,0);
    //descartes(x,n,1);
    //kerekpar(x,n,1);
    //permutacio(x,n,1);
    int k =3;
    int index = 1;
    Kombinacio(x,n,k,index,array);
//    cout << "Kombinaciok:" << endl;
//    for (int k = 0; k < n; ++k) {
//        Kombinacio(x, n, k, 1,array);
//    }
//    cout << endl << "Variaciok:" << endl;
//    for (int k = 1; k <= n; ++k) {
//        Variacio(x, n, k, 1);
//    }
    delete[]x;
    return 0;
}
