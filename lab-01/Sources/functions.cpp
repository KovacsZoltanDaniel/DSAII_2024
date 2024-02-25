//
// Created by Dani on 2024. 02. 19..
//

#include "../Headers/functions.h"
#include "iostream"
using namespace std;
#include <fstream>


void read(int *&array, int &n, ifstream &f) {
    if(!f){
        cout << "File not found" << endl;
        return;
    }
    f >> n;
    array = new int[n];
    for (int i = 0; i < n; ++i) {
        f >> array[i];
    }
}

void print_array(int *a, int n) {
    cout << "A tomb elemei: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int linearSearch(int *array, int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const int *array, int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (array[middle] == target) {
            return middle;
        }
        if (array[middle] < target) {
            left = middle + 1;
        }
        if (array[middle] > target) {
            right = middle - 1;
        }
    }
    return -1;
}

int lnko(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lkkt(int a, int b) {
    return (a * b) / lnko(a, b);
}

int power(int b, int e) {
    int sum = 1;
    for (int i = 0; i < e; ++i) {
        sum *= b;
    }
    return sum;
}

void selection_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(a[min_index],a[i]);
        }
    }
}

void minimselection_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max_index]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            swap(a[i],a[max_index]);
        }
    }
}

void bubble_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j],a[j+1]);
            }
        }
    }
}
