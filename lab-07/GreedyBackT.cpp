//
// Created by Dani on 2024. 04. 11..
//

#include "GreedyBackT.h"

void Bt(int i, int j, int s, int **a, int n,int &Min) {
    s += a[i][j];
    if(i == n-1) {
        if (s < Min) {
            Min = s;
        }
    }
    else{
        Bt(i+1,j,s,a,n,Min);
        Bt(i+1,j+1,s,a,n,Min);
    }
}

int G(int i, int j, int s, int **a, int n) {
    s += a[i][j];
    if(i < n-1){
        if(a[i+1][j] < a[i+1][j+1]){
            return G(i+1,j,s,a,n);
        }
        else{
            return G(i+1,j+1,s,a,n);
        }
    }
    return s;
}
