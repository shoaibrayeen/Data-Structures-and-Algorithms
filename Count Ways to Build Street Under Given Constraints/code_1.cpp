//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

long countAllWays(int n) {
    long dp[2][n + 1];
    dp[0][1] = 1;
    dp[1][1] = 2;
    for (int i = 2; i <= n; i++) {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
        dp[1][i] = dp[0][i - 1] * 2 + dp[1][i - 1];
    }
    return dp[0][n] + dp[1][n];
}

int main() {
    int n;
    cout << "\nEnter Number\t:\t";
    cin >> n;
    cout << "\nTotal Number of Ways\t:\t " << countAllWays(n) << "\n";
    return 0;
}

