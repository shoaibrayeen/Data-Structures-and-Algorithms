//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;



long countWays(int n, int k) {
    long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    int mod = 1000000007;
    dp[1] = k;
    long same = 0, diff = k;
    for (int i = 2; i <= n; i++) {
        same = diff;
        diff = dp[i-1] * (k-1);
        diff = diff % mod;
        dp[i] = (same + diff) % mod;
    }
    return dp[n];
}

int main() {
    int n;
    cout << "\nEnter N\t:\t";
    cin >> n;
    int k;
    cout << "\nEnter K\t:\t";
    cin >> k;
    cout << "\nNumber of Ways\t:\t" << countWays(n,k) << endl;
    return 0;
}
