//
// Created by Dani on 2024. 04. 29..
//


#ifndef LAB_10_DINAMIKUS_H
#define LAB_10_DINAMIKUS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>


#define VEGTELEN 99999

using namespace std;

void erme(int S, int n, int *w);
void baratsagos(vector<int> a);
vector<vector<int>> haromszogBeolvas(const string& filename);
void haromszogKiir(vector<vector<int>> a);
void haromszogOptimalizalas(const vector<vector<int>>& a);
int esztetika(vector<vector<int>>& e, int n, int m);
vector<vector<int>> matrixBeolvas(string filename);
void matrixKiir(vector<vector<int>> a);

#endif //LAB_10_DINAMIKUS_H
