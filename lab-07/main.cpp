#include <iostream>
#include "GreedyBackT.h"
#include <vector>


int main() {
    int n =5;
    int **a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            a[i][j] = 0;
        }
    }
    a[0][0] = 7;
    a[1][0] = 9;
    a[1][1] = 5;
    a[2][0] = 1;
    a[2][1] = 99;
    a[2][2] = 4;
    a[3][0] = 21;
    a[3][1] = 7;
    a[3][2] = 33;
    a[3][3] = 17;
    a[4][0] = 2;
    a[4][1] = 15;
    a[4][2] = 8;
    a[4][3] = 3;
    a[4][4] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " " ;
        }
        cout << endl;
    }
    int Min = INT_MAX;
    Bt(0,0,0,a,n,Min);
    cout << "Minimum BackTracking: " << Min << endl;
    int s = G(0,0,0,a,n);
    cout << "Minimum Greedy: " << s << endl;
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    cout << "\n**************************************************\n" << endl;

    vector<Food> foods = readFoodsFromFile("foods.txt");
    for (const auto& food : foods) {
        cout << food.name << " " << food.calories << endl;
    }

    int maxCalories = 2000;

    vector<pair<string, int>> menu = selectMenu(foods, maxCalories);

    printMenu(menu);
    return 0;
}
