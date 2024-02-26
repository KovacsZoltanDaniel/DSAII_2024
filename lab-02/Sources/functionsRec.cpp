//
// Created by Dani on 2024. 02. 26..
//

#include "../Headers/functionsRec.h"

int lnkoRec(int a, int b) {
    if (a == b)
        return a;
    else if (a > b)
        return lnkoRec(a - b, b);
    else
        return lnkoRec(a, b - a);
}

int lkktRec(int a, int b, int a1, int b1) {
    if (a == b)
        return a;
    else if (a > b)
        return lkktRec(a - b, b, a1, b1);
    else
        return lkktRec(a, b - a, a1, b1);
}

int powerRec(int b, int e) {
    if (e == 0)
        return 1;
    else
        return b * powerRec(b, e - 1);
}


void readArrayRec(int *a, int n, ifstream &f) {
    if (n <= 0) {
        return;
    }
    f >> a[n - 1];
    readArrayRec(a, n - 1, f);
}

void printArrayRec(int *a, int n) {
    if (n <= 0) {
        return;
    }
    cout << a[n - 1] << " ";
    printArrayRec(a, n - 1);
}

int sumArrayRec(int *a, int n) {
    if (n <= 0) {
        return 0;
    }
    return a[n - 1] + sumArrayRec(a, n - 1);
}

int maxArrayRec(int *a, int n, int max) {
    if (n <= 0) {
        return max;
    }
    if (a[n - 1] > max) {
        return maxArrayRec(a, n - 1, a[n - 1]);
    }
    return maxArrayRec(a, n - 1, max);
}

int teszt1(int a, int b) {
    int sum = 1;
    for (int i = 0; i < b; ++i) {
        sum *= a;
    }
    return sum;
}

