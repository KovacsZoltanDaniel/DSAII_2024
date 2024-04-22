//
// Created by Dani on 2024. 04. 15..
//

#ifndef LAB_08_FUNCTIONS_H
#define LAB_08_FUNCTIONS_H
#include <iostream>
#include <vector>

using namespace std;

struct Exam {
    string name;
    int score;
    float duration;
};


using namespace std;
void reszHalmazKiiro(int *array, int n);
void reszHalmaz(int *array, int n, int k);
bool igeretesBasic(int *array, int k, int n);

void findCombinations(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& result, int start);
vector<vector<int>> combinationSum(vector<int>& candidates, int target);


bool sortByScore(const Exam &a, const Exam &b);
#endif //LAB_08_FUNCTIONS_H
