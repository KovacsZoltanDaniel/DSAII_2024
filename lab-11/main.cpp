#include "vizsgatetel.h"

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Hiba: nem sikerult megnyitni a fajlt!" << endl;
        return 1;
    }

    vector<Szemely> szemelyek;
    szemelyekBeolvasas(szemelyek, file);
    szemelyekKiirasa(szemelyek);
    cout << endl;
    atlagEletkor(szemelyek);
    cout << endl;
    int minimalisIdo = minimalisOsszVarakozasiIdo(szemelyek);

    cout << "Az osszvarakozasi ido minimalis legyen: " << minimalisIdo << endl;

    file.close();
    return 0;
}
