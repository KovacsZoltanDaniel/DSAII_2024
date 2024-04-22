//
// Created by Dani on 2024. 04. 22..
//

#ifndef LAB_09_GYAK9_H
#define LAB_09_GYAK9_H
#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getDataFromFile(vector<string> &color, int &n, const string &fileName);
void kiir(const vector<string> &zaszlo);
void zaszloGeneralo(const vector<string> &szinek, vector<string> &zaszlo, int n, int m, int index);

bool isPalindrom(const std::string& text);
bool isPalindromeHelper(const std::string& text, int left, int right);
bool isEqual(char a, char b);
bool myisAlpha(char c);
#endif //LAB_09_GYAK9_H
