#include <iostream>
#include <fstream>

using namespace std;



int main() {
    int szamok[10];
    int n = 0;


    string filename = "baratsagos.txt";


    ifstream file(filename);
    if (!file.is_open()) {
       cerr << "Hiba: A fajl (" << filename << ") nem nyithato meg." << endl;
        return 1;
    }


    while ( file >> szamok[n]) {
        n++;
    }


    file.close();


   cout << "Beolvasott szamok:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << szamok[i] << " ";
    }
    cout << endl;

    return 0;
}
