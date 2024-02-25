
#include "../Headers/functions.h"
#include "fstream"
using namespace std;


int main() {
    const char *filename = "adatok.txt";
    ifstream f(filename);
    const char *filename2 = "rendezett.txt";
    ifstream f2(filename2);
    int *array,*array2;
    int n,m;
    read(array, n, f);
    read(array2, m, f2);
    print_array(array, n);
    print_array(array2, m);
    cout << "*****************************************************" << endl;
    int result = linearSearch(array,n,8);
    if (result != -1) {
        cout << "Linear Search for target " << 8 << " found at Index: " << result << endl;
    } else {
        cout << "Linear Search for target " << 8 << " not found" << endl;
    }
    cout << "*****************************************************" << endl;
    result = binarySearch(array2,m,7);
    if (result != -1) {
        cout << "Binary Search for target " << 7 << " found! at Index: " << result << endl;
    } else {
        cout << "Binary Search for target " << 7 << " not found" << endl;
    }
    return 0;
}
