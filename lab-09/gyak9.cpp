//
// Created by Dani on 2024. 04. 22..
//

#include <fstream>
#include "gyak9.h"

using namespace std;


void kiir(const vector<string> &zaszlo) {
    for (const auto &szin : zaszlo) {
        cout << szin << " ";
    }
    cout << endl;
}

void zaszloGeneralo(const vector<string> &szinek, vector<string> &zaszlo, int n, int m, int index) {
    if (index == m) {
        kiir(zaszlo);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (index == m / 2) {
            zaszlo[index] = "red";
            zaszloGeneralo(szinek, zaszlo, n, m, index + 1);
        } else if (find(zaszlo.begin(), zaszlo.begin() + index, szinek[i]) == zaszlo.begin() + index) {
            zaszlo[index] = szinek[i];
            zaszloGeneralo(szinek, zaszlo, n, m, index + 1);
        }
    }
}



bool myisAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ;
}

bool isEqual(char a, char b) {
    return tolower(a) == tolower(b);
}

bool isPalindromeHelper(const string& text, int left, int right) {
    if (left == right) {
        return true;
    }

    if (!myisAlpha(text[left])) {
        return isPalindromeHelper(text, left + 1, right);
    }

    if (!myisAlpha(text[right])) {
        return isPalindromeHelper(text, left, right - 1);
    }

    if (!isEqual(text[left], text[right])) {
        return false;
    }

    return isPalindromeHelper(text, left + 1, right - 1);
}

bool isPalindrom(const string& text) {
    return isPalindromeHelper(text, 0, text.length() - 1);
}

void getDataFromFile(vector<string> &color, int &n, const string &fileName) {
    ifstream input(fileName);

    if(!input){
        cout << "Error when openin file!" << endl;
        exit(-1) ;
    }

    input >> n;
    string word;

    while(input >> word){
        color.push_back(word);
    }

    input.close();
}
