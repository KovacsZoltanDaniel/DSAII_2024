//
// Created by Dani on 2024. 04. 15..
//

#include "../header/functions.h"


void reszHalmazKiiro(int *array, int n){
    int v[] = {2, 3, 6, 7};
    for (int i = 0; i < n; ++i) {
        if (array[i] != 0){
            for (int j = 0; j < array[i]; ++j) {
                cout << v[i] << " ";
            }
        }
    }
    cout << endl;
}

void reszHalmaz(int *array, int n, int k) {
    for (array[k] = 0; array[k] <= 1; array[k]++)  {
        if(igeretesBasic(array,k,n)){
            if (k < n - 1 ){
                reszHalmaz(array, n, k + 1);
            }
            else{
                reszHalmazKiiro(array, n);
            }
        }
    }
}

bool igeretesBasic(int *array, int k, int n) {
    int v[] = {2, 3, 6, 7};
    int s = 0;
    if (k == n - 1) {
        for (int i = 0; i <= k; i++) {
            if (array[i] == 1) {
                s = s + v[i];
            }
        }
        if (s != 7) {
            return false;
        }
    }
    return true;
}

void findCombinations(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& result, int start) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] > target)
            continue;
        combination.push_back(candidates[i]);
        findCombinations(candidates, target - candidates[i], combination, result, i);        combination.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;
    findCombinations(candidates, target, combination, result, 0);
    return result;
}


bool sortByScore(const Exam &a, const Exam &b) {
    return a.score > b.score;
}