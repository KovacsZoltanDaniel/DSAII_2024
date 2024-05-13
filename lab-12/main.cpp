#include "gyak12.h"



int main() {
    ifstream input("input.txt");
    if (!input) {
        cerr << "Unable to open input file";
        return 1;
    }

    int n;
    input >> n;
    vector<vector<int>> matrix(2, vector<int>(n));


    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            input >> matrix[i][j];
        }
    }
    input.close();

    cout << "A moho beka osszgyujtemenye: ";
    maxUgras(matrix);

    return 0;
}

