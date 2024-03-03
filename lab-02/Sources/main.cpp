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
    cout << "Osszeg: " << sumArrayRec(array, n) << endl;
    cout << "Maximum: " << maxArrayRec(array, n, array[0]) << endl;
    cout << "Lnko tomb: " << lnkoArrayRec(array,n) << endl;
    cout << "Sima lnko: " << lnkoRec(8,12) << endl;
    cout << "Lkkt: " << lkktRec(8,16,8,16) << endl;
    cout << "Hatvany: " << powerRec(2,3) << endl;
    cout << "Szamjegyei a 198-nak: " ;
    digitNumbersRec(198);
    cout << endl;
    cout << "Inverz: " << inverseNumber(5,7) << endl;

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
