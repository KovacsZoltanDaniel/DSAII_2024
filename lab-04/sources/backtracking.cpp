//
// Created by kovac on 2024. 03. 17..
//

#include "../headers/backtracking.h"

void Bt(int *x, int n, int k) {
    for(x[k] = 0; x[k] <= 9; x[k]++){
        if(k < n - 1){
            Bt(x, n, k+1);
        }else{
            kiir(x, n);
        }
    }
}

void kiir(int *array, int n){
    for (int i = 1; i <= n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}


bool igeretes(int *x, int k) {
    for (int i = 1; i < k-1 ; ++i) {
        if(x[i] == x[k]){
            return false;
        }
    }
    return true;
}


void kerekpar(int *x, int n, int k) {
    for (x[k] = 0; x[k] <= 9; x[k]++) {
        if( k < n){
            kerekpar(x,n,k+1);
        }
        else{
            kiir(x,n);
        }
    }
}

void descartes(int *x, int n, int k) {
    for(x[k] = 1; x[k] <= n; x[k]++){
        if(k < n){
            descartes(x,n,k+1);
        }
        else{
            kiir(x,n);
        }
    }
}


void permutacio(int *x, int n, int k) {
    for(x[k] = 1; x[k] <= n; x[k]++){
        if(igeretes(x,k)){
            if(k < n){
                permutacio(x,n,k+1);
            }
            else{
                kiir(x,n);
            }
        }
    }
}

bool ellenorizKombinacio(int * array, int index)
{
    for (int i = 1; i <= index - 1; i++)
        if(array[i] >= array[index])
            return false;
    return true;
}

void Kombinacio(int * array, int n, int k, int index)
{
    if (index == k + 1)
        kiir(array, k);
    else
        for (int i=1;i<=n;i++)
        {
            array[index]=i;
            if (ellenorizKombinacio(array, index))
                Kombinacio(array, n, k, index + 1);
        }
}


bool ellenorizVariacio(int * array, int index)
{
    for (int i = 1; i <= index - 1; i++)
        if(array[i] == array[index])
            return false;
    return true;
}

void Variacio(int * array, int n, int k, int index)
{
    if (index == k + 1)
        kiir(array, k);
    else
        for (int i=1;i<=n;i++)
        {
            array[index]=i;
            if (ellenorizVariacio(array, index))
                Variacio(array, n, k, index + 1);
        }
}

//void kiralyno(int *x, int n, int k) {
//    for(x[k] = 1; x[k] <= n; ++x[k]){
//        if(igereteskiralyno(x,k)){
//            if(k < n){
//                kiralyno(x,n,k+1);
//            }
//            else{
//                kiir(x,n);
//            }
//        }
//    }
//}

//bool igereteskiralyno(int *x, int k) {
//    for (int i = 1; i < k-1 ; ++i) {
//        if(x[i] == x[k] || ((k-i) == |x[k] - x[i] | )){
//            return false;
//        }
//    }
//    return true;
//}
//
