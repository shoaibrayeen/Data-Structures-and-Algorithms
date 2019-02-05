//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;


long long getStepptingNumber(int n) {
    int dp[n + 1][10];
    if (n == 1) {
        return 10;
    }
    for (int j = 0; j <= 9; j++) {
        dp[1][j] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1];
            }
            else if (j == 9) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
        }
    }
    long long sum = 0;
    for (int j = 1; j <= 9; j++) {
        sum += dp[n][j];
    }
    return sum;
}

int main() {
    int n;
    cout << "\nEnter Number\t:\t";
    cin >> n;
    cout << "\nNumber of Stepping Numbers\t:\t" << getStepptingNumber(n) << "\n";
    return 0;
}
