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

    int x[] = {1, 3, 5, 6, 8, 18, 19, 88};
    int n = 0;
    int size = sizeof(x) / sizeof(x[0]);
    int result = binarySearch(x,n,size,6);
    cout << result << endl;
    cout << "Ird be az n erteket a sakktablahoz: " << endl;
    cout << endl;
    cin >> n;
    cout << endl;
    int *array = new int[n];
    Queen(x,n,1);
    bastya(x,n,1);
    return 0;
}
