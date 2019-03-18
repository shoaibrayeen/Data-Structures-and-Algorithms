//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

long long int countAllBalancedBinaryTree(int height) {
    long long int DP[height+1];
    DP[0] = DP[1] = 1;
    for (int i = 2; i <= height; i++ ) {
        DP[i] = DP[i-1] * (2*DP[i-2] + DP[i-1]);
    }
    
    return DP[height];
    
}

int main() {
    int height;
    cout << "\nEnter Height\t:\t";
    cin >> height;
    cout << "\nTotal Balanced Binary Tree at Height - " << height << "\t:\t " << countAllBalancedBinaryTree(height) << "\n";
    return 0;
}

