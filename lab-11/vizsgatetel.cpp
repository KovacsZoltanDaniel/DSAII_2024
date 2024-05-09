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
        szemelyek[i].nev = csaladnev + " " + keresztnev;
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
    int n = szemelyek.size();

    sort(szemelyek.begin(), szemelyek.end(), emeletSzerintNovekvo);
    int osszVarakozasiIdo = 0;
    for (int i = 0; i < n - 1; ++i) {
        osszVarakozasiIdo += szemelyek[i].emelet * 2;
        cout << szemelyek[i].nev << endl;
    }
    return osszVarakozasiIdo;
}
