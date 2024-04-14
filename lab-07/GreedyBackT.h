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

    Food(string n, int c);
};

vector<pair<string, int>> selectMenu(const vector<Food>& foods, int maxCalories);
void printMenu(const vector<pair<string, int>>& menu);
vector<Food> readFoodsFromFile(const string& filename);

#endif //LAB_07_GREEDYBACKT_H

