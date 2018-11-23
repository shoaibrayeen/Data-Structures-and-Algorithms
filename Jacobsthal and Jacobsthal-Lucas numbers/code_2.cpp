//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;
int Jacobsthal(int n) {
    int dp[3];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[2] = dp[1] + 2 * dp[0];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[1];
}

int Jacobsthal_Lucas(int n) {
    int dp[3];
    dp[0] = 2;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[2] = dp[1] + 2 * dp[0];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[1];
}

int main() {
    int n;
    cout << "\nEnter n\t:\t";
    cin >> n;
    cout << "\nJacobsthal number\t:\t" << Jacobsthal(n) << endl;
    cout << "\nJacobsthal-Lucas number\t:\t" << Jacobsthal_Lucas(n) << endl;
    return 0;
}
