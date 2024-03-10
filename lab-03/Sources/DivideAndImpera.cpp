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

void mergesort(int *a, int begin, int end) {
    int mid;
    if (begin < end){
        mid = (begin + end) / 2;
        mergesort(a, begin, mid);
        mergesort(a, mid + 1, end);
        osszefesul(a, begin, mid, end);
    }
}



void osszefesul(int *x, int bal, int kozep, int jobb) {
    int *a=new int[kozep-bal+1];
    int *b=new int[jobb-kozep];
    for (int i = bal; i <= kozep; ++i) {
        a[i] = x[i];
    }
    for (int i = kozep+1; i <= jobb; ++i) {
        b[i] = x[i];
    }
    a[kozep+1] = INT_MAX;
    b[jobb+1] = INT_MAX;
    int i = bal;
    int j = kozep+1;
    for (int k = bal; k <= jobb; ++k) {
        if(a[i] < b[j]){
            x[k] = a[i];
            i++;
        }
        else{
            x[k] = b[j];
            j++;
        }
    }
    delete[] a;
    delete[] b;
}

int maximum(int *a, int i, int j) {
    int m1, m2;
    if(i == j){
        return i;
    }
    else{
        m1 = maximum(a,i,(i+j)/2);
        m2 = maximum(a,(i+j)/2+1,j);
        if(a[m1] > a[m2]){
            return m1;
        }
        else{
            return m2;
        }
    }
}
