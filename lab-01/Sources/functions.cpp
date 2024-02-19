//
// Created by Dani on 2024. 02. 19..
//

#include "../Headers/functions.h"
#include "iostream"
#include "fstream"


void read(int *&array, int &n, ifstream &f) {
    if(!f){
        cout << "File not found" << endl;
    }
    f >> n;
    array = new int[n];
    for (int i = 0; i < n; ++i) {
        f >> array[i];
    }

}

void print_array(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}

int linearSearch(int *array, int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {
            return i;
        }
    }
    return 0;
}

int binarySearch(const int *array, int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (array[middle] == target) {
            return middle;
        }
    }
    return 0;
}

int lnko(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        }
    }
    return 0;
}

int lkkt(int a, int b) {

    return 0;
}
