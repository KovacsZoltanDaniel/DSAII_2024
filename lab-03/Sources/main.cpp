#include "../Headers/DivideAndImpera.h"

int main() {
    int n;
    int *array;
    ifstream f("input.txt");
    Read(array, n, f);
    Print(array, n);

    return 0;
}
