#include <iostream>
#include "../header/functions.h"
using namespace std;
#include <fstream>



int main() {
    ifstream inputFile("input.txt");
    if(!inputFile){
        cout << "Hiba fajl megnyitaskor!" << endl;
        return 1;
    }
    int target;
    inputFile >> target;
    int n = 4;
    int *array = new int[n];
    int counter = 0;
    int num;
    while (inputFile >> num) {
        array[counter] = num;
        counter++;
    }
    cout << "Bemeneti adatok: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    reszHalmaz(array,n,1);

    return 0;
}
