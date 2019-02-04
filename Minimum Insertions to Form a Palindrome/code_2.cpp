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

int getLengthOfMinInsertions(string str) {
    int n = int(str.length());
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0 , k = i; k < n; ++j , ++k ) {
            dp[j][k] = (str[j] == str[k])? dp[j+1][k-1] : ( min( dp[j][k-1], dp[j+1][k] ) + 1 );
        }
    }
    return dp[0][n-1];
}

int main() {
    string str;
    cout << "\nEnter String\t:\t";
    cin >> str;
    cout << "\nMinimum Insertions to form Palindrome\t:\t" << getLengthOfMinInsertions(str) << "\n";
    return 0;
}
