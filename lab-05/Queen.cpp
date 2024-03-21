//
// Created by Dani on 2024. 03. 21..
//

#include "Queen.h"

void kiir(int *array, int n){
    for (int i = 1; i <= n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void kiir1(int *array, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(array[j] == i){
                cout << "Q";
            }
        }
    }
    cout << endl;
}


void kiralyno(int *x, int n, int k) {
    static int outputCount=0;
    for(x[k] = 1; x[k] <= n; ++x[k]){
        if(igereteskiralyno(x,k)){
            if(k < n ){
                kiralyno(x,n,k+1);
            }
            else{
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j) {
                        if(x[j] == i){
                            cout << " Q ";
                        }
                        else{
                            cout << " * ";
                        }
                    }
                    cout << endl;
                }
                outputCount++;
                cout << endl;
            }
        }
    }
    if(k == 1){
        cout << "Number of outputs: " << outputCount << endl;
    }
}

bool igereteskiralyno(int *x, int k) {
    for (int i = 1; i <= k-1 ; ++i) {
        if(x[i] == x[k] || (k-i) == abs(x[k]-x[i])){
            return false;
        }
    }
    return true;
}
