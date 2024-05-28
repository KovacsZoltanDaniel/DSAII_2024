#include "Greedy.h"

int main() {
    vector<int> mushrooms = {1, 3, 4};
    int target_weight = 8;
    int result = minMushrooms(mushrooms, target_weight);

    if (result != -1) {
        cout << "Minimum number of mushrooms needed: " << result << endl;
    } else {
        cout << "It is impossible to reach that weight" << endl;
    }
    return 0;
}
