//
// Created by Dani on 2024. 05. 13..
//

#include "gyak12.h"
void maxUgras(vector<vector<int>>& matrix) {
    int sum = 0;

    if(matrix[0][matrix[0].size()-1] > matrix[1][matrix[0].size()-1]){
        sum += matrix[0][matrix[0].size()-1];
    }
    else{
        sum += matrix[1][matrix[0].size()-1];
    }

    int oszlop = matrix[0].size() -2 ;

    while (oszlop > 0) {
        int maxErtek = 0;

        if(matrix[0][oszlop] <0 && matrix[1][oszlop] < 0){
            oszlop --;
        }
        for (int sor = 0; sor <= 1; sor++) {

            maxErtek = max(maxErtek, matrix[sor][oszlop]);
        }
        sum += maxErtek;
        oszlop -= 1;
    }


    if(matrix[0][0] > matrix[1][0]){
        sum += matrix[0][0];
    }
    else{
        sum += matrix[1][0];
    }

    cout<< sum << endl;
}

void findEmployeesWithinXHours(int n, int director, int boss[], int x) {
    int distance[MAXN];

    for (int i = 1; i <= n; ++i) {
        int current = i;
        int dist = 0;

        while (current != director && boss[current] != 0) {
            current = boss[current];
            dist++;
        }

        if (current == director) {
            distance[i] = dist;
        } else {
            distance[i] = -1;
        }
    }


    for (int i = 1; i <= n; ++i) {
        if (distance[i] != -1 && distance[i] <= x) {
            cout << i << endl;
        }
    }
}