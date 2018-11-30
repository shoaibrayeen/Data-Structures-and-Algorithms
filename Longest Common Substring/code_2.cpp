//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int lcs(string s1 , string s2) {
    long m = s1.length();
    long n = s2.length();
    int table[m+1][n+1];
    int result = 0;
    for (int i = 0; i <= m; i++ ) {
        for (int j = 0; j <= n; j++ ) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            }
            
            else if ( s1[i-1] == s2[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
                result = max(result, table[i][j]);
            }
            else {
                table[i][j] = 0;
            }
        }
    }
    return result;
}

int main() {
    string s1 , s2;
    cout << "\n1st String\t:\t";
    cin >> s1;
    cout << "\n2nd String\t:\t";
    cin >> s2;
    cout << "\nLength of substring\t:\t " << lcs( s1, s2 ) << "\n";
    
    return 0;
}
