#include <iostream>
#include <vector>
using namespace std;

#include "dinamikus.h"

int main() {
    int S = 11; // Az összeg, amit ki kell fizetni
    int n = 3;
    vector<int> w = {2, 3, 5}; // Az érmék értékei

    cout << minCoins(S, n, w) << endl;

    int *a;
    readArray("baratsagos.txt", &n, &a);

    int **c = (int **) malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        c[i] = (int *) calloc(n, sizeof(int));
    }

    for (int i = 0; i < n - 1; i++) {
        c[i][i + 1] = maximum(a[i], a[i + 1]);
    }
    c[n - 1][n - 1] = a[n - 1];

    for (int k = 3; k < n; k += 2) {
        for (int i = 0, j = i + k; j < n; i++, j++) {
            c[i][j] = maximum(a[i] + minimum(c[i + 1][j - 1], c[i + 2][j]),
                              a[j] + minimum(c[i + 1][j - 1], c[i][j - 2]));
        }
    }

    printf("result: %d\n", c[0][n - 1]);
    backwards(c, n, a, c[0][n - 1]);
    printf("\n");

    int **e, m;

    readFlowerFile("flowershop.txt", &e, &n, &m);

    createAestheticImpact(e, c, n, m);

    printf("Aesthetic impact: %d\n", c[n][m]);
    printFlowers(e, c, n, m);
    return 0;
}
