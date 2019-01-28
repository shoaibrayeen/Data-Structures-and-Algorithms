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

struct DP {
    bool value;
    char ch;
};

bool isMatch(string str, string pattern) {
    int n = int(str.length());
    int m = int(pattern.length());
    if (m == 0) {
        return (n == 0);
    }
    if (pattern[0] == '+') {
        return false;
    }
    DP lookup[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            lookup[i][j].value = false;
            lookup[i][j].ch = ' ';
        }
    }
    lookup[0][0].value = true;
    for (int j = 1; j <= n; j++) {
        if (pattern[j - 1] == '*') {
            lookup[j][0].value =
            lookup[j - 1][0].value;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (pattern[i - 1] == '*') {
                lookup[i][j].value = lookup[i][j - 1].value || lookup[i - 1][j].value;
                lookup[i][j].ch = str[j - 1];
            }
            else if (pattern[i - 1] == '?') {
                lookup[i][j].value = lookup[i - 1][j - 1].value;
                lookup[i][j].ch = str[j - 1];
            }
            else if (str[j - 1] == pattern[i - 1]) {
                lookup[i][j].value = lookup[i - 1][j - 1].value;
            }
            else if (pattern[i - 1] == '+') {
                if (pattern[i - 2] != '+' || pattern[i - 2] != '*' || pattern[i - 2] != '?')
                    if (pattern[i - 2] == str[j - 1]) {
                        lookup[i][j].value = lookup[i - 1][j - 1].value;
                        lookup[i][j].ch = str[j - 1];
                    }
                    else if (str[j-1] == lookup[i-1][j-1].ch) {
                        lookup[i][j].value = lookup[i - 1][j - 1].value;
                        lookup[i][j].ch = lookup[i - 1][j - 1].ch;
                    }
                    else {
                        lookup[i][j].value = false;
                    }
            }
        }
    }
    
    return lookup[m][n].value;
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
