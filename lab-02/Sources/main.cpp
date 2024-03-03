#include <iostream>
#include "../Headers/functionsRec.h"

int main() {
    int *array;
    int n;
    ifstream f("input.txt");
    f >> n;
    array = new int[n];
    readArrayRec(array, n, f);
    cout << "A tomb elemei:" << endl;
    printArrayRec(array, n);
    cout << endl;
    cout << sumArrayRec(array, n) << endl;
    cout << maxArrayRec(array, n, array[0]) << endl;
    cout << lnkoRec(8,12) << endl;
    cout << lkktRec(18,35,18,35) << endl;
    cout << powerRec(2,3) << endl;
    cout << lnkoArrayRec(array,n) << endl;
    digitNumbersRec(198);
    cout << endl;
    cout << inverseNumber(5,7) << endl;

    //teszt
    cout << "*************************" << endl;
    cout << "Teszt:" << endl;
    int a = 2;
    int b = 3;
    int result1 = teszt1(a,b);
    int result2 = teszt1(b,a);
    if (result1 == result2){
        cout << "A ket szam egyenlo!" << endl;
    }
    else if(result1 > result2){
        cout << result1 << " nagyobb, mint " << result2 << endl;
    }
    else{
        cout << result2 << " nagyobb, mint " << result1 << endl;
    }
    return 0;
}
