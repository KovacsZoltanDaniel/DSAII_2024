//
// Created by Dani on 2024. 04. 29..
//


#include "dinamikus.h"

int minCoins(int S, int n, vector<int>& w) {
    vector<int> c(S + 1, VEGTELEN);
    c[0] = 0;
    for (int i = 1; i <= S; ++i) {
        for (int k = 0; k < n; ++k) {
            if (i - w[k] >= 0 && c[i - w[k]] + 1 < c[i]) {
                c[i] = c[i - w[k]] + 1;
            }
        }
    }
    return c[S];
}

void printMatrix(int **c, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}

int minimum(int x, int y){
    return (x < y ? x : y);
}

int maximum(int x, int y){
    return (x > y ? x : y);
}

void readArray(const char * filename, int * n, int ** a){
    FILE * fin = fopen(filename, "rt");
    if(!fin){
        exit(1);
    }

    fscanf(fin, "%d", n);
    *a = (int*)malloc(*n * sizeof(int));

    for(int i = 0; i < *n; i++){
        fscanf(fin, "%d", &((*a)[i]));
    }

    fclose(fin);
}

void backwards(int **c, int n, int * a, int result){
    int i = 0, j = n - 1;

    while(i != j + 1){
        int sum = c[i][j];
        int maxi = maximum(a[i], a[j]);

        sum -= maxi;

        if(c[i][j - 2] == sum){
            printf("%d ", maxi);
            j -= 2;
        }
        else if(c[i + 1][j - 1] == sum){
            printf("%d ", maxi);
            i += 1;
            j -= 1;
        }
        else if(c[i + 2][j] == sum){
            printf("%d ", maxi);
            i += 2;
        }
        else{
            sum += maxi;
            int mini = minimum(a[i], a[j]);
            printf("%d ", mini);
            sum -= mini;

            if(c[i][j - 2] == sum){
                j -= 2;
            }
            else if(c[i + 1][j - 1] == sum){
                i += 1;
                j -= 1;
            }
            else if(c[i + 2][j] == sum){
                i += 2;
            }
        }

    }
}

void printFlowers(int ** e, int ** c, int i, int j){
    if(i > 0 && j > i){
        if(c[i][j] == c[i - 1][j - 1] + e[i - 1][j - 1]){
            printFlowers(e, c, i - 1, j - 1);
            printf("The %dth flower is in the %dth vase.\n", i, j);
        } else {
            printFlowers(e, c, i, j - 1);
            printf("The %dth vase is empty.\n", j);
        }
    } else {
        if(i == 0 && j > 0){
            printFlowers(e, c, i, j - 1);
            printf("The %dth vase is empty.\n", j);
        } else if (i > 0 && i == j){
            printFlowers(e, c, i - 1, j - 1);
            printf("The %dth flower is in the %dth vase.\n", i, j);
        }
    }
}

void createAestheticImpact(int ** e, int ** c, int n, int m){
    c = (int**)malloc((n + 1) * sizeof(int*));

    for(int i = 0; i <= n; i++){
        c[i] = (int*)calloc(m + 1, sizeof(int));
    }

    for(int i = 1; i <= n; i++){
        c[i][i] = c[i - 1][i - 1] + e[i - 1][i - 1];
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= m - n + i; j++){
            if(c[i - 1][j - 1] + e[i - 1][j - 1] > c[i][j - 1]){
                c[i][j] = c[i - 1][j - 1] + e[i - 1][j - 1];
            } else {
                c[i][j] = c[i][j - 1];
            }
        }
    }
}


void readFlowerFile(const char * filename, int ***e, int *n, int *m){
    FILE * fin = fopen(filename, "rt");
    if(!fin){
        exit(5);
    }

    fscanf(fin, "%d%d", n, m);

    *e = (int**)calloc(*n, sizeof(int*));

    for(int i = 0; i < *n; i++){
        (*e)[i] = (int*)calloc(*m , sizeof(int));
        for(int j = 0; j < *m; j++){
            fscanf(fin, "%d", &((*e)[i][j]));
        }
    }

    fclose(fin);
}

