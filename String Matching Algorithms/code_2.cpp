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

// calculating Longest prefix AND suffix
void computeLPSArray(string pattern, int* lps) {
    long M = pattern.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}


bool search(string text , string pattern) {
    long M = pattern.length();
    long N = text.length();
    bool flag = false;
    int lps[M];   // for longest prefix and suffix
    computeLPSArray(pattern, lps);
    
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        
        if (j == M) {
            cout << "Pattern found at index\t:\t" << i-j << "\n";
            j = lps[j - 1];
            flag = true;
        }
        else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return flag;
}

int main() {
    string text , pattern;
    cout << "\nEnter Text\t\t\t\t:\t";
    getline(cin , text);
    cout << "\nEnter Pattern\t\t\t:\t";
    getline(cin , pattern);
    cout << endl;
    if ( !search(text ,pattern) ) {
        cout << "\nPattern Not Found\n";
    }
    cout << endl;
    return 0;
}
