//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

int lcs(string X , string Y) {
    int m = int(X.length());
    int n = int(Y.length());
    int result = 0;
    int table[2][n];
    int k = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                table[k][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1]) {
                table[k][j] = table[1 - k][j - 1] + 1;
                result = max(result, table[k][j]);
            }
            else {
                table[k][j] = 0;
            }
        }
        k = 1 - k;
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

