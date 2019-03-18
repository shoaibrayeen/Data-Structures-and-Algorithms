//
//  code_3.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

long long int countAllBalancedBinaryTree(int height) {
    long long int DP[3];
    DP[0] = DP[1] = 1;
    for (int i = 2; i <= height; i++ ) {
        DP[2] = DP[1] * (2*DP[0] + DP[1]);
        DP[0] = DP[1];
        DP[1] = DP[2];
    }
    
    return DP[1];
    
}

int main() {
    int height;
    cout << "\nEnter Height\t:\t";
    cin >> height;
    cout << "\nTotal Balanced Binary Tree at Height " << height << "\t:\t " << countAllBalancedBinaryTree(height) << "\n";
    return 0;
}

