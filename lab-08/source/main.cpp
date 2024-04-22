#include <iostream>
#include "../header/functions.h"
using namespace std;
#include <fstream>



int main() {
    ifstream inputFile("input.txt");
    if(!inputFile){
        cout << "Hiba fajl megnyitaskor!" << endl;
        return 1;
    }
    int target;
    inputFile >> target;
    int n = 4;
    int *array = new int[n];
    int counter = 0;
    int num;
    vector<int> candidates;
    while (inputFile >> num) {
        candidates.push_back(num);
        array[counter] = num;
        counter++;
    }
    cout << "Bemeneti adatok: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Target: " << target << endl;

    reszHalmaz(array,n,0);





    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Kimenet: ";
    for (const auto& combination : result) {
        cout << "[";
        for (int i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1)
                cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    cout << "****************************************" << endl;
    ifstream input("exams.txt");

    input >> n;

    vector<Exam> exams(n);
    for (int i = 0; i < n; ++i) {
        input >> exams[i].name >> exams[i].score >> exams[i].duration;
    }

    float start, end;
    input >> start >> end;
    input.close();

    float time = end - start;


    sort(exams.begin(), exams.end(), sortByScore);


    vector<bool> selected(n, false);

    int pontok = 0;
    float totalTime = 0;
    for (int i = 0; i < n; ++i) {
        if (totalTime + exams[i].duration <= time && !selected[i]) {
            selected[i] = true;
            totalTime += exams[i].duration;
            pontok += exams[i].score;
        }
    }


    for (int i = 0; i < n; ++i) {
        if (selected[i]) {
            cout << i + 1 << " ";
        }
    }

    if (pontok >= 150) {
        cout << "IGEN";
    } else {
        cout << "NEM";
    }

    return 0;
}