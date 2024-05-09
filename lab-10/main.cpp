#include <iostream>
#include <vector>
using namespace std;

#include "dinamikus.h"

int main() {

    int S = 10; // Például: 10 Ft-ot szeretnénk kifizetni
    int n = 3; // 3 féle érme áll rendelkezésünkre
    int w[] = {1, 3, 4}; // Az érmék értékei
    cout << "Penzermek fuggveny kimenete:\n";
    erme(S, n, w);
    cout << endl;


    vector<int> baratsagos_parbaj_pontszamok = {19, 2, 4, 16,3,15,4,14,17,1};
    cout << "Baratsagos parbaj fuggveny kimenete:\n";
    baratsagos(baratsagos_parbaj_pontszamok);
    cout << endl;


    cout << "Haromszog beolvasasa fuggveny kimenete:\n";
    vector<vector<int>> haromszog_matrix = haromszogBeolvas("haromszog.txt");
    haromszogKiir(haromszog_matrix);
    cout << endl;


    cout << "Haromszog optimalizalasa fuggveny kimenete:\n";
    haromszogOptimalizalas(haromszog_matrix);
    cout << endl;


//    cout << "Max esztetikai osszhatas fuggveny kimenete:\n";
//    vector<vector<int>> esztetikai_matrix = matrixBeolvas("flowershop.txt");
//    cout << "Max esztetikai osszhatas: " << esztetika(esztetikai_matrix, esztetikai_matrix.size(), esztetikai_matrix[0].size()) << endl;
//    cout << endl;




    return 0;
}