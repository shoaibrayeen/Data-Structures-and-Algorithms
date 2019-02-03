//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <string>

using namespace std;

bool isMatch(string txt, string pat) {
    int n = int(txt.length());
    int m = int(pat.length());
    if (m == 0) {
        return (n == 0);
    }
    int i = 0, j = 0, index_txt = -1,
    index_pat = -1;
    
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }
        else if (j < m && pat[j] == '?') {
            i++;
            j++;
        }
        else if (j < m && pat[j] == '*') {
            index_txt = i;
            index_pat = j;
            j++;
        }
        else if (index_pat != -1) {
            j = index_pat + 1;
            i = index_txt + 1;
            index_txt++;
        }
        else {
            return false;
        }
    }
    while (j < m && pat[j] == '*') {
        j++;
    }
    if (j == m) {
        return true;
    }
    
    return false;

}

int main() {
    string str;
    string pattern;
    cout << "\nEnter Text\t:\t";
    cin >> str;
    cout << "\nEnter Pattern\t:\t";
    cin >> pattern;
    if( isMatch(str, pattern)) {
        cout << "\nPattern Matches\n";
    }
    else {
        cout << "\nPattern does not Match\n";
    }
    return 0;
}
