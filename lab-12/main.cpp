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


    ifstream infile("be.txt");
    if (!infile) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    int  director;
    infile >> n >> director;

    int boss[MAXN] = {0};
    int employee, manager;
    while (infile >> employee >> manager) {
        boss[employee] = manager;
    }

    int x;
    cout << "Enter the number of hours (x): ";
    cin >> x;

    findEmployeesWithinXHours(n, director, boss, x);

    return 0;
}

