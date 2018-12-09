//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool search(string text , string pattern) {
    long M = pattern.length();
    long N = text.length();
    bool flag = false;
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        
        if (j == M) {
            cout << "Pattern found at index\t:\t" << i << "\n";
            flag = true;
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
