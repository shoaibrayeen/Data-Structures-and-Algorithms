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

bool isMatch(string str, string pattern) {
    int n = int(str.length());
    int m = int(pattern.length());
    if (m == 0) {
        return (n == 0);
    }
    bool lookup[n + 1][m + 1];
    memset(lookup, false, sizeof(lookup));
    lookup[0][0] = true;
    
    for (int j = 1; j <= m; j++) {
        if (pattern[j - 1] == '*') {
            lookup[0][j] = lookup[0][j - 1];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pattern[j - 1] == '*') {
                lookup[i][j] = lookup[i][j - 1] ||lookup[i - 1][j];
            }
            else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1];
            }
            else {
                lookup[i][j] = false;
            }
        }
    }
    return lookup[n][m];
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
