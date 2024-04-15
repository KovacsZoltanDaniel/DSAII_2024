//
// Created by Dani on 2024. 04. 11..
//

#include "GreedyBackT.h"
#include <fstream>
#include <sstream>

void Bt(int i, int j, int s, int **a, int n,int &Min) {
    s += a[i][j];
    if(i == n-1) {
        if (s < Min) {
            Min = s;
        }
    }
    else{
        Bt(i+1,j,s,a,n,Min);
        Bt(i+1,j+1,s,a,n,Min);
    }
}

int G(int i, int j, int s, int **a, int n) {
    s += a[i][j];
    if(i < n-1){
        if(a[i+1][j] < a[i+1][j+1]){
            return G(i+1,j,s,a,n);
        }
        else{
            return G(i+1,j+1,s,a,n);
        }
    }
    return s;
}

Food::Food(string n, int c,float g) : name(n), calories(c), gramm(g){}


vector<Food> readFoodsFromFile(const string& filename) {
    vector<Food> foods;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string name;
            int calories;
            float size;
            if (iss >> name >> calories >> size) {
                foods.push_back(Food(name, calories, size));
            }
        }
        file.close();
    } else {
        exit(-1);
    }
    return foods;
}




vector<pair<string, int>> selectMenu(const vector<Food>& foods, int maxCalories) {
    vector<pair<string, int>> menu;

    vector<Food> sortedFoods = foods;
    sort(sortedFoods.begin(), sortedFoods.end(), [](const Food& a, const Food& b) {
        return a.calories < b.calories;
    });

    // Greedy választás
    for (const Food& food : sortedFoods) {
        if (food.calories <= maxCalories) {
            menu.push_back(make_pair(food.name, food.calories));
            maxCalories -= food.calories;
        } else {
            break;
        }
    }

    return menu;
}