//
//  code_3.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int countAllWays(int n) {
    int DP[4];
    DP[0] = DP[1] = 1;
    DP[2] = 2;
    for (int i = 3; i <= n; i++) {
        DP[3] = DP[2] + DP[1] + DP[0];
        DP[0] = DP[1];
        DP[1] = DP[2];
        DP[2] = DP[3];
    }
    return DP[3];
}

int main() {
    int n;
    cout << "\nEnter Number\t:\t";
    cin >> n;
    cout << "\nTotal Number of Ways\t:\t " << countAllWays(n) << "\n";
    return 0;
}

