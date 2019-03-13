//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int countAllWays(int n) {
    int DP[5];
    DP[0] = DP[1] = DP[2] = 1;
    DP[3] = 2;
    for (int i = 4; i <= n; i++) {
        DP[4] = DP[3] + DP[1] + DP[0];
        DP[0] = DP[1];
        DP[1] = DP[2];
        DP[2] = DP[3];
        DP[3] = DP[4];
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

