//
// Created by Dani on 2024. 04. 15..
//

#include "../header/functions.h"



void reszHalmazKiiro(int *array, int n){
    int v[] = {2,3,6,7};
    for (int i = 0; i < n; ++i) {
        if (array[i] != 0){
            for (int j = 0; j < array[i]; ++j) {
            cout << v[i] << " ";
            }
        }
    }
        cout << endl;

}


void reszHalmaz(int *array, int n, int k) {
    for (array[k] = 0; array[k] <= 1; array[k]++ )  {
        if(igeretesBasic(array,k,n)){
            if (k < n - 1){
                reszHalmaz(array, n, k + 1);
            }
            else{
                reszHalmazKiiro(array, n);
            }
        }
    }
}

bool igeretesBasic(int *array, int k, int n) {
    int v[] = {2, 3, 6, 7};
    int s = 0;
    if (k == n - 1) {
        for (int i = 0; i <= k; ++i) {
            if (array[i] == 1) {
                s = s +  v[i];
            }
        }
        if (s != 7) {
            return false;
        }
    }
    return true;
}
