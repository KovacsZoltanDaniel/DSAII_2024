#include "../Headers/functions.h"
#include "fstream"
using namespace std;


int main() {
    const char *filename = "adatok.txt";
    ifstream f(filename);
    int *array;
    int n,result;
    read(array, n, f);
    print_array(array, n);
    cout << "*****************************************************" << endl;
    result = linearSearch(array,n,8);
    if (result != -1) {
        cout << "Linear Search for target " << 8 << " found at Index: " << result << endl;
    } else {
        cout << "Linear Search for target " << 8 << " not found" << endl;
    }
    cout << "*****************************************************" << endl;
    cout << "LNKO: " << lnko(array[2],array[4]) << endl;
    cout << "LKKT: " << lkkt(array[2],array[6]) << endl;
    cout << "*****************************************************" << endl;
    result = power(array[3],5);
    cout << "Power: " << result << endl;
    cout << "*****************************************************" << endl;
    //cout << "Selection sort:" << endl;
    //selection_sort(array,n);
    //cout << "Minimselection sort:" << endl;
    //minimselection_sort(array,n);
    cout << "Bubble sort:" << endl;
    bubble_sort(array,n);
    print_array(array,n);
    cout << "*****************************************************" << endl;
    result = binarySearch(array,n,7);
    if (result != -1) {
        cout << "Binary Search for target " << 7 << " found! at Index: " << result << endl;
    } else {
        cout << "Binary Search for target " << 7 << " not found" << endl;
    }
    return 0;
}
