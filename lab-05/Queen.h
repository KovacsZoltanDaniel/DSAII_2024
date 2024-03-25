//
// Created by Dani on 2024. 03. 21..
//

#ifndef LAB_05_QUEEN_H
#define LAB_05_QUEEN_H
#include <iostream>

using namespace std;

void Bt(int *x, int n, int k);
void kiir(int *x, int n,int*array2);
void kerekpar(int *x,int n, int k);
void descartes(int *x, int n, int k);
void permutacio(int *x, int n, int k);
bool igeretes(int *x, int k);
bool ellenorizKombinacio(int * array, int index);
void Kombinacio(int * array, int n, int k, int index,int *array2);
bool ellenorizVariacio(int * array, int index);
void Variacio(int * array, int n, int k, int index);
void kiralyno(int *x, int n, int k);
bool igereteskiralyno(int *x, int k);

#endif //LAB_05_QUEEN_H
