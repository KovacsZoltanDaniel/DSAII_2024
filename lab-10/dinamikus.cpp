//
// Created by Dani on 2024. 04. 29..
//


#include "dinamikus.h"


void erme(int S, int n, int *w) {
    int *c = new int[S+1];
    c[0] = 0;
    for ( int i = 1 ; i <= S ; ++i ){
        c[i] = VEGTELEN - 1;
        for ( int k = 0 ; k < n ; ++k ){
            if ( i-w[k] >= 0 && c[i-w[k]] + 1 < c[i] ){
                c[i] = c[i-w[k]] + 1;
            }
        }
    }

    for(int i = 0; i <= S; i++)
        cout << i << " : " << c[i] << endl;

    delete[] c;
}

void baratsagos(vector<int> a) {
    int n = a.size();
    if (n == 0) {
        cout << "A bemeneti vektor üres, nincs mit feldolgozni." << endl;
        return;
    }

    int c[n][n];
    // Először inicializáljuk a táblát nullákkal
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            c[i][j] = 0;
        }
    }

    for(int k = 0; k < n; ++k) {
        for(int i = 0, j = k; j < n; ++i, ++j) {
            int x = ((i + 2) <= j) ? c[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? c[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? c[i][j - 2] : 0;
            c[i][j] = max(a[i] + min(x, y), a[j] + min(y, z));
        }
    }

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; ++j) {
            cout << setw(3) << c[i][j] << " ";
        }
        cout << endl;
    }

    cout << "eredmeny: " << c[0][n - 1] << endl;
}

vector<vector<int>> haromszogBeolvas(const string& filename) {
    ifstream f(filename);
    if(!f)
        exit(-2);
    int n;
    f >> n;

    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            f >> a[i][j];
        }
    }
    return a;
}

void haromszogKiir(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void haromszogOptimalizalas(const vector<vector<int>>& a) {
    vector<vector<int>>c(a.size(), vector<int>(a.size()));

    for (int i = 0; i < a.size(); ++i) {
        c[c.size() - 1][i] = a[a.size() - 1][i];
    }

    for (int i = a.size() - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            c[i][j] = max(a[i][j] + c[i+1][j], a[i][j] + c[i+1][j+1]);
        }
    }
    haromszogKiir(c);
}

int esztetika(vector<vector<int>>& e, int n, int m) {
    vector<vector<int>> c(n + 1, vector<int>(m + 1));
//    int c[n+1][m+1];
    for (int j = 0; j <= m - n; ++j) {
        c[0][j] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        c[i][i] = c[i - 1][i - 1] + e[i][i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= m - n + i; ++j) {
            if (c[i - 1][j - 1] + e[i][j] > c[i][j - 1]) {
                c[i][j] = c[i - 1][j - 1] + e[i][j];
            } else {
                c[i][j] = c[i][j - 1];
            }
        }
    }
    return c[n][m];
}

vector<vector<int>> matrixBeolvas(string filename) {
    ifstream f(filename);
    if(!f)
        exit(-2);
    int n, m;
    f >> n;
    f >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            f >> a[i][j];
        }
    }
    return a;
}

void matrixKiir(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[0].size(); ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}