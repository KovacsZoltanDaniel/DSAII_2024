//
// Created by Dani on 2024. 04. 29..
//


#ifndef LAB_10_DINAMIKUS_H
#define LAB_10_DINAMIKUS_H

#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define VEGTELEN 99999

using namespace std;

int minCoins(int S, int n, vector<int>& w);
void printMatrix(int **c, int n);
int minimum(int x, int y);
int maximum(int x, int y);
void readArray(const char * filename, int * n, int ** a);
void backwards(int **c, int n, int * a, int result);
void printFlowers(int ** e, int ** c, int i, int j);
void createAestheticImpact(int ** e, int ** c, int n, int m);
void readFlowerFile(const char * filename, int ***e, int *n, int *m);

#endif //LAB_10_DINAMIKUS_H
