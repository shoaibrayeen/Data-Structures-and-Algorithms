//
//  code_3.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#define d 256

bool search(string text , string pattern) {
    long M = pattern.length();
    long N = text.length();
    bool flag = false;
    int q = 29; // Any PRIME Number according to pattern value
    int j;
    int pattern_hash = 0;
    int text_hash = 0;
    int h = 1;
    for (int i = 0; i < M-1; i++) {
        h = (h*d)%q;
    }
    //calculating hash value for pattern and text
    for (int i = 0; i < M; i++) {
        pattern_hash = (d*pattern_hash + pattern[i])%q;
        text_hash = (d*text_hash + text[i])%q;
    }
    
    for (int i = 0; i <= N - M; i++) {
        if ( pattern_hash == text_hash ) {
            for (j = 0; j < M; j++) {
                if (text[i+j] != pattern[j])
                    break;
            }
            if (j == M) {
                cout << "Pattern found at index\t:\t" << i << "\n";
                flag = true;
            }
        }
        // calculating hash value for text
        if ( i < N-M ) {
            text_hash = (d*(text_hash - text[i]*h) + text[i+M])%q;
            if (text_hash < 0) {
                text_hash = (text_hash + q);
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
