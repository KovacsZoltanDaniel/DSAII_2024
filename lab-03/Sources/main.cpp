#include "../Headers/DivideAndImpera.h"

int main() {
    int n;
    int *array;
    ifstream f("input.txt");
    Read(array, n, f);
    Print(array, n);
    mergesort(array, 0, n - 1);
    Print(array, n);
    cout << "Maximum: " << array[maximum(array, 0, n - 1)] << endl;
    return 0;
}
