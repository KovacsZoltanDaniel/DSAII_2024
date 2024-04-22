#include "gyak9.h"

int main(){
    vector<string>colors;
    int n;
    getDataFromFile(colors,n,"colors.txt");

    for(auto szin:colors){
        cout << szin << endl;
    }
    int m = 3;
    if (m % 2 == 0) m--;

    vector<string> zaszlo(m);

    zaszloGeneralo(colors, zaszlo, n, m, 0);
    cout << "**********************************************" << endl;
    string text = "A jos icipici soja!98734";
    if (isPalindrom(text)) {
        cout << "The text '" << text << "' is a palindrome." << endl;
    } else {
        cout << "The text '" << text << "' is not a palindrome." << endl;
    }
    return 0;
}
