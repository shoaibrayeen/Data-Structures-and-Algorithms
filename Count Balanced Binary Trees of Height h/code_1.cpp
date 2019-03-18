//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
using namespace std;

int countAllBalancedBinaryTree(int height) {
    if ( height == 0 || height == 1) {
        return 1;
    }
    return countAllBalancedBinaryTree(height-1) * (2 * countAllBalancedBinaryTree(height-2) + countAllBalancedBinaryTree(height-1));
    
}

int main() {
    int height;
    cout << "\nEnter Height\t:\t";
    cin >> height;
    cout << "\nTotal Balanced Binary Tree at Height" << height << "\t:\t " << countAllBalancedBinaryTree(height) << "\n";
    return 0;
}

