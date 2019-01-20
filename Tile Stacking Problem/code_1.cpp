//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
#include <vector>
using namespace std;


int possibleWays(int n, int m, int k) {
    int dp[m+1][n+1];
    int presum[m+1][n+1];
    memset(dp, 0, sizeof dp);
    memset(presum, 0, sizeof presum);
    for (int i = 1; i < n + 1; i++) {
        dp[0][i] = 0;
        presum[0][i] = 1;
    }
    for (int i = 0; i < m + 1; i++) {
        presum[i][0] = dp[i][0] = 1;
    }
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            dp[i][j] = presum[i - 1][j];
            if (j > k) {
                dp[i][j] -= presum[i - 1][j - k - 1];
            }
        }
        for (int j = 1; j < n + 1; j++) {
            presum[i][j] = dp[i][j] + presum[i][j - 1];
        }
    }
    
    return dp[m][n];
}

int main() {
    int n;
    cout << "\nEnter n\t:\t";
    cin >> n;
    int m;
    cout << "\nEnter m\t:\t";
    cin >> m;
    int k;
    cout << "\nEnter k\t:\t";
    cin >> k;
    cout << "\nNumber of ways\t:\t" << possibleWays(n, m, k);
    cout <<  endl;
    return 0;
}
