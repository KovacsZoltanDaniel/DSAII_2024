//
// Created by Dani on 2024. 04. 11..
//

#ifndef LAB_07_GREEDYBACKT_H
#define LAB_07_GREEDYBACKT_H

#include <iostream>
#include <vector>


using namespace std;

void Bt(int i, int j, int s, int **a, int n,int &Min);
int G(int i, int j, int s, int **a, int n);
struct Food {
    string name;
    int calories;
    float gramm;

    Food(string n, int c, float g);
};


vector<Food> readFoodsFromFile(const string& filename);

vector<pair<string, int>> selectMenu(const vector<Food>& foods, int maxCalories);

#endif //LAB_07_GREEDYBACKT_H

