//
// Created by Dani on 2024. 05. 28..
//

#include "Greedy.h"
int minMushrooms(vector<int>& mushrooms, int target_weight) {

    sort(mushrooms.rbegin(), mushrooms.rend());

    int current_weight = 0;
    int count = 0;


    for (int weight : mushrooms) {
        current_weight += weight;
        count++;
        if (current_weight == target_weight) {
            return count;
        }
    }

    return -1;
}