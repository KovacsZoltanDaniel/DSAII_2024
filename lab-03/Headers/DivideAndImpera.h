//
// Created by Dani on 2024. 03. 04..
//

#ifndef DSAII_2024_DIVIDEANDIMPERA_H
#define DSAII_2024_DIVIDEANDIMPERA_H
#include <iostream>
#include <fstream>

using namespace std;

void Read(int *&array, int &n, ifstream &f);
void Print(int *a, int n);
void mergesort(int *a, int i, int j);
void osszefesul(int *a, int i, int k, int j);
#endif //DSAII_2024_DIVIDEANDIMPERA_H
