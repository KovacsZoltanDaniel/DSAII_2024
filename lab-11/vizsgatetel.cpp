//
// Created by Dani on 2024. 05. 09..
//

#include "vizsgatetel.h"

void szemelyekBeolvasas(vector<Szemely> &szemelyek, ifstream &file) {
    int n;
    file >> n;
    szemelyek.resize(n);
    string csaladnev, keresztnev;
    for (int i = 0; i < n; ++i) {
        file >> csaladnev >> keresztnev >> szemelyek[i].kor >> szemelyek[i].nem >> szemelyek[i].emelet;
        //szemelyek[i].nev = csaladnev + " " + keresztnev;
        szemelyek[i].nev = csaladnev.append(" ").append(keresztnev);
    }
}

void szemelyekKiirasa(const vector<Szemely> &szemelyek) {
    for (const auto &szemely: szemelyek) {
        cout << szemely.nev << " " << szemely.kor << " ";
        if (szemely.nem == 1) {
            cout << "Ferfi " << szemely.emelet << endl;
        } else {
            cout << "No " << szemely.emelet << endl;
        }
    }
}

void atlagEletkor(const vector<Szemely> &szemelyek) {
    int osszFerfiak = 0;
    int osszNok = 0;
    int ferfiakSzama = 0;
    int nokSzama = 0;
    double avg;

    for (const auto &szemely: szemelyek) {
        if (szemely.nem == 1) {
            osszFerfiak += szemely.kor;
            ferfiakSzama++;
        } else {
            osszNok += szemely.kor;
            nokSzama++;
        }
    }
    if (ferfiakSzama > 0) {
        avg = (double) osszFerfiak / (double) ferfiakSzama;
        cout << "Ferfiak atlageletkora: " << avg << endl;
    } else {
        cout << "Nincs ferfi az adatok kozott." << endl;
    }
    if (nokSzama > 0) {
        avg = (double) osszNok / (double) nokSzama;
        cout << "Nok atlageletkora: " << avg << endl;
    } else {
        cout << "Nincs no az adatok kozott." << endl;
    }
}

bool emeletSzerintNovekvo(const Szemely &szemely1, const Szemely &szemely2) {
    return szemely1.emelet < szemely2.emelet;
}

int minimalisOsszVarakozasiIdo(vector<Szemely> &szemelyek) {
    unsigned long long n = szemelyek.size();

    sort(szemelyek.begin(), szemelyek.end(), emeletSzerintNovekvo);
    int osszVarakozasiIdo = 0;

    for (int i = 0; i < n ; ++i) {
        if(i == 5){
            cout << szemelyek[i].nev << endl;
        }
        else{
            osszVarakozasiIdo += szemelyek[i].emelet * 2;
            cout << szemelyek[i].nev << endl;
        }

    }
    return osszVarakozasiIdo;
}

int binarySearch(const int *x, int n,int size, int target) {
    if(n <= size){
        int middle = (n+size)/2;
        if(x[middle] == target){
            return middle;
        }
        if(x[middle] < target){
            return binarySearch(x,middle+1,size,target);
        }
        if(x[middle] > target){
            return binarySearch(x,n,middle-1,target);
        }
    }
    return -8;
}

void Queen(int *x, int n, int k) {
    static int outputCount=0;
    for(x[k] = 1; x[k] <= n; ++x[k]){
        if(igeretes(x,k)){
            if(k < n ){
                Queen(x,n,k+1);
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

bool igeretes(int *x, int k) {
    for (int i = 1; i <= k-1 ; ++i) {
        if(x[i] == x[k] || (k-i) == abs(x[k]-x[i])){
            return false;
        }
    }
    return true;
}
bool igeretes2(int *x, int k) {
    for (int i = 1; i < k; ++i) {
        if (x[i] == x[k]) {
            return false;
        }
    }
    return true;
}

void bastya(int *x,int n, int k) {
    static int outputCount = 0;
    for (x[k] = 1; x[k] <= n; ++x[k]) {
        if (igeretes2(x, k)) {
            if (k == n) {
                ++outputCount ;
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j) {
                        if (x[j] == i) {
                            cout << " R ";
                        } else {
                            cout << " * ";
                        }
                    }
                    cout << endl;
                }
                cout << endl;
            } else {
                bastya(x, n, k + 1);
            }
        }
    }
    if (k == 1) {
        cout << "Number of outputs: " << outputCount << endl;
    }
}