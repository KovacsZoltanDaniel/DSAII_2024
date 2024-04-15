//
// Created by Dani on 2024. 04. 15..
//

#include "../header/functions.h"

void backtracking(vector<int>& nums, int target, vector<int>& combination, vector<vector<int>>& result, int start) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        if (target - nums[i] >= 0) {
            combination.push_back(nums[i]);
            backtracking(nums, target - nums[i], combination, result, i); //ha csak egyszer hasznaljuk fel akkor ide i helyett i+1 kell
            combination.pop_back();
        }
    }
}
