//
//  code_3.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 17/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include<iostream>
#include<string.h>
using namespace std;

int min(int x, int y, int z) {
    return min(min(x, y), z);
}

int editDist(string str1 , string str2) {
    int m  = int(str1.length());
    int n  = int(str2.length());
    int dp[2][n+1];
    for (int i = 0; i <= m; i++ ) {
        for (int j = 0; j <= n; j++ ) {
            if (i == 0) {
                dp[i % 2][j] = j;
            }
            else if (j == 0) {
                dp[i % 2][j] = i;
            }
            else if (str1[i-1] == str2[j-1]) {
                dp[i % 2][j] = dp[(i-1) % 2][j-1];
            }
            else {
                dp[i % 2][j] = 1 + min(dp[i%2][j-1], dp[(i-1) % 2][j], dp[(i-1) % 2][j-1]);
            }
        }
    }
    
    return dp[m % 2][n];
}

int main() {
    string s1 , s2;
    cout << "\n1st String\t:\t";
    cin >> s1;
    cout << "\n2nd String\t:\t";
    cin >> s2;
    cout << "\nEdit Distance\t:\t" << editDist( s1, s2 ) << endl;
    return 0;
}
