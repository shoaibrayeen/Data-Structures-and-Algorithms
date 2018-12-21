//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

void printGolomb(int n) {
    cout << "\nGolomb Sequence\t:\t";
    int dp[n + 1];
    dp[1] = 1;
    cout << dp[1] << " ";
    for (int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i - dp[dp[i - 1]]];
        cout << dp[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "\nEnter N\t\t\t:\t";
    cin >> n;
    printGolomb(n);
    return 0;
}
