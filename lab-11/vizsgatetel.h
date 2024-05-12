//
// Created by Dani on 2024. 05. 09..
//

#ifndef LAB_11_VIZSGATETEL_H
#define LAB_11_VIZSGATETEL_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Szemely {
    string nev;
    int kor;
    int nem;
    int emelet;
};

void szemelyekBeolvasas(vector<Szemely>& szemelyek, ifstream& file);
void szemelyekKiirasa(const vector<Szemely>& szemelyek);
void atlagEletkor(const vector<Szemely>& szemelyek);
int minimalisOsszVarakozasiIdo(vector<Szemely>& szemlyek);
bool emeletSzerintNovekvo(const Szemely& szemely1, const Szemely& szemely2);
int binarySearch(const int *x, int n,int size, int target);
void Queen(int *x, int n, int k);
void bastya(int *x,int n, int k);
bool igeretes(int *x, int k);
bool igeretes2(int *x, int k);



#endif //LAB_11_VIZSGATETEL_H
