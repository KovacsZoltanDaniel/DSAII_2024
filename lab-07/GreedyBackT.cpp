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

Food::Food(string n, int c) : name(n), calories(c) {}

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

void printMenu(const vector<pair<string, int>>& menu) {
    cout << "Panna menuje:" << endl;
    for (const auto& item : menu) {
        cout << "- " << item.first << " (" << item.second << " kcal)" << endl;
    }
}

vector<Food> readFoodsFromFile(const string& filename) {
    vector<Food> foods;
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string name;
            int calories ;
            string word;
            while (ss >> word) {
                // Ellenőrizzük, hogy a szó szám-e
                bool isNumber = true;
                for (char c : word) {
                    if (!isdigit(c)) {
                        isNumber = false;
                        break;
                    }
                }
                // Ha a szó nem szám, akkor az étel nevének tekintjük
                if (!isNumber) {
                    if (!name.empty()) {
                        name += " ";
                    }
                    name += word;
                } else {
                    // Ha szám, akkor az a kalóriatartalom lesz
                    calories = stoi(word);
                    break; // Mivel csak egy kalóriatartalom lehet az adott sorban, kilépünk a ciklusból
                }
            }
            foods.push_back(Food(name, calories));
        }
        file.close();
    } else {
        cout << "Unable to open file";
    }
    return foods;
}