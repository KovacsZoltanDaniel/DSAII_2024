#include <iostream>
#include "../header/functions.h"
using namespace std;
#include <fstream>



int main() {
    ifstream inputFile("input.txt");
    int target;
    inputFile >> target;

    vector<int> nums;
    int num;
    while (inputFile >> num) {
        nums.push_back(num);
    }
    for(auto &oke:nums){
        cout << oke << " ";
    }
    cout << endl;
    vector<vector<int>> result;
    vector<int> combination;
    backtracking(nums, target, combination, result, 0);

    for (const auto& comb : result) {
        cout << "[";
        for (int i = 0; i < comb.size(); ++i) {
            cout << comb[i];
            if (i != comb.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
